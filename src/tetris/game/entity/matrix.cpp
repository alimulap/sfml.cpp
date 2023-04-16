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

sf::Vector2i Matrix::getGeometilePos(std::unique_ptr<Geometile::Geometile>& geometile) {
    return static_cast<sf::Vector2i>((geometile->getPosition() - this->position) / TILE_SIZE); }

sf::Vector2i Matrix::getPosInMatrix(const sf::Vector2f& pos) {
    return static_cast<sf::Vector2i>((pos - this->position) / TILE_SIZE); }

bool Matrix::isValidAndInBound(std::unique_ptr<Geometile::Geometile>& geometile, const sf::Vector2f& nextPos)
{
    sf::Vector2i posInMatrix = this->getPosInMatrix(nextPos);
    int tileIndex = posInMatrix.y * 10 + posInMatrix.x;
    std::array<sf::Vector2f, 4> geoTiles = geometile->getOrigins();
    for (int i = 0; i < 4; ++i)
        if (!this->isValidAndInBound(posInMatrix.x + geoTiles[i].x,posInMatrix.y +  geoTiles[i].y))
            return false;

    return true;
}

bool Matrix::isValidAndInBound(const sf::Vector2f& position)
{
    auto pos = (position - this->position) / TILE_SIZE;
    return this->isValidAndInBound(pos.x, pos.y);
}

bool Matrix::isValidAndInBound(int x, int y)
{
    if (0 > x || x >= 10 || 0 > y || y >= 20)
        return false;
    auto pos = y * 10 + x;
    return isValidAndInBound(pos);
}

bool Matrix::isValidAndInBound(int index)
{
    if (0 > index || index >= 200)
        return false;
    return this->tiles[index] == std::nullopt;
}

void Matrix::fillWithGeometile(std::unique_ptr<Geometile::Geometile> geometile)
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

