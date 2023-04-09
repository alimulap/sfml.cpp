#include "tetris/game.hpp"

int main() {
    Game game = Game();

    while (game.isRunning())
    {
        game.update();
        game.render();
    }
}

