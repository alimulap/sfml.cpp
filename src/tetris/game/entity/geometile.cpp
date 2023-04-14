#include "tetris/entity/geometile.hpp"
#include "tetris/constants.hpp"

namespace Geometile
{
    Geometile::Geometile() { }

    Geometile::~Geometile() { }

    Zigga::Zigga(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Red, VF01),
              Tile(position, size, sf::Color::Red, VF11),
              Tile(position, size, sf::Color::Red, VF12),
              Tile(position, size, sf::Color::Red, VF22)} { }

    Zigga::~Zigga() { }

    Geometype Zigga::getType() {
        return Geometype::Zigga; }

    sf::Vector2f Zigga::getPosition() {
        return this->position; }

    void Zigga::setPosition(const sf::Vector2f& position) {
        this->position = position;
        for (auto& tile : tiles)
            tile.setPosition(position); }

    void Zigga::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF01);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF22);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF01);
            this->tiles[3].setOrigin(VF02);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF21);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF10);
            this->tiles[3].setOrigin(VF00);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF12);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF20);
            break;
        }
    }

    void Zigga::update() 
    {
        //something
    }

    void Zigga::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Sarru::Sarru(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Green, VF01),
              Tile(position, size, sf::Color::Green, VF11),
              Tile(position, size, sf::Color::Green, VF10),
              Tile(position, size, sf::Color::Green, VF20)} { }

    Sarru::~Sarru() { }

    void Sarru::rotate(short dir) 
    { 
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF01);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF10);
            this->tiles[3].setOrigin(VF20);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF22);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF21);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF02);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF12);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF01);
            this->tiles[3].setOrigin(VF00);
            break;
        }
    }

    Geometype Sarru::getType() {
        return Geometype::Sarru; }

    sf::Vector2f Sarru::getPosition() {
        return this->position; }

    void Sarru::setPosition(const sf::Vector2f& position) {
        this->position = position;
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

    Jagga::Jagga(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Blue, VF10),
              Tile(position, size, sf::Color::Blue, VF11),
              Tile(position, size, sf::Color::Blue, VF12),
              Tile(position, size, sf::Color::Blue, VF02)} { }

    Jagga::~Jagga() { }

    void Jagga::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF02);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF21);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF01);
            this->tiles[3].setOrigin(VF00);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF12);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF10);
            this->tiles[3].setOrigin(VF20);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF01);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF22);
            break;
        }
    }

    Geometype Jagga::getType() {
        return Geometype::Jagga; }

    sf::Vector2f Jagga::getPosition() {
        return this->position; }

    void Jagga::setPosition(const sf::Vector2f& position) {
        this->position = position;
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

    Lirru::Lirru(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color(255, 165, 0), VF10),
              Tile(position, size, sf::Color(255, 165, 0), VF11),
              Tile(position, size, sf::Color(255, 165, 0), VF12),
              Tile(position, size, sf::Color(255, 165, 0), VF22)} { }

    Lirru::~Lirru() { }

    void Lirru::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF22);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF21);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF01);
            this->tiles[3].setOrigin(VF02);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF12);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF10);
            this->tiles[3].setOrigin(VF00);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF01);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF20);
            break;
        }
    }

    Geometype Lirru::getType() {
        return Geometype::Lirru; }

    sf::Vector2f Lirru::getPosition() {
        return this->position; }

    void Lirru::setPosition(const sf::Vector2f& position) {
        this->position = position;
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

    Terru::Terru(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color(255, 0, 255), VF01),
              Tile(position, size, sf::Color(255, 0, 255), VF11),
              Tile(position, size, sf::Color(255, 0, 255), VF21),
              Tile(position, size, sf::Color(255, 0, 255), VF12)} { }

    Terru::~Terru() { }

    void Terru::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF01);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF12);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF01);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF21);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF01);
            this->tiles[3].setOrigin(VF10);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF12);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF10);
            this->tiles[3].setOrigin(VF21);
            break;
        }
    }

    Geometype Terru::getType() {
        return Geometype::Terru; }

    sf::Vector2f Terru::getPosition() {
        return this->position; }

    void Terru::setPosition(const sf::Vector2f& position) {
        this->position = position;
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

    Iggu::Iggu(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Cyan, VF02),
              Tile(position, size, sf::Color::Cyan, VF12),
              Tile(position, size, sf::Color::Cyan, VF22),
              Tile(position, size, sf::Color::Cyan, VF32)} { }

    Iggu::~Iggu() { }

    void Iggu::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        switch (this->rot)
        {
        case Rotation::r0:
            this->tiles[0].setOrigin(VF02);
            this->tiles[1].setOrigin(VF12);
            this->tiles[2].setOrigin(VF22);
            this->tiles[3].setOrigin(VF32);
            break;
        case Rotation::r90:
            this->tiles[0].setOrigin(VF10);
            this->tiles[1].setOrigin(VF11);
            this->tiles[2].setOrigin(VF12);
            this->tiles[3].setOrigin(VF13);
            break;
        case Rotation::r180:
            this->tiles[0].setOrigin(VF31);
            this->tiles[1].setOrigin(VF21);
            this->tiles[2].setOrigin(VF11);
            this->tiles[3].setOrigin(VF01);
            break;
        case Rotation::r270:
            this->tiles[0].setOrigin(VF23);
            this->tiles[1].setOrigin(VF22);
            this->tiles[2].setOrigin(VF21);
            this->tiles[3].setOrigin(VF20);
            break;
        }
    }

    Geometype Iggu::getType() {
        return Geometype::Iggu; }

    sf::Vector2f Iggu::getPosition() {
        return this->position; }

    void Iggu::setPosition(const sf::Vector2f& position) {
        this->position = position;
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

    Orra::Orra(const sf::Vector2f& position, const sf::Vector2f& size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Yellow, VF00),
              Tile(position, size, sf::Color::Yellow, VF10),
              Tile(position, size, sf::Color::Yellow, VF11),
              Tile(position, size, sf::Color::Yellow, VF01)} { }

    Orra::~Orra() { }

    void Orra::rotate(short dir) 
    {
        this->rot = (dir > 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot + 1) % 4) :
                    (dir < 0) ? static_cast<Rotation>(static_cast<uint8_t>(this->rot - 1) % 4) : this->rot;

        //switch (this->rot)
        //{
        //case Rotation::r0:
        //    this->tiles[0].setOrigin(VF01);
        //    this->tiles[1].setOrigin(VF11);
        //    this->tiles[2].setOrigin(VF12);
        //    this->tiles[3].setOrigin(VF22);
        //    break;
        //case Rotation::r90:
        //    this->tiles[0].setOrigin(VF10);
        //    this->tiles[1].setOrigin(VF11);
        //    this->tiles[2].setOrigin(VF01);
        //    this->tiles[3].setOrigin(VF02);
        //    break;
        //case Rotation::r180:
        //    this->tiles[0].setOrigin(VF21);
        //    this->tiles[1].setOrigin(VF11);
        //    this->tiles[2].setOrigin(VF10);
        //    this->tiles[3].setOrigin(VF00);
        //    break;
        //case Rotation::r270:
        //    this->tiles[0].setOrigin(VF12);
        //    this->tiles[1].setOrigin(VF11);
        //    this->tiles[2].setOrigin(VF21);
        //    this->tiles[3].setOrigin(VF20);
        //    break;
        //}
    }

    Geometype Orra::getType() {
        return Geometype::Orra; }

    sf::Vector2f Orra::getPosition() {
        return this->position; }

    void Orra::setPosition(const sf::Vector2f& position) {
        this->position = position;
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
