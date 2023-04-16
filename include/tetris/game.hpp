#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "constants.hpp"
#include "tetris/state/play.hpp"
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

    std::unique_ptr<State::State> state = std::make_unique<State::Play>();

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
