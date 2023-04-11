#include "tetris/entity/matrix.hpp"

#include "tetris/constants.hpp"

Matrix::Matrix(sf::Vector2f pos)
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

void Matrix::render(const std::shared_ptr<sf::RenderTarget>& window) 
{
    for (const auto& i : this->metrices)
        window->draw(i); 
    window->draw(this->border);
}

