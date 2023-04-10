#include "tetris/game.hpp"

void Game::initVariables()
{
}

void Game::initWindows()
{
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->window = std::make_shared<sf::RenderWindow>(this->videoMode, "  Tetris", sf::Style::None);
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
    this->window->clear(sf::Color::Transparent);

    this->a->render(window);
    this->b->render(window);
    this->c->render(window);
    this->d->render(window);
    this->e->render(window);
    this->f->render(window);
    this->g->render(window);

    this->window->display();
}
