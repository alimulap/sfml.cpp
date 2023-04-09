#include "tetris/game.hpp"

void Game::initVariables()
{
}

void Game::initWindows()
{
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->window = std::make_shared<sf::RenderWindow>(this->videoMode, "testCmake", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
    this->initVariables();
    this->initWindows();
}

Game::~Game()
{
}

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
}

void Game::render()
{
    this->window->clear(sf::Color::White);

    this->a.render(window);

    this->window->display();
}

