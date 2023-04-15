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

enum Rotation 
{
    r0,
    r90,
    r180,
    r270,
};

namespace Geometile
{
    class Geometile
    {
    public:
        Geometile();
        virtual ~Geometile();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        virtual void rotate(short dir) = 0;

        virtual Geometype getType() = 0;

        virtual std::array<sf::Vector2f, 4> getOrigins() = 0;

        virtual std::array<Tile, 4> getTiles() = 0;

        virtual sf::Vector2f getPosition() = 0;
        virtual void setPosition(const sf::Vector2f& position) = 0;

        virtual void update() = 0;
        virtual void render(const std::shared_ptr<sf::RenderTarget>& window) = 0;
    };

    class Zigga : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Zigga(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Zigga();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Sarru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Sarru(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Sarru();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Jagga : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Jagga(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Jagga();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Lirru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Lirru(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Lirru();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Terru : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Terru(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Terru();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Iggu : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Iggu(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Iggu();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };

    class Orra : public Geometile
    {
    private:
        std::array<Tile, 4> tiles;
        sf::Vector2f position;

        Rotation rot = Rotation::r0;

    public:
        Orra(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Orra();

        //\> if dir is positive,
        //\> geometile will rotate 90 degree
        //\> if negative rotate -90 degree
        //\> otherwise will not rotate
        void rotate(short dir) override;

        Geometype getType() override;

        std::array<sf::Vector2f, 4> getOrigins() override;

        std::array<Tile, 4> getTiles() override;

        sf::Vector2f getPosition() override;
        void setPosition(const sf::Vector2f& position) override;

        void update() override;
        void render(const std::shared_ptr<sf::RenderTarget>& window) override;
    };
}
