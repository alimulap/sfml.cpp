#include <iostream>
#include "SFML/System/Vector2.hpp"
#include "include/window/window_handler.hpp"

sf::Vector2f operator *(sf::Vector2f left, sf::Vector2f right)
{
    return sf::Vector2f(left.x * right.x, left.y * right.y);
}

int main()
{
    sf::Vector2f a(1.,2.);
    sf::Vector2f b(1.,2.);

    sf::Vector2f c = a * b;

    std::cout << c.x 
              << ", "
              << c.y;
}
