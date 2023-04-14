#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Event.hpp"
#include <memory>
#include <optional>

enum class StateType
{
    MainMenu,
    Play,
};

namespace State 
{
    class State 
    {
    public:
        virtual std::optional<std::unique_ptr<State>> getNextState() = 0;
        virtual void pollEvent() = 0;

        virtual void update() = 0;
        virtual void render(const std::shared_ptr<sf::RenderTarget>& window) = 0;
    };
}
