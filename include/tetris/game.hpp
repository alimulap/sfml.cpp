#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "constants.hpp"
#include "entity/geometile.hpp"
#include "entity/matrix.hpp"
#include "handler/window_handler.hpp"

class Game
{
private:
    //\> window stuff
    std::shared_ptr<sf::RenderWindow> window;
    //\> well.. video mode
    sf::VideoMode videoMode;

    sf::ContextSettings settings;

    //\> event stuff
    sf::Event event;

    sf::Image img;
    sf::Texture tex;
    sf::Sprite sp;

    std::unique_ptr<Geometile::Geometile> a = std::make_unique<Geometile::Zigga>(Geometile::Zigga(sf::Vector2f(20. , 20.), TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> b = std::make_unique<Geometile::Sarru>(Geometile::Sarru(sf::Vector2f(100., 20.), TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> c = std::make_unique<Geometile::Jagga>(Geometile::Jagga(sf::Vector2f(180., 20.), TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> d = std::make_unique<Geometile::Lirru>(Geometile::Lirru(sf::Vector2f(260., 20.), TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> e = std::make_unique<Geometile::Terru>(Geometile::Terru(sf::Vector2f(340., 20.), TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> f = std::make_unique<Geometile::Iggu>(Geometile::Iggu(sf::Vector2f(20. , 120.),  TILE_SIZE));
    std::unique_ptr<Geometile::Geometile> g = std::make_unique<Geometile::Orra>(Geometile::Orra(sf::Vector2f(120., 120.),  TILE_SIZE));

    Matrix matrix;

    //\> initialize anything window related
    void initWindows();
    //\> initialize variables
    void initVariables();

public:
    Game();
    ~Game();

    //\> Check if the application is still running
    const bool isRunning() const;

    //\> common event handler
    void pollEvent();

    //\> update the game every certain fps
    void update();
    //\> handling rendering
    void render();
};
