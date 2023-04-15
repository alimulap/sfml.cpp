#pragma once

#include <array>
#include <memory>
#include <optional>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "tetris/entity/geometile.hpp"
#include "tetris/entity/tile.hpp"

class Matrix
{
private:
    std::array<sf::RectangleShape, 200> metrices;
    sf::RectangleShape border;
    sf::Vector2f position;

    std::array<std::optional<Tile>, 200> tiles{};

    void initMetrices();

public:
    Matrix(const sf::Vector2f& pos);
    ~Matrix();

    void fillWithGeometile(std::unique_ptr<Geometile::Geometile>& geometile);
    
    sf::Vector2i getGeometilePos(std::unique_ptr<Geometile::Geometile>& geometile);
    sf::Vector2f getGhostPos(std::unique_ptr<Geometile::Geometile>& controlled);

    const sf::Vector2f& getPosition();

    void render(const std::shared_ptr<sf::RenderTarget>& window);
};
