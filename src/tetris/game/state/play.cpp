#include "tetris/state/play.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "tetris/constants.hpp"
#include "util/operator_overload.hpp"
#include <iostream>

namespace State
{

Play::Play()
    : matrix(sf::Vector2f(0., 0.))
{
    this->clock.restart();

    this->controlled = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(0., 0.) * TILE_SIZE, TILE_SIZE);
    this->ghost = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(0., 0.) * TILE_SIZE, TILE_SIZE);
    this->ikan = std::make_unique<Geometile::Zigga>(this->matrix.getPosition() + sf::Vector2f(3., 10.) * TILE_SIZE, TILE_SIZE);
    this->matrix.fillWithGeometile(this->ikan);
}

Play::~Play() { }

void Play::updateGhost()
{

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
    //\> move down
    if (this->clock.getElapsedTime().asSeconds() > 1.f) 
    {
        this->clock.restart();
        this->controlled->setPosition(this->controlled->getPosition() + sf::Vector2f(0., TILE_SIZE.y));
        this->ghost->setPosition(this->matrix.getGhostPos(this->controlled));
    }

    //\> move horizontal
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (!this->moved) {
            this->controlled->setPosition(this->controlled->getPosition() + sf::Vector2f( TILE_SIZE.x, 0.));
            this->ghost->setPosition(this->matrix.getGhostPos(this->controlled));
            this->moved = true;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (!this->moved) {
            this->controlled->setPosition(this->controlled->getPosition() + sf::Vector2f(-TILE_SIZE.x, 0.));
            this->ghost->setPosition(this->matrix.getGhostPos(this->controlled));
            this->moved = true;
        }
    } else {
        this->moved = false;
    }

    //\> move vertical
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (!this->rotated) {
            this->controlled->rotate( 1);
            this->ghost->rotate( 1);
            this->ghost->setPosition(this->matrix.getGhostPos(this->controlled));
            this->rotated = true;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        if (!this->rotated) {
            this->controlled->rotate(-1);
            this->ghost->rotate(-1);
            this->ghost->setPosition(this->matrix.getGhostPos(this->controlled));
            this->rotated = true;
        }
    } else {
        this->rotated = false;
    }
}

void Play::render(const std::shared_ptr<sf::RenderTarget> &window)
{
    this->controlled->render(window);
    this->ghost->render(window);
    this->matrix.render(window);
}

}
