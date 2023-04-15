#include "tetris/entity/tile.hpp"
#include "util/operator_overload.hpp"
#include "tetris/constants.hpp"
#include <iostream>

void Tile::initVertices()
{
    this->vertecies[0]  = sf::Vertex(this->position + this->size * P5, adjustColor(this->color, -20, 1));
    this->vertecies[1]  = sf::Vertex(this->position + this->size * P6, adjustColor(this->color, -20, 1));
    this->vertecies[2]  = sf::Vertex(this->position + this->size * P7, adjustColor(this->color, -20, 1));
    this->vertecies[3]  = sf::Vertex(this->position + this->size * P8, adjustColor(this->color, -20, 1));

    this->vertecies[4]  = sf::Vertex(this->position + this->size * P1, adjustColor(this->color, -20, 0));
    this->vertecies[5]  = sf::Vertex(this->position + this->size * P2, adjustColor(this->color, -20, 0));
    this->vertecies[6]  = sf::Vertex(this->position + this->size * P6, adjustColor(this->color, -20, 0));
    this->vertecies[7]  = sf::Vertex(this->position + this->size * P5, adjustColor(this->color, -20, 0));

    this->vertecies[8]  = sf::Vertex(this->position + this->size * P1, adjustColor(this->color, -20, 2));
    this->vertecies[9]  = sf::Vertex(this->position + this->size * P4, adjustColor(this->color, -20, 2));
    this->vertecies[10] = sf::Vertex(this->position + this->size * P8, adjustColor(this->color, -20, 2));
    this->vertecies[11] = sf::Vertex(this->position + this->size * P5, adjustColor(this->color, -20, 2));
    
    this->vertecies[12] = sf::Vertex(this->position + this->size * P2, adjustColor(this->color, -20, 3));
    this->vertecies[13] = sf::Vertex(this->position + this->size * P3, adjustColor(this->color, -20, 3));
    this->vertecies[14] = sf::Vertex(this->position + this->size * P7, adjustColor(this->color, -20, 3));
    this->vertecies[15] = sf::Vertex(this->position + this->size * P6, adjustColor(this->color, -20, 3));

    this->vertecies[16] = sf::Vertex(this->position + this->size * P4, adjustColor(this->color, -20, 4));
    this->vertecies[17] = sf::Vertex(this->position + this->size * P3, adjustColor(this->color, -20, 4));
    this->vertecies[18] = sf::Vertex(this->position + this->size * P7, adjustColor(this->color, -20, 4));
    this->vertecies[19] = sf::Vertex(this->position + this->size * P8, adjustColor(this->color, -20, 4));
}

void Tile::adjustVerticesPos()
{
    this->vertecies[0].position  = this->position + this->size * P5;
    this->vertecies[1].position  = this->position + this->size * P6;
    this->vertecies[2].position  = this->position + this->size * P7;
    this->vertecies[3].position  = this->position + this->size * P8;
                                                                   
    this->vertecies[4].position  = this->position + this->size * P1;
    this->vertecies[5].position  = this->position + this->size * P2;
    this->vertecies[6].position  = this->position + this->size * P6;
    this->vertecies[7].position  = this->position + this->size * P5;
                                                                   
    this->vertecies[8].position  = this->position + this->size * P1;
    this->vertecies[9].position  = this->position + this->size * P4;
    this->vertecies[10].position = this->position + this->size * P8;
    this->vertecies[11].position = this->position + this->size * P5;
                                                                   
    this->vertecies[12].position = this->position + this->size * P2;
    this->vertecies[13].position = this->position + this->size * P3;
    this->vertecies[14].position = this->position + this->size * P7;
    this->vertecies[15].position = this->position + this->size * P6;
                                                                   
    this->vertecies[16].position = this->position + this->size * P4;
    this->vertecies[17].position = this->position + this->size * P3;
    this->vertecies[18].position = this->position + this->size * P7;
    this->vertecies[19].position = this->position + this->size * P8;
}

Tile::Tile(const sf::Vector2f& initPos, const sf::Vector2f& size, sf::Color color, const sf::Vector2f& origin) 
{
    this->origin = origin;
    this->position = initPos + origin * size;
    this->size = size;
    this->color = color;

    this->initVertices();
}

Tile::~Tile() 
{
}

void Tile::setPosition(const sf::Vector2f& pos) {
    this->position = pos + this->size * this->origin;
    this->adjustVerticesPos(); }

void Tile::setOrigin(const sf::Vector2f &newOrigin) 
{
    //this->position = this->position - this->size * this->origin + this->size * newOrigin;
    this->position = this->position - this->size * (this->origin - newOrigin);
    this->origin = newOrigin; 
    this->adjustVerticesPos(); 
}

sf::Vector2f Tile::getOrigin() {
    return this->origin; }

void Tile::render(const std::shared_ptr<sf::RenderTarget>& window) {
    window->draw(this->vertecies, 20, sf::Quads); }

sf::Color adjustColor(const sf::Color& color, sf::Int8 relative, sf::Uint8 scale) 
{
    sf::Color result;
    result.r = std::clamp(color.r + relative * scale, 0, 255);
    result.g = std::clamp(color.g + relative * scale, 0, 255);
    result.b = std::clamp(color.b + relative * scale, 0, 255);
    return result;
}
