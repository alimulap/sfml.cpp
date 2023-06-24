#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/System/Clock.hpp"

#include "state.hpp"
#include "util/operator_overload.hpp"
#include "tetris/entity/matrix.hpp"
#include "tetris/entity/geometile.hpp"
#include "tetris/constants.hpp"


namespace State 
{

class Play : public State
{
private:
    sf::Clock automaticMoveClock;
    sf::Clock moveClock;

    Matrix matrix;

    std::optional<std::unique_ptr<Geometile::Geometile>> controlled;
    std::optional<std::unique_ptr<Geometile::Geometile>> ghost;
    std::optional<std::unique_ptr<Geometile::Geometile>> ikan;

    std::optional<std::unique_ptr<State>> nextState = std::nullopt;

    Direction moveAction = Direction::None;

    bool moved = false;
    bool rotated = false;

    void geometileController();
    void moveControlled(Direction dir);
    void updateGhost();

public:
    Play();
    ~Play();

    std::optional<std::unique_ptr<State>> getNextState() override;

    void pollEvent() override;

    void update() override;
    void render(const std::shared_ptr<sf::RenderTarget>& window) override;
};

}
