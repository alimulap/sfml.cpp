#include "tetris/game.hpp"

void Game::initVariables()
{
}

void Game::initWindows()
{
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->settings.antialiasingLevel = 3.0;
    this->window = std::make_shared<sf::RenderWindow>(this->videoMode, "  Tetris", sf::Style::Titlebar, this->settings);
    Handler::enableBlurBehindWindow(this->window->getSystemHandle());
}

Game::Game()
{
    this->initWindows();
    this->initVariables();
}

Game::~Game() { }

const bool Game::isRunning() const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            this->state->pollEvent();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				this->window->close();
			break;
        default:
            break;
        }
    }
}

void Game::update() 
{
    this->pollEvent();
    this->state->update();
}

void Game::render()
{
    this->window->clear(sf::Color::Transparent);
    
    this->state->render(this->window);

    this->window->display();
}

