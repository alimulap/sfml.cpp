#include "SFML/System/Vector2.hpp"

#include <array>

#include "tile.hpp"

namespace Geometile
{
    class Geometile
    {
    public:
        virtual sf::Vector2f getPosition() = 0;
        virtual void setPosition(sf::Vector2f position) = 0;

        virtual void update() = 0;
        virtual void render(const std::shared_ptr<sf::RenderTarget>& window) = 0;
    };

    class Ziga : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Ziga(sf::Vector2f position, sf::Vector2f size);
        ~Ziga();

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Saru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Saru(sf::Vector2f position, sf::Vector2f size);
        ~Saru();

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };
}
