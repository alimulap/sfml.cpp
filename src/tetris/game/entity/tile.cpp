#include "tetris/entity/tile.hpp"

void Tile::initVertices()
{
    this->vertecies[0]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 1));
    this->vertecies[1]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 1));
    this->vertecies[2]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 1));
    this->vertecies[3]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 1));

    this->vertecies[4]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.0f, this->position.y + this->size.x * 1.0f), adjustColor(this->color, -20, 0));
    this->vertecies[5]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 2.0f, this->position.y + this->size.x * 1.0f), adjustColor(this->color, -20, 0));
    this->vertecies[6]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 0));
    this->vertecies[7]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 0));

    this->vertecies[8]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.0f, this->position.y + this->size.x * 1.0f), adjustColor(this->color, -20, 2));
    this->vertecies[9]  = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.0f, this->position.y + this->size.x * 2.0f), adjustColor(this->color, -20, 2));
    this->vertecies[10] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 2));
    this->vertecies[11] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 2));

    this->vertecies[12] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 2.0f, this->position.y + this->size.x * 1.0f), adjustColor(this->color, -20, 3));
    this->vertecies[13] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 2.0f, this->position.y + this->size.x * 2.0f), adjustColor(this->color, -20, 3));
    this->vertecies[14] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 3));
    this->vertecies[15] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.2f), adjustColor(this->color, -20, 3));

    this->vertecies[16] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.0f, this->position.y + this->size.x * 2.0f), adjustColor(this->color, -20, 4));
    this->vertecies[17] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 2.0f, this->position.y + this->size.x * 2.0f), adjustColor(this->color, -20, 4));
    this->vertecies[18] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.8f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 4));
    this->vertecies[19] = sf::Vertex(sf::Vector2f(this->position.x + this->size.x * 1.2f, this->position.y + this->size.x * 1.8f), adjustColor(this->color, -20, 4));
}

Tile::Tile(sf::Vector2f initPos, sf::Vector2f size, sf::Color color, sf::Vector2f origin) 
{
    this->origin = origin;
    this->position = initPos + sf::Vector2f(origin.x * size.x, origin.y * size.y);
    this->size = size;
    this->color = color;

    this->initVertices();
}

Tile::~Tile() 
{
}

void Tile::setPosition(sf::Vector2f pos)
{
    this->position = pos + sf::Vector2f(this->origin.x * this->size.x, this->origin.y * this->size.y);
}

void Tile::render(const std::shared_ptr<sf::RenderTarget>& window) 
{
    window->draw(this->vertecies, 20, sf::Quads);
}

sf::Color adjustColor(const sf::Color& color, sf::Int8 relative, sf::Uint8 scale) 
{
    sf::Color result;
    result.r = std::clamp(color.r + relative * scale, 0, 255);
    result.g = std::clamp(color.g + relative * scale, 0, 255);
    result.b = std::clamp(color.b + relative * scale, 0, 255);
    return result;
}
