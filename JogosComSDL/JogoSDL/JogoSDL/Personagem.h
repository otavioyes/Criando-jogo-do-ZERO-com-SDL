#pragma once
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#endif // !PERSONAGEM_H

#include <SDL.h>

class Personagem
{
public: 
	Personagem(SDL_Renderer* renderizador);
	~Personagem();

	void evento(SDL_Event& eventoPersonagem);
	void move();
	void renderiza(SDL_Renderer* renderizador);


private:
	SDL_Texture* textura;
	SDL_Rect posReto;
	int velocX, velocY;
};
