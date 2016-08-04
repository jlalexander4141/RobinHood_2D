//Joshua Alexander

/////////////////////////////////////////////// INSTRUCTIONS /////////////////////////////////////////////////////

// WASD or arrow keys to move

// spacebar to fire

// escape key to quit

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

#include "game.h"
#include "player.h"
#include "pickup.h"
#include "hud.h"
#include "room.h"

game *game1;

player player1;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//current active room
bool roomStart = true;
bool roomMid = false;
bool roomLower = false;
bool roomUpper = false;
int CURRENT_ROOM = 0;
int START = 0;
int FIRST = 1;
int MID = 2;
int LOWER = 3;
int UPPER = 4;

//rect variables
//rooms
SDL_Rect room1Pos;
SDL_Rect room2Pos;
SDL_Rect room3Pos;
SDL_Rect room4Pos;
SDL_Rect room5Pos;
//player
SDL_Rect playerPos;
//doors
SDL_Rect room1Door1;
SDL_Rect room2Door1;
SDL_Rect room2Door2;
SDL_Rect room2Door3;
SDL_Rect room3Door1;
SDL_Rect room4Door1;
//walls
SDL_Rect room1Wall1;
SDL_Rect room1Wall2;
SDL_Rect room2Wall1;
SDL_Rect room2Wall2;
SDL_Rect room2Wall3;
SDL_Rect room2Wall4;
SDL_Rect room2Wall5;
SDL_Rect room2Wall6;
SDL_Rect room3Wall1;
SDL_Rect room3Wall2;
SDL_Rect room3Wall3;
SDL_Rect room3Wall4;
SDL_Rect room3Wall5;
SDL_Rect room3Wall6;
SDL_Rect room4Wall1;
SDL_Rect room4Wall2;
SDL_Rect room4Wall3;
SDL_Rect room4Wall4;

//texture variables
//rooms
SDL_Texture *room1Texture;
SDL_Texture *room2Texture;
SDL_Texture *room3Texture;
SDL_Texture *room4Texture;
SDL_Texture *room5Texture;
//player
SDL_Texture *playerTexture;

//player variables
const int PLAYER_VEL = 5;
int pVelX = 0;
int pVelY = 0;

//GUI variables
int health = 10;
int ammo = 20;
int coins = 0;

//check for keyboard input
bool keyInput(SDL_Event event, bool inGame)
{
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

	return inGame;
}

