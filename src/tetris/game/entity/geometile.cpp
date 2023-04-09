#include "tetris/entity/geometile.hpp"

namespace Geometile
{
//    Geometile::Geometile(Geometype type) 
//    {
//        this->type = type;
//        switch (this->type)
//        {
//            case Geometype::ziga:
//                this->tiles = { 
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f(-1., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 1., 1.))};
//                break;                                                                                 
//            case Geometype::saru:                                                                      
//                this->tiles = {                                                                        
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f(-1., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0.,-1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 1.,-1.))};
//                break;                                                                                 
//            case Geometype::jaga:                                                                      
//                this->tiles = {                                                                        
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0.,-1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f(-1., 1.))};
//                break;                                                                                 
//            case Geometype::liru:                                                                      
//                this->tiles = {                                                                        
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0.,-1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 1.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 1., 1.))};
//                break;                                                                                 
//            case Geometype::igu:                                                                       
//                this->tiles = {                                                                        
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.))};
//                break;                                                                                 
//            case Geometype::ora:                                                                       
//                this->tiles = {                                                                        
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.)),
//                    Tile(sf::Vector2f(20., 20.), sf::Vector2f(50., 50.), sf::Color::Red, sf::Vector2f( 0., 0.))};
//                break;
//        }
//    }

    Ziga::Ziga(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Red, sf::Vector2f(-1., 0.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 0., 0.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 0., 1.)),
              Tile(position, size, sf::Color::Red, sf::Vector2f( 1., 1.))}
    {
    }

    Ziga::~Ziga()
    {
    }

    sf::Vector2f Ziga::getPosition() 
    {
        return this->position;
    }

    void Ziga::setPosition(sf::Vector2f position)
    {
        for (auto& tile : tiles)
            tile.setPosition(position);
    }

    void Ziga::update() 
    {
        //something
    }

    void Ziga::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }

    Saru::Saru(sf::Vector2f position, sf::Vector2f size)
        : position(position),
        tiles{Tile(position, size, sf::Color::Green, sf::Vector2f(-1., 0.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 0., 0.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 0.,-1.)),
              Tile(position, size, sf::Color::Green, sf::Vector2f( 1.,-1.))}
    {
    }

    Saru::~Saru()
    {
    }

    sf::Vector2f Saru::getPosition() 
    {
        return this->position;
    }

    void Saru::setPosition(sf::Vector2f position)
    {
        for (auto& tile : tiles)
            tile.setPosition(position);
    }

    void Saru::update() 
    {
        //something
    }

    void Saru::render(const std::shared_ptr<sf::RenderTarget>& window)
    {
        for (auto& tile : tiles)
            tile.render(window);
    }
}
