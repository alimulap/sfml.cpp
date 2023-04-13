#include "tetris/state/play.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "tetris/constants.hpp"
#include "tetris/entity/tile.hpp"
#include "util/operator_overload.hpp"

namespace State
{

Play::Play()
    : matrix(sf::Vector2f(60., 60.))
{
    this->clock.restart();

    this->controlled = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(2., 2.) * TILE_SIZE, TILE_SIZE);
    this->ghost = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(2., 7.) * TILE_SIZE, TILE_SIZE);
}

Play::~Play() { }

std::optional<std::unique_ptr<State>> Play::getNextState() 
{
    if (this->nextState == std::nullopt)
        return std::nullopt;
    else
        return std::move(this->nextState); 
}

void Play::pollEvent(const sf::Event& event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:
        break;
    default:
        break;
    }
}

void Play::update()
{
    if (this->clock.getElapsedTime().asSeconds() > 1.f) {
        this->clock.restart();
        this->controlled->setPosition(this->controlled->getPosition() + sf::Vector2f(0., TILE_SIZE.y)); }
}

void Play::render(const std::shared_ptr<sf::RenderTarget> &window)
{
    this->controlled->render(window);
    this->ghost->render(window);
    this->matrix.render(window);
}

}
