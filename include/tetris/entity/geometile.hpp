#pragma once

#include "SFML/System/Vector2.hpp"

#include <array>

#include "tile.hpp"

enum Geometype
{
    Zigga,
    Sarru,
    Jagga,
    Lirru,
    Terru,
    Iggu,
    Orra,
};

namespace Geometile
{
    class Geometile
    {
    public:
        Geometile();
        virtual ~Geometile();

        virtual Geometype getType() = 0;

        virtual sf::Vector2f getPosition() = 0;
        virtual void setPosition(sf::Vector2f position) = 0;

        virtual void update() = 0;
        virtual void render(const std::shared_ptr<sf::RenderTarget>& window) = 0;
    };

    class Zigga : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Zigga(sf::Vector2f position, sf::Vector2f size);
        ~Zigga();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Sarru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Sarru(sf::Vector2f position, sf::Vector2f size);
        ~Sarru();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Jagga : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Jagga(sf::Vector2f position, sf::Vector2f size);
        ~Jagga();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Lirru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Lirru(sf::Vector2f position, sf::Vector2f size);
        ~Lirru();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Terru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Terru(sf::Vector2f position, sf::Vector2f size);
        ~Terru();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Iggu : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Iggu(sf::Vector2f position, sf::Vector2f size);
        ~Iggu();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Orra : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

    public:
        Orra(sf::Vector2f position, sf::Vector2f size);
        ~Orra();

        Geometype getType() override;

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };
}
