#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "constants.hpp"
#include "entity/geometile.hpp"

class Game
{
private:
    // window stuff
    std::shared_ptr<sf::RenderWindow> window;
    // well.. video mode
    sf::VideoMode videoMode;

    // event stuff
    sf::Event event;

    Geometile::Ziga a = Geometile::Ziga(sf::Vector2f(20., 20.), sf::Vector2f(20., 20.));

    // initialize anything window related
    void initWindows();
    // initialize variables
    void initVariables();

public:
    Game();
    ~Game();

    const bool isRunning() const;

    // common event handler
    void pollEvent();

    // update the game every certain fps
    void update();
    // handling rendering
    void render();
};
