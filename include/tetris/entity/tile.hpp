#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <memory>

sf::Color adjustColor(const sf::Color& color, sf::Int8 relative, sf::Uint8 scale);

class Tile 
{
private:
    // Tile vertecies
    sf::Vertex vertecies[20];
    // Tile position absolute(?) i think
    sf::Vector2f position;
    // Size of the tile
    sf::Vector2f size;
    // Tile origin from 0 to 1 could be more or less if you want to
    sf::Vector2f origin;
    // Tile color
    sf::Color color;

    void initVertices();

public:
    //Tile();
    Tile(sf::Vector2f initPos, sf::Vector2f size, sf::Color color, sf::Vector2f origin);
    ~Tile();
    
    //\ position + (size * origin)
    //\ if the origin is (0.5, 0.5) 
    //\ setPosition(10., 10.) with size of (10., 10.)
    //\ will actually be (5., 5.)
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    // well.. size..
    void setSize();
    // render the tile
    void render(const std::shared_ptr<sf::RenderTarget>& window);
};

