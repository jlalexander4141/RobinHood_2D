//Joshua Alexander

/////////////////////////////////////////////// INSTRUCTIONS /////////////////////////////////////////////////////

// WASD or arrow keys to move

// spacebar to fire

/////////////////////////////////////////////// INSTRUCTIONS /////////////////////////////////////////////////////

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

#if defined(_WIN32) || (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//active screen
bool roomStart = true;
bool roomMid = false;
bool roomLower = false;
bool roomUpper = false;

int health = 10;
int ammo = 20;
int coins = 0;

int main(int argc, char* argv[]) {

#if defined(_WIN32) || (_WIN64)

	string currentWorkingDirectory(getcwd(NULL, 0));
	string images_dir = currentWorkingDirectory + "\\RobinHood_2D\\image\\";

#endif

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

		// ROOM START
		// Load Room PNG to a SDL Surface
		SDL_Surface *surface = IMG_Load("RobinHood_2D/image/roomStart.png");

		// Load Room PNG to a SDL Texture
		SDL_Texture *room1Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect room1Pos;

		// Set the x, y, width and height SDL Rectangle values
		room1Pos.x = 0;
		room1Pos.y = 0;
		room1Pos.w = SCREEN_WIDTH;
		room1Pos.h = SCREEN_HEIGHT;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		//ROOM MID
		// Load Room PNG to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/roomMid.png");

		// Load Room PNG to a SDL Texture
		SDL_Texture *room2Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect room2Pos;

		// Set the x, y, width and height SDL Rectangle values
		room2Pos.x = 0;
		room2Pos.y = 0;
		room2Pos.w = SCREEN_WIDTH;
		room2Pos.h = SCREEN_HEIGHT;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		//ROOM LOWER
		// Load Room PNG to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/roomLower.png");

		// Load Room PNG to a SDL Texture
		SDL_Texture *room3Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect room3Pos;

		// Set the x, y, width and height SDL Rectangle values
		room3Pos.x = 0;
		room3Pos.y = 0;
		room3Pos.w = SCREEN_WIDTH;
		room3Pos.h = SCREEN_HEIGHT;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		//ROOM UPPER
		// Load Room PNG to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/roomUpper.png");

		// Load Room PNG to a SDL Texture
		SDL_Texture *room4Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect room4Pos;

		// Set the x, y, width and height SDL Rectangle values
		room4Pos.x = 0;
		room4Pos.y = 0;
		room4Pos.w = SCREEN_WIDTH;
		room4Pos.h = SCREEN_HEIGHT;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

	// ******************* Create the room (background) texture - END *******************



	// ******************* Create the player texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/player.png");

		// Load Room BITMAP to a SDL Texture
		SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect playerPos;

		// Set the x, y, width and height SDL Rectangle values
		playerPos.x = 200;
		playerPos.y = 515;
		playerPos.w = 64;
		playerPos.h = 128;

		// Set the maximum velocity of the player
		const int PLAYER_VEL = 5;
		int gravity = 3;
		bool isJumping = false;
		Uint32 start = 0;

		// The velocity of the player
		int pVelX = 0;
		int pVelY = 0;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

	// ******************* Create the player texture - END *******************


	// ******************* Create the health texture - START *******************

	// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health10.png");

		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health10Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect healthPos;

		// Set the x, y, width and height SDL Rectangle values
		healthPos.x = 10;
		healthPos.y = 10;
		healthPos.w = 368;
		healthPos.h = 44;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health09.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health09Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health08.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health08Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health07.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health07Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health06.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health06Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health05.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health05Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health04.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health04Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health03.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health03Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health02.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health02Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health01.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health01Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/health00.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *health00Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the health texture - END *******************

		// ******************* Create the ammo texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/ammo20.png");

		// Load Room BITMAP to a SDL Texture
		SDL_Texture *ammo20Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect ammo20Pos;

		// Set the x, y, width and height SDL Rectangle values
		ammo20Pos.x = 10;
		ammo20Pos.y = 50;
		ammo20Pos.w = 367;
		ammo20Pos.h = 51;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo19.png");
		SDL_Texture *ammo19Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo18.png");
		SDL_Texture *ammo18Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo17.png");
		SDL_Texture *ammo17Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo16.png");
		SDL_Texture *ammo16Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo15.png");
		SDL_Texture *ammo15Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo14.png");
		SDL_Texture *ammo14Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo13.png");
		SDL_Texture *ammo13Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo12.png");
		SDL_Texture *ammo12Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo11.png");
		SDL_Texture *ammo11Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo10.png");
		SDL_Texture *ammo10Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo09.png");
		SDL_Texture *ammo09Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo08.png");
		SDL_Texture *ammo08Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo07.png");
		SDL_Texture *ammo07Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo06.png");
		SDL_Texture *ammo06Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo05.png");
		SDL_Texture *ammo05Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo04.png");
		SDL_Texture *ammo04Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo03.png");
		SDL_Texture *ammo03Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo02.png");
		SDL_Texture *ammo02Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo01.png");
		SDL_Texture *ammo01Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		surface = IMG_Load("RobinHood_2D/image/ammo00.png");
		SDL_Texture *ammo00Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);

		// ******************* Create the ammo texture - END *******************

		// ******************* Create the inventory texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins0.png");

		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins0Texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect coinsPos;

		// Set the x, y, width and height SDL Rectangle values
		coinsPos.x = 710;
		coinsPos.y = 10;
		coinsPos.w = 307;
		coinsPos.h = 117;

		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins1.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins1Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins2.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins2Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins3.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins3Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins4.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins4Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coins5.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coins5Texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the inventory texture - END *******************

		// ******************* Create the health pickup texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/healthPickup.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *healthPickupTexture = SDL_CreateTextureFromSurface(renderTarget, surface);
		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect healthPickupPos;
		// Set the x, y, width and height SDL Rectangle values
		healthPickupPos.x = 100;
		healthPickupPos.y = 400;
		healthPickupPos.w = 64;
		healthPickupPos.h = 64;
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the health pickup texture - END *******************

		// ******************* Create the ammo pickup texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/ammoPickup.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *ammoPickupTexture = SDL_CreateTextureFromSurface(renderTarget, surface);
		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect ammoPickupPos;
		// Set the x, y, width and height SDL Rectangle values
		ammoPickupPos.x = 200;
		ammoPickupPos.y = 400;
		ammoPickupPos.w = 64;
		ammoPickupPos.h = 64;
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the ammo pickup texture - END *******************

		// ******************* Create the coin pickup texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/coinPickup.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *coinPickupTexture = SDL_CreateTextureFromSurface(renderTarget, surface);
		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect coinPickupPos;
		// Set the x, y, width and height SDL Rectangle values
		coinPickupPos.x = 300;
		coinPickupPos.y = 400;
		coinPickupPos.w = 64;
		coinPickupPos.h = 64;
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the coin pickup texture - END *******************

		// ******************* Create the enemy test texture - START *******************

		// Load Room BITMAP to a SDL Surface
		surface = IMG_Load("RobinHood_2D/image/enemyTest.png");
		// Load Room BITMAP to a SDL Texture
		SDL_Texture *enemyTestTexture = SDL_CreateTextureFromSurface(renderTarget, surface);
		// Create a SDL Rectangle for the roomTexture's position and size
		SDL_Rect enemyTestPos;
		// Set the x, y, width and height SDL Rectangle values
		enemyTestPos.x = 600;
		enemyTestPos.y = 515;
		enemyTestPos.w = 64;
		enemyTestPos.h = 128;
		//Release the SDL surface for later use
		SDL_FreeSurface(surface);

		// ******************* Create the coin pickup texture - END *******************



	// ******************* Create the room walls - START *******************
		// DOORS
		// Create a SDL Rectangle for the position and size
		SDL_Rect room1Door1;
		// Set the x, y, width and height SDL Rectangle values
		room1Door1.x = 1024;
		room1Door1.y = 0;
		room1Door1.w = 1;
		room1Door1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Door1;
		// Set the x, y, width and height SDL Rectangle values
		room2Door1.x = 0;
		room2Door1.y = 0;
		room2Door1.w = 1;
		room2Door1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Door2;
		// Set the x, y, width and height SDL Rectangle values
		room2Door2.x = 845;
		room2Door2.y = 768;
		room2Door2.w = 200;
		room2Door2.h = 1;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Door3;
		// Set the x, y, width and height SDL Rectangle values
		room2Door3.x = 470;
		room2Door3.y = 0;
		room2Door3.w = 200;
		room2Door3.h = 1;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Door1;
		// Set the x, y, width and height SDL Rectangle values
		room3Door1.x = 845;
		room3Door1.y = 0;
		room3Door1.w = 200;
		room3Door1.h = 1;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room4Door1;
		// Set the x, y, width and height SDL Rectangle values
		room4Door1.x = 470;
		room4Door1.y = 768;
		room4Door1.w = 200;
		room4Door1.h = 1;

		// ROOM START
		// Create a SDL Rectangle for the position and size
		SDL_Rect room1Wall1;
		// Set the x, y, width and height SDL Rectangle values
		room1Wall1.x = 0;
		room1Wall1.y = 0;
		room1Wall1.w = 35;
		room1Wall1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room1Wall2;
		// Set the x, y, width and height SDL Rectangle values
		room1Wall2.x = 0;
		room1Wall2.y = 650;
		room1Wall2.w = 1024;
		room1Wall2.h = 10;

		// ROOM MID
		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall1;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall1.x = 990;
		room2Wall1.y = 0;
		room2Wall1.w = 10;
		room2Wall1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall2;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall2.x = 0;
		room2Wall2.y = 650;
		room2Wall2.w = 845;
		room2Wall2.h = 10;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall3;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall3.x = 722;
		room2Wall3.y = 433;
		room2Wall3.w = 300;
		room2Wall3.h = 30;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall4;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall4.x = 430;
		room2Wall4.y = 220;
		room2Wall4.w = 290;
		room2Wall4.h = 30;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall5;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall5.x = 430;
		room2Wall5.y = 0;
		room2Wall5.w = 37;
		room2Wall5.h = 220;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room2Wall6;
		// Set the x, y, width and height SDL Rectangle values
		room2Wall6.x = 615;
		room2Wall6.y = 0;
		room2Wall6.w = 500;
		room2Wall6.h = 35;

		// ROOM LOWER
		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall1;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall1.x = 0;
		room3Wall1.y = 0;
		room3Wall1.w = 35;
		room3Wall1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall2;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall2.x = 990;
		room3Wall2.y = 0;
		room3Wall2.w = 35;
		room3Wall2.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall3;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall3.x = 0;
		room3Wall3.y = 650;
		room3Wall3.w = 1024;
		room3Wall3.h = 10;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall4;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall4.x = 0;
		room3Wall4.y = 0;
		room3Wall4.w = 845;
		room3Wall4.h = 35;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall5;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall5.x = 775;
		room3Wall5.y = 218;
		room3Wall5.w = 500;
		room3Wall5.h = 500;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room3Wall6;
		// Set the x, y, width and height SDL Rectangle values
		room3Wall6.x = 560;
		room3Wall6.y = 433;
		room3Wall6.w = 500;
		room3Wall6.h = 500;

		// ROOM UPPER
		// Create a SDL Rectangle for the position and size
		SDL_Rect room4Wall1;
		// Set the x, y, width and height SDL Rectangle values
		room4Wall1.x = 0;
		room4Wall1.y = 0;
		room4Wall1.w = 35;
		room4Wall1.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room4Wall2;
		// Set the x, y, width and height SDL Rectangle values
		room4Wall2.x = 990;
		room4Wall2.y = 0;
		room4Wall2.w = 35;
		room4Wall2.h = 768;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room4Wall3;
		// Set the x, y, width and height SDL Rectangle values
		room4Wall3.x = 0;
		room4Wall3.y = 650;
		room4Wall3.w = 470;
		room4Wall3.h = 10;

		// Create a SDL Rectangle for the position and size
		SDL_Rect room4Wall4;
		// Set the x, y, width and height SDL Rectangle values
		room4Wall4.x = 615;
		room4Wall4.y = 650;
		room4Wall4.w = 500;
		room4Wall4.h = 10;
		
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

					case SDLK_UP:
						pVelY -= PLAYER_VEL;
						/*if (!isJumping)
						{
							isJumping = true;
						}*/
						break;
					case SDLK_DOWN:
						pVelY += PLAYER_VEL;
						break;
					case SDLK_LEFT:
						pVelX -= PLAYER_VEL;
						break;
					case SDLK_RIGHT:
						pVelX += PLAYER_VEL;
						break;

					case SDLK_w:
						pVelY -= PLAYER_VEL;
						/*if (isJumping != true)
						{
							isJumping = true;
						}*/
						break;
					case SDLK_s:
						pVelY += PLAYER_VEL;
						break;
					case SDLK_a:
						pVelX -= PLAYER_VEL;
						break;
					case SDLK_d:
						pVelX += PLAYER_VEL;
						break;

					case SDLK_SPACE:
						ammo--;
						break;

					}
				}
				//Check if a key was released
				else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
				{
					switch( event.key.keysym.sym )
					{

					case SDLK_UP:
						pVelY += PLAYER_VEL;
						break;
					case SDLK_DOWN:
						pVelY -= PLAYER_VEL;
						break;
					case SDLK_LEFT:
						pVelX += PLAYER_VEL;
						break;
					case SDLK_RIGHT:
						pVelX -= PLAYER_VEL;
						break;

					case SDLK_w:
						pVelY += PLAYER_VEL;
						break;
					case SDLK_s:
						pVelY -= PLAYER_VEL;
						break;
					case SDLK_a:
						pVelX += PLAYER_VEL;
						break;
					case SDLK_d:
						pVelX -= PLAYER_VEL;
						break;

					}
				}
			}

			// ******************* INPUT -END *******************


			// ******************* Start the SDL Draw Process *******************

		    	// Clear the SDL RenderTarget
		    	SDL_RenderClear(renderTarget);

				//if (isJumping)
				//{
				//	pVelY -= 3;
				//	start = SDL_GetTicks();
				//	if (start >= 5)
				//	{
				//		isJumping = false;
				//		start = 0;
				//	}
				//}
				//else
				//{
				//	start = 0;
				//	//playerPos.y += gravity;
				//}

				if (health >= 10)
				{
					health = 10;
				}
				if (ammo >= 20)
				{
					ammo = 20;
				}
				if (coins >= 5)
				{
					coins = 5;
				}
				if (ammo <= 0)
				{
					ammo = 0;
				}

				// ROOM START
				if (roomStart)
				{
					// Copy the roomTexture to the RenderTarget using the roomPos to place it in position
					SDL_RenderCopy(renderTarget, room1Texture, NULL, &room1Pos);

					//Move the player left or right
					playerPos.x += pVelX;

					// Check for wall collisions - left or right
					if (SDL_HasIntersection(&playerPos, &room1Wall1) || SDL_HasIntersection(&playerPos, &room1Wall2)) {

						//Move back
						playerPos.x -= pVelX;
					}

					//Move the player up or down
					playerPos.y += pVelY;

					// Check for wall collisions - up or down
					if (SDL_HasIntersection(&playerPos, &room1Wall1) || SDL_HasIntersection(&playerPos, &room1Wall2)) {

						//Move back
						playerPos.y -= pVelY;
					}

					// Check for health pickup collisions
					if (SDL_HasIntersection(&playerPos, &healthPickupPos)) {

						health = 10;
					}

					// Check for ammo pickup collisions
					if (SDL_HasIntersection(&playerPos, &ammoPickupPos)) {

						ammo = 20;
					}

					// Check for coin pickup collisions
					if (SDL_HasIntersection(&playerPos, &coinPickupPos)) {

						coins += 1;
					}

					// Check for coin enemyTest collisions
					if (SDL_HasIntersection(&playerPos, &enemyTestPos)) {

						health -= 1;
						playerPos.x -= pVelX;
						playerPos.y -= pVelY;

					}

					if (SDL_HasIntersection(&playerPos, &room1Door1))
					{
						roomStart = false;
						roomMid = true;
						playerPos.x = 10;
						playerPos.y = 515;
					}
				}

				//ROOM MID
				if (roomMid)
				{
					// Copy the roomTexture to the RenderTarget using the roomPos to place it in position
					SDL_RenderCopy(renderTarget, room2Texture, NULL, &room2Pos);

					//Move the player left or right
					playerPos.x += pVelX;

					// Check for wall collisions - left or right
					if (SDL_HasIntersection(&playerPos, &room2Wall1) || SDL_HasIntersection(&playerPos, &room2Wall2) || 
						SDL_HasIntersection(&playerPos, &room2Wall3) || SDL_HasIntersection(&playerPos, &room2Wall4) ||
						SDL_HasIntersection(&playerPos, &room2Wall5) || SDL_HasIntersection(&playerPos, &room2Wall6)) {

						//Move back
						playerPos.x -= pVelX;
					}

					//Move the player up or down
					playerPos.y += pVelY;

					// Check for wall collisions - up or down
					if (SDL_HasIntersection(&playerPos, &room2Wall1) || SDL_HasIntersection(&playerPos, &room2Wall2) ||
						SDL_HasIntersection(&playerPos, &room2Wall3) || SDL_HasIntersection(&playerPos, &room2Wall4) || 
						SDL_HasIntersection(&playerPos, &room2Wall5) || SDL_HasIntersection(&playerPos, &room2Wall6)) {

						//Move back
						playerPos.y -= pVelY;
					}

					if (SDL_HasIntersection(&playerPos, &room2Door1))
					{
						roomStart = true;
						roomMid = false;
						playerPos.x = 950;
						playerPos.y = 515;
					}
					if (SDL_HasIntersection(&playerPos, &room2Door2))
					{
						roomLower = true;
						roomMid = false;
						playerPos.x = 900;
						playerPos.y = 80;
					}
					if (SDL_HasIntersection(&playerPos, &room2Door3))
					{
						roomUpper = true;
						roomMid = false;
						playerPos.x = 620;
						playerPos.y = 515;
					}
				}

				// ROOM LOWER
				if (roomLower)
				{
					// Copy the roomTexture to the RenderTarget using the roomPos to place it in position
					SDL_RenderCopy(renderTarget, room3Texture, NULL, &room3Pos);

					//Move the player left or right
					playerPos.x += pVelX;

					// Check for wall collisions - left or right
					if (SDL_HasIntersection(&playerPos, &room3Wall1) || SDL_HasIntersection(&playerPos, &room3Wall2) ||
						SDL_HasIntersection(&playerPos, &room3Wall3) || SDL_HasIntersection(&playerPos, &room3Wall4) ||
						SDL_HasIntersection(&playerPos, &room3Wall5) || SDL_HasIntersection(&playerPos, &room3Wall6)) {

						//Move back
						playerPos.x -= pVelX;
					}

					//Move the player up or down
					playerPos.y += pVelY;

					// Check for wall collisions - up or down
					if (SDL_HasIntersection(&playerPos, &room3Wall1) || SDL_HasIntersection(&playerPos, &room3Wall2) ||
						SDL_HasIntersection(&playerPos, &room3Wall3) || SDL_HasIntersection(&playerPos, &room3Wall4) ||
						SDL_HasIntersection(&playerPos, &room3Wall5) || SDL_HasIntersection(&playerPos, &room3Wall6)) {

						//Move back
						playerPos.y -= pVelY;
					}

					if (SDL_HasIntersection(&playerPos, &room3Door1))
					{
						roomLower = false;
						roomMid = true;
						playerPos.x = 725;
						playerPos.y = 515;
					}
				}

				// ROOM UPPER
				if (roomUpper)
				{
					// Copy the roomTexture to the RenderTarget using the roomPos to place it in position
					SDL_RenderCopy(renderTarget, room4Texture, NULL, &room4Pos);

					//Move the player left or right
					playerPos.x += pVelX;

					// Check for wall collisions - left or right
					if (SDL_HasIntersection(&playerPos, &room4Wall1) || SDL_HasIntersection(&playerPos, &room4Wall2) ||
						SDL_HasIntersection(&playerPos, &room4Wall3) || SDL_HasIntersection(&playerPos, &room4Wall4)) {

						//Move back
						playerPos.x -= pVelX;
					}

					//Move the player up or down
					playerPos.y += pVelY;

					// Check for wall collisions - up or down
					if (SDL_HasIntersection(&playerPos, &room4Wall1) || SDL_HasIntersection(&playerPos, &room4Wall2) ||
						SDL_HasIntersection(&playerPos, &room4Wall3) || SDL_HasIntersection(&playerPos, &room4Wall4)) {

						//Move back
						playerPos.y -= pVelY;
					}

					if (SDL_HasIntersection(&playerPos, &room4Door1))
					{
						roomUpper = false;
						roomMid = true;
						playerPos.x = 475;
						playerPos.y = 75;
					}
				}

				// Copy the healthPickupTexture to the RenderTarget using the roomPos to place it in position
				SDL_RenderCopy(renderTarget, healthPickupTexture, NULL, &healthPickupPos);

				// Copy the ammoPickupTexture to the RenderTarget using the roomPos to place it in position
				SDL_RenderCopy(renderTarget, ammoPickupTexture, NULL, &ammoPickupPos);

				// Copy the coinPickupTexture to the RenderTarget using the roomPos to place it in position
				SDL_RenderCopy(renderTarget, coinPickupTexture, NULL, &coinPickupPos);

				// Copy the enemyTestTexture to the RenderTarget using the roomPos to place it in position
				SDL_RenderCopy(renderTarget, enemyTestTexture, NULL, &enemyTestPos);

				// Copy the playerTexture to the RenderTarget using the roomPos to place it in position
				SDL_RenderCopy(renderTarget, playerTexture, NULL, &playerPos);

				//update health GUI
				if (health == 10)
					SDL_RenderCopy(renderTarget, health10Texture, NULL, &healthPos);
				else if (health == 9)
					SDL_RenderCopy(renderTarget, health09Texture, NULL, &healthPos);
				else if (health == 8)
					SDL_RenderCopy(renderTarget, health08Texture, NULL, &healthPos);
				else if (health == 7)
					SDL_RenderCopy(renderTarget, health07Texture, NULL, &healthPos);
				else if (health == 6)
					SDL_RenderCopy(renderTarget, health06Texture, NULL, &healthPos);
				else if (health == 5)
					SDL_RenderCopy(renderTarget, health05Texture, NULL, &healthPos);
				else if (health == 4)
					SDL_RenderCopy(renderTarget, health04Texture, NULL, &healthPos);
				else if (health == 3)
					SDL_RenderCopy(renderTarget, health03Texture, NULL, &healthPos);
				else if (health == 2)
					SDL_RenderCopy(renderTarget, health02Texture, NULL, &healthPos);
				else if (health == 1)
					SDL_RenderCopy(renderTarget, health01Texture, NULL, &healthPos);
				else if (health == 0)
					SDL_RenderCopy(renderTarget, health00Texture, NULL, &healthPos);

				//update ammo GUI
				if (ammo == 20)
					SDL_RenderCopy(renderTarget, ammo20Texture, NULL, &ammo20Pos);
				else if (ammo == 19)
					SDL_RenderCopy(renderTarget, ammo19Texture, NULL, &ammo20Pos);
				else if (ammo == 18)
					SDL_RenderCopy(renderTarget, ammo18Texture, NULL, &ammo20Pos);
				else if (ammo == 17)
					SDL_RenderCopy(renderTarget, ammo17Texture, NULL, &ammo20Pos);
				else if (ammo == 16)
					SDL_RenderCopy(renderTarget, ammo16Texture, NULL, &ammo20Pos);
				else if (ammo == 15)
					SDL_RenderCopy(renderTarget, ammo15Texture, NULL, &ammo20Pos);
				else if (ammo == 14)
					SDL_RenderCopy(renderTarget, ammo14Texture, NULL, &ammo20Pos);
				else if (ammo == 13)
					SDL_RenderCopy(renderTarget, ammo13Texture, NULL, &ammo20Pos);
				else if (ammo == 12)
					SDL_RenderCopy(renderTarget, ammo12Texture, NULL, &ammo20Pos);
				else if (ammo == 11)
					SDL_RenderCopy(renderTarget, ammo11Texture, NULL, &ammo20Pos);
				else if (ammo == 10)
					SDL_RenderCopy(renderTarget, ammo10Texture, NULL, &ammo20Pos);
				else if (ammo == 9)
					SDL_RenderCopy(renderTarget, ammo09Texture, NULL, &ammo20Pos);
				else if (ammo == 8)
					SDL_RenderCopy(renderTarget, ammo08Texture, NULL, &ammo20Pos);
				else if (ammo == 7)
					SDL_RenderCopy(renderTarget, ammo07Texture, NULL, &ammo20Pos);
				else if (ammo == 6)
					SDL_RenderCopy(renderTarget, ammo06Texture, NULL, &ammo20Pos);
				else if (ammo == 5)
					SDL_RenderCopy(renderTarget, ammo05Texture, NULL, &ammo20Pos);
				else if (ammo == 4)
					SDL_RenderCopy(renderTarget, ammo04Texture, NULL, &ammo20Pos);
				else if (ammo == 3)
					SDL_RenderCopy(renderTarget, ammo03Texture, NULL, &ammo20Pos);
				else if (ammo == 2)
					SDL_RenderCopy(renderTarget, ammo02Texture, NULL, &ammo20Pos);
				else if (ammo == 1)
					SDL_RenderCopy(renderTarget, ammo01Texture, NULL, &ammo20Pos);
				else if (ammo == 0)
					SDL_RenderCopy(renderTarget, ammo00Texture, NULL, &ammo20Pos);

				//update inventory GUI
				if (coins == 0)
					SDL_RenderCopy(renderTarget, coins0Texture, NULL, &coinsPos);
				else if (coins == 1)
					SDL_RenderCopy(renderTarget, coins1Texture, NULL, &coinsPos);
				else if (coins == 2)
					SDL_RenderCopy(renderTarget, coins2Texture, NULL, &coinsPos);
				else if (coins == 3)
					SDL_RenderCopy(renderTarget, coins3Texture, NULL, &coinsPos);
				else if (coins == 4)
					SDL_RenderCopy(renderTarget, coins4Texture, NULL, &coinsPos);
				else if (coins == 5)
					SDL_RenderCopy(renderTarget, coins5Texture, NULL, &coinsPos);

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
