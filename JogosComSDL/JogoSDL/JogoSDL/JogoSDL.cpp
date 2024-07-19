#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>


int main() {
    Game game;
    if (!game.init()) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return 1;
    }

    game.run();
    game.close();
    return 0;
}