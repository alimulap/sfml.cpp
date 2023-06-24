#include "tetris/state/play.hpp"

namespace State
{

Play::Play()
    : matrix(sf::Vector2f(0., 0.))
{
    this->automaticMoveClock.restart();

    this->controlled = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(0., 0.) * TILE_SIZE, TILE_SIZE);
    this->ghost = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(0., 0.) * TILE_SIZE, TILE_SIZE);
    this->updateGhost();
    this->ikan = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(3., 10.) * TILE_SIZE, TILE_SIZE);
    this->matrix.fillWithGeometile(std::move(this->ikan).value());
}

Play::~Play() { }

void Play::geometileController()
{
    //\> move down
    if (this->automaticMoveClock.getElapsedTime().asSeconds() > 1.f) 
    {
        this->automaticMoveClock.restart();
        this->moveControlled(Direction::Down);
        this->updateGhost();
    }

    this->moved = false;

    //\> move control
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        this->moved = true;
        if (this->moveAction == Direction::None)
        {
            this->moveAction = Direction::Right;
            this->moveClock.restart();
            this->moveControlled(Direction::Right);
            this->updateGhost();
        }
        if (this->moveAction == Direction::Right && this->moveClock.getElapsedTime().asSeconds() > 0.1f) {
            this->moveControlled(Direction::Right);
            this->updateGhost();
            this->moveClock.restart();
        }
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        this->moved = true;
        if (this->moveAction == Direction::None)
        {
            this->moveAction = Direction::Left;
            this->moveClock.restart();
            this->moveControlled(Direction::Left);
            this->updateGhost();
        }
        if (this->moveAction == Direction::Left && this->moveClock.getElapsedTime().asSeconds() > 0.1f) {
            this->moveControlled(Direction::Left);
            this->updateGhost();
            this->moveClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
    {
        this->moved = true;
        if (this->moveAction == Direction::None)
        {
            this->moveAction = Direction::Down;
            this->moveClock.restart();
            this->moveControlled(Direction::Down);
            this->updateGhost();
        }
        if (this->moveAction == Direction::Down && this->moveClock.getElapsedTime().asSeconds() > 0.1f) {
            this->moveControlled(Direction::Down);
            this->updateGhost();
            this->moveClock.restart();
        }
    }

    if (!this->moved) {
        this->moveClock.restart();
        this->moveAction = Direction::None; }

    //\> rotate
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (!this->rotated) {
            this->controlled.value()->rotate( 1);
            this->ghost.value()->rotate( 1);
            this->updateGhost();
            this->rotated = true;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        if (!this->rotated) {
            this->controlled.value()->rotate(-1);
            this->ghost.value()->rotate(-1);
            this->updateGhost();
            this->rotated = true;
        }
    } else {
        this->rotated = false;
    }
}

void Play::moveControlled(Direction dir)
{
    sf::Vector2f nextPos = 
        dir == Direction::Up ? this->controlled.value()->getPosition() + sf::Vector2f(0., -TILE_SIZE.y) :
        dir == Direction::Right ? this->controlled.value()->getPosition() + sf::Vector2f(TILE_SIZE.x, 0.) :
        dir == Direction::Left ? this->controlled.value()->getPosition() + sf::Vector2f(-TILE_SIZE.y, 0.) :
        dir == Direction::Down ? this->controlled.value()->getPosition() + sf::Vector2f(0., TILE_SIZE.y) : sf::Vector2f();

    if (this->matrix.isValidAndInBound(this->controlled.value(), nextPos)) 
        this->controlled.value()->setPosition(nextPos);
}

void Play::updateGhost()
{
    if (!this->controlled.has_value() || !this->controlled.has_value())
        return;
    sf::Vector2i posInMatrix = this->matrix.getGeometilePos(this->controlled.value());
    int tileIndex = posInMatrix.y * 10 + posInMatrix.x;
    std::array<sf::Vector2f, 4> geoTiles = this->controlled.value()->getOrigins();
    std::array<int, 4> tilesIndex{};
    for (int i = 0; i < 4; ++i)
        tilesIndex[i] = tileIndex + geoTiles[i].y * 10 + geoTiles[i].x;

    while (true) 
    {
        for (int i = 0; i < 4; ++i)
        {
            tilesIndex[i] += 10;
            if (!this->matrix.isValidAndInBound(tilesIndex[i])) {
                this->ghost.value()->setPosition(sf::Vector2f(tileIndex % 10, static_cast<int>(tileIndex / 10.)) * TILE_SIZE + this->matrix.getPosition());
                return;
            }
        }

        tileIndex += 10;
    }
    this->ghost.value()->setPosition(sf::Vector2f(tileIndex % 10, static_cast<int>(tileIndex / 10.)) * TILE_SIZE + this->matrix.getPosition());
}

std::optional<std::unique_ptr<State>> Play::getNextState() 
{
    if (this->nextState == std::nullopt)
        return std::nullopt;
    else
        return std::move(this->nextState); 
}

void Play::pollEvent()
{
}

void Play::update()
{
    this->geometileController();
}

void Play::render(const std::shared_ptr<sf::RenderTarget> &window)
{
    (this->controlled.has_value()) ? this->controlled.value()->render(window) : void();
    (this->ghost.has_value()) ? this->ghost.value()->render(window) : void();
    this->matrix.render(window);
}

}
