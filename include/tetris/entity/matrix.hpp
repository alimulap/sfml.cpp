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
    Matrix(sf::Vector2f pos);
    ~Matrix();

    void fillWithGeometile(const Geometile::Geometile& geometile);

    const sf::Vector2f& getPosition();

    void render(const std::shared_ptr<sf::RenderTarget>& window);
};
