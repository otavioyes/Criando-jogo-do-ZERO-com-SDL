#pragma once

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Personagem.h"

class Game {
public:
    Game();
    ~Game();
    bool init();
    void run();
    void close();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Personagem* player;
    bool running;
};

#endif