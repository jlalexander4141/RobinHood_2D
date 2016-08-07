//Joshua Alexander

#ifndef _game_h
#define _game_h

//include SDL on windows
#if defined(_WIN32) || (_WIN64)
#include "SDL.h"
#include "SDL_image.h"
#endif
//include SDL on mac
#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class game
{
public:
	// GAME LOOP Variable
	bool inGame;
	// SDL Event handler
	SDL_Event event;
	// Create a SDL Window reference - pointer
	SDL_Window *window;
	// Create a SDL RenderTarget - pointer
	SDL_Renderer *renderTarget;
	// Create a SDL Surface - pointer
	SDL_Surface *surface;

	game()
	{
		inGame = true;
		window = nullptr;
		renderTarget = nullptr;
		surface = nullptr;
	}

	void createWindow();
	void destroyWindow();
};

#endif
