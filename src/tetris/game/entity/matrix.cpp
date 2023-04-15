#include "tetris/entity/matrix.hpp"

#include <iostream>

#include "tetris/constants.hpp"

#include "util/operator_overload.hpp"

Matrix::Matrix(const sf::Vector2f& pos)
    : position(pos)
{
    this->initMetrices();
}

Matrix::~Matrix() { }

void Matrix::initMetrices()
{
    for (int i = 0; i < this->metrices.size(); ++i)
    {
        this->metrices[i].setSize(TILE_SIZE);
        this->metrices[i].setPosition( sf::Vector2f( this->position.x + i%10 * TILE_SIZE.x, this->position.y + static_cast<int>(i/10.) * TILE_SIZE.y));
        this->metrices[i].setOutlineThickness(0.4);
        this->metrices[i].setOutlineColor(sf::Color::White);
        this->metrices[i].setFillColor(sf::Color::Transparent);
    }

    this->border.setFillColor(sf::Color::Transparent);
    this->border.setOutlineColor(sf::Color::White);
    this->border.setOutlineThickness(this->metrices[0].getOutlineThickness() * 2);
    this->border.setSize(sf::Vector2f(10. * TILE_SIZE.x + this->border.getOutlineThickness() * 4, 20. * TILE_SIZE.y + this->border.getOutlineThickness() * 4));
    this->border.setPosition(this->position - sf::Vector2f(this->border.getOutlineThickness() * 2,this->border.getOutlineThickness() * 2));
}

const sf::Vector2f& Matrix::getPosition() {
    return this->position; }

sf::Vector2i Matrix::getGeometilePos(std::unique_ptr<Geometile::Geometile>& geometile)
{
    sf::Vector2f result = (geometile->getPosition() - this->position) / TILE_SIZE;
    return static_cast<sf::Vector2i>(result);
}

sf::Vector2f Matrix::getGhostPos(std::unique_ptr<Geometile::Geometile>& controlled)
{
    sf::Vector2i pos = this->getGeometilePos(controlled);
    int tilePos = pos.y * 10 + pos.x;
    std::array<sf::Vector2f, 4> geoTiles = controlled->getOrigins();
    std::array<int, 4> tilesPos{};
    for (int i = 0; i < 4; ++i)
        tilesPos[i] = tilePos + geoTiles[i].y * 10 + geoTiles[i].x;

    while (true) 
    {
        for (int i = 0; i < 4; ++i)
        {
            tilesPos[i] += 10;
            if (tilesPos[i] >= 200 || this->tiles[tilesPos[i]] != std::nullopt) 
                return sf::Vector2f(tilePos % 10, static_cast<int>(tilePos / 10.)) * TILE_SIZE + this->position;
        }

        tilePos += 10;
    }

    return sf::Vector2f(tilePos % 10, static_cast<int>(tilePos / 10.)) * TILE_SIZE + this->position;
}

void Matrix::fillWithGeometile(std::unique_ptr<Geometile::Geometile>& geometile)
{
    auto geoTiles = geometile->getTiles();
    auto geoPos = this->getGeometilePos(geometile);
    sf::Vector2i temp;
    for (int i = 0; i < 4; ++i) 
    {
        temp = geoPos + static_cast<sf::Vector2i>(geoTiles[i].getOrigin());
        this->tiles[temp.y * 10 + temp.x] = geoTiles[i];
    }
}

void Matrix::render(const std::shared_ptr<sf::RenderTarget>& window) 
{
    for (auto& tile : this->tiles)
        if (tile.has_value())
            tile->render(window);
    window->draw(this->border);
    for (const auto& i : this->metrices)
        window->draw(i); 
}

