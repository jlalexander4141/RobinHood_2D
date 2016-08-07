//Joshua Alexander

#include "game.h"

void game::createWindow()
{
	// Start SDL2
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create a SDL Window in the middle of the screen
	window = SDL_CreateWindow("Robin Hood 2D",
						  SDL_WINDOWPOS_CENTERED,
						  SDL_WINDOWPOS_CENTERED,
						  1024, 768,
						  SDL_WINDOW_SHOWN);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);

	// Create an SDL RenderTarget
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void game::destroyWindow()
{
	SDL_DestroyWindow(window);
}
