#include "Personagem.h"

#include <SDL_image.h>
#include <iostream>

Personagem::Personagem(SDL_Renderer* renderizador) : velocX(0), velocY(0)
{
	SDL_Surface* tempSuperficie = IMG_Load("personagem.png");
	if (!tempSuperficie) {
		std::cerr << "Falha ao carregar a imagem do personagem! IMG_ERROR: " << IMG_GetError() << std::endl;
	}
	else
	{
		textura = SDL_CreateTextureFromSurface(renderizador, tempSuperficie);
		SDL_FreeSurface(tempSuperficie);
	}
	posReto = { 100, 100, 32, 32 }; //posicao e tamanho do peronagem 
}

Personagem::~Personagem() {
    SDL_DestroyTexture(textura);
}

void Personagem::evento(SDL_Event& eventoPersonagem) {
    if (eventoPersonagem.type == SDL_KEYDOWN && eventoPersonagem.key.repeat == 0) {
        switch (eventoPersonagem.key.keysym.sym) {
        case SDLK_UP: velocY -= 5; break;
        case SDLK_DOWN: velocY += 5; break;
        case SDLK_LEFT: velocX -= 5; break;
        case SDLK_RIGHT: velocX += 5; break;
        }
    }
    else if (eventoPersonagem.type == SDL_KEYUP && eventoPersonagem.key.repeat == 0) {
        switch (eventoPersonagem.key.keysym.sym) {
        case SDLK_UP: velocY += 5; break;
        case SDLK_DOWN: velocY -= 5; break;
        case SDLK_LEFT: velocX += 5; break;
        case SDLK_RIGHT: velocX -= 5; break;
        }
    }
}

void Personagem::move() {
    posReto.x += velocX;
    posReto.y += velocY;

    // Manter dentro dos limites da janela
    if (posReto.x < 0 || (posReto.x + posReto.w) > 800) {
        posReto.x -= velocX;
    }
    if (posReto.y < 0 || (posReto.y + posReto.h) > 600) {
        posReto.y -= velocY;
    }
}

void Personagem::renderiza(SDL_Renderer* renderizador) {
    SDL_RenderCopy(renderizador, textura, nullptr, &posReto);
}