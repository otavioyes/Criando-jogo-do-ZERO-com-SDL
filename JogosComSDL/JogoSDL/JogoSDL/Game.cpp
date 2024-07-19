#include "Game.h"
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), player(nullptr), running(false) {}

Game::~Game() {
    close();
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return false;
    }

    player = new Personagem(renderer);
    running = true;

    return true;
}

void Game::run() {
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            player->evento(e);
        }

        player->move();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Preto
        SDL_RenderClear(renderer);

        player->renderiza(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Game::close() {
    delete player;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}