int main(int argc, char* argv[])
{

#if defined(_WIN32) || (_WIN64)

	string currentWorkingDirectory(getcwd(NULL, 0));
	string images_dir = currentWorkingDirectory + "\\RobinHood_2D\\image\\";

#endif

	//Create the SDL Window
	game1->createWindow();

	//setup the rooms
	room gameRoom;
	gameRoom.setup(game1);

	//setup the player
	player1.setup(game1);

	//setup the HUD
	healthGUI healthGUI1;
	healthGUI1.setup(game1);

	ammoGUI ammoGUI1;
	ammoGUI1.setup(game1);

	coinGUI coinGUI1;
	coinGUI1.setup(game1);

	// ******************* Create the health pickup texture - START *******************

	healthPickup healthPickup1;
	healthPickup1.setup(game1);

	// ******************* Create the health pickup texture - END *******************

	// ******************* Create the ammo pickup texture - START *******************

	ammoPickup ammoPickup1;
	ammoPickup1.setup(game1);

	// ******************* Create the ammo pickup texture - END *******************

	// ******************* Create the coin pickup texture - START *******************

	coinPickup coinPickup1;
	coinPickup1.setup(game1);

	// ******************* Create the coin pickup texture - END *******************

	// ******************* Create the enemy test texture - START *******************

	// Load Room BITMAP to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/enemyTest.png");
	// Load Room BITMAP to a SDL Texture
	SDL_Texture *enemyTestTexture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	// Create a SDL Rectangle for the roomTexture's position and size
	SDL_Rect enemyTestPos;
	// Set the x, y, width and height SDL Rectangle values
	enemyTestPos.x = 600;
	enemyTestPos.y = 515;
	enemyTestPos.w = 64;
	enemyTestPos.h = 128;
	//Release the SDL surface for later use
	SDL_FreeSurface(game1->surface);

	// ******************* Create the enemy test texture - END *******************


	//set the wall and door locations
	gameRoom.walls(game1);


	// ******************* GAME LOOP - START *******************

	// While the loop is running
	while(game1->inGame)
	{

		//check for keyboard input
		game1->inGame = keyInput(game1->event, game1->inGame);


		// ******************* Start the SDL Draw Process *******************

			// Clear the SDL RenderTarget
			SDL_RenderClear(game1->renderTarget);


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

			//update health pickup
			healthPickup1.draw(game1, 100, 400);

			//update ammo pickup
			ammoPickup1.draw(game1, 200, 400);

			//update coin pickup
			coinPickup1.draw(game1, 300, 400);

			// ROOM START
			if (CURRENT_ROOM == START)
			{
				//draw room
				gameRoom.draw(game1, CURRENT_ROOM);

				//Move the player left or right
				player1.pos.x += pVelX;

				// Check for wall collisions - left or right
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[0][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[0][1]))
				{

					//Move back
					player1.pos.x -= pVelX;
				}

				//Move the player up or down
				player1.pos.y += pVelY;

				// Check for wall collisions - up or down
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[0][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[0][1]))
				{

					//Move back
					player1.pos.y -= pVelY;
				}

				// Check for health pickup collisions
				if (SDL_HasIntersection(&player1.pos, &healthPickup1.pos)) {

					health = 10;
				}

				// Check for ammo pickup collisions
				if (SDL_HasIntersection(&player1.pos, &ammoPickup1.pos)) {

					ammo = 20;
				}

				// Check for coin pickup collisions
				if (SDL_HasIntersection(&player1.pos, &coinPickup1.pos)) {

					coins += 1;
				}

				// Check for coin enemyTest collisions
				if (SDL_HasIntersection(&player1.pos, &enemyTestPos)) {

					health -= 1;
					player1.pos.x -= pVelX;
					player1.pos.y -= pVelY;

				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[0][0]))
				{
					roomStart = false;
					roomMid = true;
					player1.pos.x = 10;
					player1.pos.y = 515;
				}
			}

			//ROOM MID
			if (CURRENT_ROOM == MID)
			{
				//draw room
				gameRoom.draw(game1, CURRENT_ROOM);

				//Move the player left or right
				player1.pos.x += pVelX;

				// Check for wall collisions - left or right
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][3]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][4]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][5]))
				{

					//Move back
					player1.pos.x -= pVelX;
				}

				//Move the player up or down
				player1.pos.y += pVelY;

				// Check for wall collisions - up or down
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][3]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][4]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[2][5]))
				{

					//Move back
					player1.pos.y -= pVelY;
				}

				if (SDL_HasIntersection(&player1.pos, &room2Door1))
				{
					roomStart = true;
					roomMid = false;
					player1.pos.x = 950;
					player1.pos.y = 515;
				}
				if (SDL_HasIntersection(&player1.pos, &room2Door2))
				{
					roomLower = true;
					roomMid = false;
					player1.pos.x = 900;
					player1.pos.y = 80;
				}
				if (SDL_HasIntersection(&player1.pos, &room2Door3))
				{
					roomUpper = true;
					roomMid = false;
					player1.pos.x = 620;
					player1.pos.y = 515;
				}
			}

			// ROOM LOWER
			if (CURRENT_ROOM == LOWER)
			{
				//draw room
				gameRoom.draw(game1, CURRENT_ROOM);

				//Move the player left or right
				player1.pos.x += pVelX;

				// Check for wall collisions - left or right
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][3]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][4]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][5]))
				{

					//Move back
					player1.pos.x -= pVelX;
				}

				//Move the player up or down
				player1.pos.y += pVelY;

				// Check for wall collisions - up or down
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][3]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][4]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[3][5]))
				{

					//Move back
					player1.pos.y -= pVelY;
				}

				if (SDL_HasIntersection(&player1.pos, &room3Door1))
				{
					roomLower = false;
					roomMid = true;
					player1.pos.x = 725;
					player1.pos.y = 515;
				}
			}

			// ROOM UPPER
			if (CURRENT_ROOM == UPPER)
			{
				//draw room
				gameRoom.draw(game1, CURRENT_ROOM);

				//Move the player left or right
				player1.pos.x += pVelX;

				// Check for wall collisions - left or right
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][3]))
				{

					//Move back
					player1.pos.x -= pVelX;
				}

				//Move the player up or down
				player1.pos.y += pVelY;

				// Check for wall collisions - up or down
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][0]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][1]) ||
					SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][2]) || SDL_HasIntersection(&player1.pos, &gameRoom.wall[4][3]))
				{

					//Move back
					player1.pos.y -= pVelY;
				}

				if (SDL_HasIntersection(&player1.pos, &room4Door1))
				{
					roomUpper = false;
					roomMid = true;
					player1.pos.x = 475;
					player1.pos.y = 75;
				}
			}

			// Copy the enemyTestTexture to the RenderTarget using the roomPos to place it in position
			SDL_RenderCopy(game1->renderTarget, enemyTestTexture, NULL, &enemyTestPos);

			//update player
			player1.draw(game1);

			//update health GUI
			healthGUI1.draw(game1, health);

			//update ammo GUI
			ammoGUI1.draw(game1, ammo);

			//update inventory GUI
			coinGUI1.draw(game1, coins);

			// Draw "Present" the SDL RenderTarget to the user
			SDL_RenderPresent(game1->renderTarget);

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
