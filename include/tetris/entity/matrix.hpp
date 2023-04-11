#include "SFML/Graphics/RectangleShape.hpp"

#include <array>
#include <memory>

#include "SFML/Graphics/RenderTarget.hpp"

class Matrix
{
private:
    std::array<sf::RectangleShape, 200> metrices;
    sf::RectangleShape border;
    sf::Vector2f position;

    void initMetrices();

public:
    Matrix(sf::Vector2f pos);
    ~Matrix();

    const sf::Vector2f& getPosition();

    void render(const std::shared_ptr<sf::RenderTarget>& window);
};
