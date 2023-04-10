#include "tetris/entity/geometile.hpp"

namespace Geometile
{
    Geometile::Geometile() { }

    Geometile::~Geometile() { }

    Zigga::Zigga(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Red, sf::Vector2f( 0., 0.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 1., 0.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 2., 1.))} { }

    Zigga::~Zigga() { }

    Geometype Zigga::getType() {
        return Geometype::Zigga; }

    sf::Vector2f Zigga::getPosition() {
        return this->position; }

    void Zigga::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Zigga::update() 
    {
        //something
    }

    void Zigga::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Sarru::Sarru(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Green, sf::Vector2f( 0., 1.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 1., 0.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 2., 0.))} { }

    Sarru::~Sarru() { }

    Geometype Sarru::getType() {
        return Geometype::Sarru; }

    sf::Vector2f Sarru::getPosition() {
        return this->position; }

    void Sarru::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Sarru::update() 
    {
        //something
    }

    void Sarru::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Jagga::Jagga(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Blue, sf::Vector2f( 1., 0.)),
              Tile(position, size, sf::Color::Blue, sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color::Blue, sf::Vector2f( 1., 2.)),
              Tile(position, size, sf::Color::Blue, sf::Vector2f( 0., 2.))} { }

    Jagga::~Jagga() { }

    Geometype Jagga::getType() {
        return Geometype::Jagga; }

    sf::Vector2f Jagga::getPosition() {
        return this->position; }

    void Jagga::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Jagga::update() 
    {
        //something
    }

    void Jagga::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Lirru::Lirru(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color(255, 165, 0), sf::Vector2f( 1., 0.)),
              Tile(position, size, sf::Color(255, 165, 0), sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color(255, 165, 0), sf::Vector2f( 1., 2.)),
              Tile(position, size, sf::Color(255, 165, 0), sf::Vector2f( 2., 2.))} { }

    Lirru::~Lirru() { }

    Geometype Lirru::getType() {
        return Geometype::Lirru; }

    sf::Vector2f Lirru::getPosition() {
        return this->position; }

    void Lirru::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Lirru::update() 
    {
        //something
    }

    void Lirru::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Terru::Terru(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color(255, 0, 255), sf::Vector2f( 0., 1.)),
              Tile(position, size, sf::Color(255, 0, 255), sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color(255, 0, 255), sf::Vector2f( 2., 1.)),
              Tile(position, size, sf::Color(255, 0, 255), sf::Vector2f( 1., 2.))} { }

    Terru::~Terru() { }

    Geometype Terru::getType() {
        return Geometype::Terru; }

    sf::Vector2f Terru::getPosition() {
        return this->position; }

    void Terru::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Terru::update() 
    {
        //something
    }

    void Terru::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Iggu::Iggu(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Cyan, sf::Vector2f( 0., 2.)),
              Tile(position, size, sf::Color::Cyan, sf::Vector2f( 1., 2.)),
              Tile(position, size, sf::Color::Cyan, sf::Vector2f( 2., 2.)),
              Tile(position, size, sf::Color::Cyan, sf::Vector2f( 3., 2.))} { }

    Iggu::~Iggu() { }

    Geometype Iggu::getType() {
        return Geometype::Iggu; }

    sf::Vector2f Iggu::getPosition() {
        return this->position; }

    void Iggu::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Iggu::update() 
    {
        //something
    }

    void Iggu::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Orra::Orra(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Yellow, sf::Vector2f( 0., 0.)),
              Tile(position, size, sf::Color::Yellow, sf::Vector2f( 1., 0.)),
              Tile(position, size, sf::Color::Yellow, sf::Vector2f( 1., 1.)),
              Tile(position, size, sf::Color::Yellow, sf::Vector2f( 0., 1.))} { }

    Orra::~Orra() { }

    Geometype Orra::getType() {
        return Geometype::Orra; }

    sf::Vector2f Orra::getPosition() {
        return this->position; }

    void Orra::setPosition(sf::Vector2f position) {
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Orra::update() 
    {
        //something
    }

    void Orra::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }
}
