//============================================================================
// Name        : 2D_level.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//
///d
//include SDL on windows

//include SDL on windows
#if defined(_WIN32) || (_WIN64)
#include "SDL.h"
#endif
//include SDL on mac
#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#endif

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* argv[]) {

	// GAME LOOP Variable
	bool inGame = true;

	//SDL Event handler
	SDL_Event event;

	// ******************* Create the SDL Window - START *******************
		// Start SDL2
    	SDL_Init(SDL_INIT_EVERYTHING);

    	// Create a SDL Window reference - pointer
    	SDL_Window *window = nullptr;

    	// Create a SDL RenderTarget - pointer
    	SDL_Renderer *renderTarget = nullptr;

    	// Create a SDL Window in the middle of the screen
    	window = SDL_CreateWindow("Robin Hood 2D",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
							  SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    	//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		IMG_Init(imgFlags);

    	// Create an SDL RenderTarget
    	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // ******************* Create the SDL Window - END *******************



    // ******************* Create the room (background) texture - START *******************

		// Load Room BITMAP to a SDL Surface
		SDL_Surface *surface = IMG_Load("RobinHood_2D/image/roomStart.png");

		// Load Room BITMAP to a SDL Texture
		SDL_Texture *roomTexture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect roomPos;

		// Set the x, y, width and height SDL Rectangle values
		roomPos.x = 0;
		roomPos.y = 0;
		roomPos.w = SCREEN_WIDTH;
		roomPos.h = SCREEN_HEIGHT;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

	// ******************* Create the room (background) texture - END *******************



	// ******************* Create the player texture - START *******************

	// ******************* Create the player texture - END *******************



	// ******************* Create the room walls - START *******************
		// Create a SDL Rectangle for the Wall1's position and size
		SDL_Rect Wall1;

		// Set the x, y, width and height SDL Rectangle values
		Wall1.x = 610;
		Wall1.y = 0;
		Wall1.w = 33;
		Wall1.h = 321;

		// Create a SDL Rectangle for the Wall2's position and size
		SDL_Rect Wall2;

		// Set the x, y, width and height SDL Rectangle values
		Wall2.x = 784;
		Wall2.y = 288;
		Wall2.w = 240;
		Wall2.h = 33;

		// Create a SDL Rectangle for the Wall3's position and size
		SDL_Rect Wall3;

		// Set the x, y, width and height SDL Rectangle values
		Wall3.x = 0;
		Wall3.y = 536;
		Wall3.w = 832;
		Wall3.h = 33;

		// Create a SDL Rectangle for the Wall4's position and size
		SDL_Rect Wall4;

		// Set the x, y, width and height SDL Rectangle values
		Wall4.x = 291;
		Wall4.y = 155;
		Wall4.w = 33;
		Wall4.h = 414;
	// ******************* Create the room walls - END *******************



	// ******************* GAME LOOP - START *******************

		// While the loop is running
		while(inGame){

			// ******************* INPUT - START ****************

			// Check for Keyboard Input using SDL_Event event
			while( SDL_PollEvent( &event ) != 0 )
			{
				//Check if a key was pressed
				if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
				{
					switch( event.key.keysym.sym )
					{

					case SDLK_ESCAPE:
					{
						inGame = false;
					}break;

					}
				}
				//Check if a key was released
				else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
				{
					switch( event.key.keysym.sym )
					{



					}
				}
			}

			// ******************* INPUT -END *******************


			// ******************* UPDATE Player - START *****************
			// ******************* UPDATE Player - END *******************


			// ******************* Start the SDL Draw Process *******************

		    	// Clear the SDL RenderTarget
		    	SDL_RenderClear(renderTarget);

		    	// Copy the roomTexture to the RenderTarget using the roomPos to place it in position
		    	SDL_RenderCopy(renderTarget, roomTexture, NULL, &roomPos);

		    	// Draw "Present" the SDL RenderTarget to the user
		    	SDL_RenderPresent(renderTarget);

		    // ******************* End the SDL Draw Process *******************


		    // Delay so that we are at 60 FPS
		    SDL_Delay(16);

		}

	// ******************* GAME LOOP - END *******************

    // Cleanup and Quit
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
