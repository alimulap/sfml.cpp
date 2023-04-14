#pragma once

#include "SFML/System/Clock.hpp"
#include "state.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

#include "tetris/entity/matrix.hpp"
#include "tetris/entity/geometile.hpp"

namespace State 
{

class Play : public State
{
private:
    sf::Clock clock;

    Matrix matrix;
    std::unique_ptr<Geometile::Geometile> controlled;
    std::unique_ptr<Geometile::Geometile> ghost;

    std::optional<std::unique_ptr<State>> nextState = std::nullopt;

    bool moved = false;
    bool rotated = false;

public:
    Play();
    ~Play();

    std::optional<std::unique_ptr<State>> getNextState() override;
    void pollEvent() override;

    void update() override;
    void render(const std::shared_ptr<sf::RenderTarget>& window) override;
};

}
