//Joshua Alexander

/////////////////////////////////////////////// INSTRUCTIONS /////////////////////////////////////////////////////

// A and D to move

// W to jump

// spacebar to fire

// escape key to quit

/////////////////////////////////////////////// INSTRUCTIONS /////////////////////////////////////////////////////

#if defined(_WIN32) || (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif

#include "game.h"
#include "player.h"
#include "pickup.h"
#include "hud.h"
#include "room.h"
#include "turret.h"
#include "enemy.h"
#include "decor.h"

game game1;

player player1;
bool playerFaceRight = true;
bool playerFaceLeft = false;
bool shot = false;
bool jumping = false;
bool canJump = true;
int jumpCount = 0;
SDL_Rect pBulletPos;
SDL_Rect eBulletPos;

bool win = false;
bool lose = false;

bool coin1 = false;
bool coin2 = false;
bool coin3 = false;
bool coin4 = false;
bool coin5 = false;

//current active room
int CURRENT_ROOM = 6;
int START = 0;
int FIRST = 5;
int MID = 2;
int LOWER = 3;
int UPPER = 4;
int TITLE = 6;
int CREDITS = 7;
int INSTRUCTIONS = 8;
int WIN = 9;
int LOSE = 10;

//rect variables
//player
SDL_Rect playerPos;

//texture variables
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
				if(canJump)
				{
					jumping = true;
					canJump = false;
				}
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				pVelX -= PLAYER_VEL;
				playerFaceLeft = true;
				playerFaceRight = false;
				break;
			case SDLK_RIGHT:
				pVelX += PLAYER_VEL;
				playerFaceLeft = false;
				playerFaceRight = true;
				break;

			case SDLK_w:
				if(canJump)
				{
					jumping = true;
					canJump = false;
				}
				break;
			case SDLK_s:
				break;
			case SDLK_a:
				pVelX -= PLAYER_VEL;
				playerFaceLeft = true;
				playerFaceRight = false;
				break;
			case SDLK_d:
				pVelX += PLAYER_VEL;
				playerFaceLeft = false;
				playerFaceRight = true;
				break;

			case SDLK_SPACE:
				if(player1.ammo > 0)
				{
					shot = true;
				}
				if(CURRENT_ROOM == TITLE)
				{
					CURRENT_ROOM = CREDITS;
				}
				else if(CURRENT_ROOM == CREDITS)
				{
					CURRENT_ROOM = INSTRUCTIONS;
				}
				else if(CURRENT_ROOM == INSTRUCTIONS)
				{
					CURRENT_ROOM = START;
				}
				else if(CURRENT_ROOM == WIN)
				{
					CURRENT_ROOM = TITLE;
				}
				else if(CURRENT_ROOM == LOSE)
				{
					CURRENT_ROOM = TITLE;
				}
				break;

			}
		}
		//Check if a key was released
		else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
		{
			switch( event.key.keysym.sym )
			{

			case SDLK_UP:
				//pVelY += PLAYER_VEL;
				break;
			case SDLK_DOWN:
				//pVelY -= PLAYER_VEL;
				break;
			case SDLK_LEFT:
				pVelX += PLAYER_VEL;
				break;
			case SDLK_RIGHT:
				pVelX -= PLAYER_VEL;
				break;

			case SDLK_w:
				//pVelY += PLAYER_VEL;
				break;
			case SDLK_s:
				//pVelY -= PLAYER_VEL;
				break;
			case SDLK_a:
				pVelX += PLAYER_VEL;
				break;
			case SDLK_d:
				pVelX -= PLAYER_VEL;
				break;

			case SDLK_SPACE:
				shot = false;
				break;

			}
		}
	}

	return inGame;
}

int main(int argc, char* argv[])
{
	// CREATE WINDOW START

	// Start SDL2
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create a SDL Window in the middle of the screen
	game1.window = SDL_CreateWindow("Robin Hood 2D",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024, 768,
		SDL_WINDOW_SHOWN);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);

	// Create an SDL RenderTarget
	game1.renderTarget = SDL_CreateRenderer(game1.window, -1, SDL_RENDERER_ACCELERATED);
	
	//CREATE WINDOW END

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

	//setup the health pickup
	healthPickup healthPickup1;
	healthPickup1.setup(game1);

	//setup the ammo pickup
	ammoPickup ammoPickup1;
	ammoPickup1.setup(game1);

	//setup the coin pickups
	coinPickup coinPickup1, coinPickup2, coinPickup3, coinPickup4, coinPickup5;
	coinPickup1.setup(game1);
	coinPickup2.setup(game1);
	coinPickup3.setup(game1);
	coinPickup4.setup(game1);
	coinPickup5.setup(game1);

	//create enemies
	turret turret1, turret2;
	turret1.setup(game1, 750, 525);
	turret2.setup(game1, 900, 525);
	enemy enemy1, enemy2, enemy3;
	enemy1.setup(game1, 700, 525);
	enemy2.setup(game1, 50, 525);
	enemy3.setup(game1, 50, 525);

	//setup decorations
	sign sign1;
	sign1.setup(game1);
	flower flowerArr[10];
	for(int i = 0; i < 10; i++)
	{
		flowerArr[i].setup(game1);
	}

	//set the wall and door locations
	gameRoom.walls(game1);


	// ******************* GAME LOOP - START *******************

	// While the loop is running
	while(game1.inGame)
	{

		//check for keyboard input
		game1.inGame = keyInput(game1.event, game1.inGame);


		// ******************* Start the SDL Draw Process *******************

			// Clear the SDL RenderTarget
			SDL_RenderClear(game1.renderTarget);

			if(!jumping)
			{
				pVelY += 10;
			}
			else
			{
				pVelY -= 10;
				jumpCount += 10;
				if(jumpCount >= 250)
				{
					jumping = false;
					jumpCount = 0;
				}
			}

			if (health >= 10)
			{
				health = 10;
			}
			if (health <= 0)
			{
				health = 0;
				lose = true;
			}
			if (player1.ammo >= 20)
			{
				player1.ammo = 20;
			}
			if (player1.ammo <= 0)
			{
				player1.ammo = 0;
			}
			if (coins >= 5)
			{
				coins = 5;
				win = true;
			}

			if(win == true)
			{
				CURRENT_ROOM = WIN;
				enemy1.setup(game1, 700, 525);
				enemy2.setup(game1, 50, 525);
				enemy3.setup(game1, 50, 525);
				turret1.setup(game1, 750, 525);
				turret2.setup(game1, 900, 525);
				player1.pos.x = 200;
				health = 10;
				player1.ammo = 20;
				coins = 0;
				coin1 = false;
				coin2 = false;
				coin3 = false;
				coin4 = false;
				coin5 = false;
				win = false;
			}
			if(lose == true)
			{
				CURRENT_ROOM = LOSE;
				enemy1.setup(game1, 700, 525);
				enemy2.setup(game1, 50, 525);
				enemy3.setup(game1, 50, 525);
				turret1.setup(game1, 750, 525);
				turret2.setup(game1, 900, 525);
				player1.pos.x = 200;
				health = 10;
				player1.ammo = 20;
				coins = 0;
				coin1 = false;
				coin2 = false;
				coin3 = false;
				coin4 = false;
				coin5 = false;
				lose = false;
			}

			if (SDL_HasIntersection(&player1.pos, &eBulletPos))
			{
				health--;
				turret1.resetBullet();
				eBulletPos = turret1.bulletPos;
				turret2.resetBullet();
				eBulletPos = turret2.bulletPos;
			}

			// MENU TITLE
			if (CURRENT_ROOM == TITLE)
			{
				gameRoom.draw(game1, CURRENT_ROOM);
			}
			// MENU CREDITS
			if (CURRENT_ROOM == CREDITS)
			{
				gameRoom.draw(game1, CURRENT_ROOM);
			}
			// MENU INSTRUCTIONS
			if (CURRENT_ROOM == INSTRUCTIONS)
			{
				gameRoom.draw(game1, CURRENT_ROOM);
			}
			// MENU WIN
			if (CURRENT_ROOM == WIN)
			{
				gameRoom.draw(game1, CURRENT_ROOM);
			}
			// MENU LOSE
			if (CURRENT_ROOM == LOSE)
			{
				gameRoom.draw(game1, CURRENT_ROOM);
			}

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
					canJump = true;
				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[0][0]))
				{
					CURRENT_ROOM = FIRST;
					player1.pos.x = 10;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
				}

				//draw decorations
				sign1.draw(game1, 900, 520);
				flowerArr[0].draw(game1, 50, 520);
				flowerArr[1].draw(game1, 300, 520);
				flowerArr[2].draw(game1, 600, 520);
			}

			//ROOM FIRST
			if (CURRENT_ROOM == FIRST)
			{
				//draw room
				gameRoom.draw(game1, CURRENT_ROOM);

				//draw health pickup
				healthPickup1.draw(game1, 200, 400);

				//draw ammo pickup
				ammoPickup1.draw(game1, 400, 400);

				//Move the player left or right
				player1.pos.x += pVelX;

				// Check for wall collisions - left or right
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[1][0]))
				{

					//Move back
					player1.pos.x -= pVelX;
				}

				//Move the player up or down
				player1.pos.y += pVelY;

				// Check for wall collisions - up or down
				if (SDL_HasIntersection(&player1.pos, &gameRoom.wall[1][0]))
				{

					//Move back
					player1.pos.y -= pVelY;
					canJump = true;
				}

				//draw enemy
				if(enemy1.health > 0)
				{
					enemy1.draw(game1, player1.pos.x);
					if (SDL_HasIntersection(&enemy1.pos, &pBulletPos) && enemy1.active == true)
					{
						enemy1.health--;
						player1.resetBullet();
					}
				}
				if (SDL_HasIntersection(&player1.pos, &enemy1.pos) && enemy1.health > 0)
				{
					health--;
					if(player1.pos.x > enemy1.pos.x)
					{
						enemy1.pos.x -= 50;
					}
					else
					{
						enemy1.pos.x += 50;
					}
				}
				if(enemy1.health <= 0 && coin1 == false)
				{
					//draw coin pickup
					coinPickup1.draw(game1, enemy1.pos.x, 550);
					// Check for coin pickup collisions
					if (SDL_HasIntersection(&player1.pos, &coinPickup1.pos))
					{
						coins += 1;
						coin1 = true;
					}
				}

				// Check for health pickup collisions
				if (SDL_HasIntersection(&player1.pos, &healthPickup1.pos))
				{
					health = 10;
				}

				// Check for ammo pickup collisions
				if (SDL_HasIntersection(&player1.pos, &ammoPickup1.pos))
				{
					player1.ammo = 20;
				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[1][1]))
				{
					CURRENT_ROOM = START;
					player1.pos.x = 950;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
				}
				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[1][0]))
				{
					CURRENT_ROOM = MID;
					player1.pos.x = 10;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
				}

				//draw decorations
				flowerArr[0].draw(game1, 100, 520);
				flowerArr[1].draw(game1, 300, 520);
				flowerArr[3].draw(game1, 600, 520);
				flowerArr[4].draw(game1, 700, 520);
				flowerArr[5].draw(game1, 900, 520);
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
					canJump = true;
				}

				//draw turret
				if (turret1.health > 0)
				{
					turret1.draw(game1, player1.pos.x);
					eBulletPos = turret1.shoot(game1);
					if (SDL_HasIntersection(&turret1.pos, &pBulletPos) && turret1.active == true)
					{
						turret1.health--;
						player1.resetBullet();
					}
				}
				if(turret1.health <= 0 && coin2 == false)
				{
					//draw coin pickup
					coinPickup2.draw(game1, turret1.pos.x, 550);
					// Check for coin pickup collisions
					if (SDL_HasIntersection(&player1.pos, &coinPickup2.pos))
					{
						coins += 1;
						coin2 = true;
					}
				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[2][0]))
				{
					CURRENT_ROOM = FIRST;
					player1.pos.x = 950;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
				}
				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[2][1]))
				{
					CURRENT_ROOM = LOWER;
					player1.pos.x = 900;
					player1.pos.y = 80;
					jumping = false;
					jumpCount = 0;
				}
				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[2][2]))
				{
					CURRENT_ROOM = UPPER;
					player1.pos.x = 620;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
				}

				//draw decorations
				flowerArr[0].draw(game1, 150, 520);
				flowerArr[1].draw(game1, 250, 520);
				flowerArr[3].draw(game1, 500, 520);
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
					canJump = true;
				}

				//draw enemy
				if(enemy2.health > 0)
				{
					enemy2.draw(game1, player1.pos.x);
					if (SDL_HasIntersection(&enemy2.pos, &pBulletPos) && enemy2.active == true)
					{
						enemy2.health--;
						player1.resetBullet();
					}
				}
				if (SDL_HasIntersection(&player1.pos, &enemy2.pos) && enemy2.health > 0)
				{
					health--;
					if(player1.pos.x > enemy2.pos.x)
					{
						enemy2.pos.x -= 50;
					}
					else
					{
						enemy2.pos.x += 50;
					}
				}
				if(enemy2.health <= 0 && coin3 == false)
				{
					//draw coin pickup
					coinPickup3.draw(game1, enemy2.pos.x, 550);
					// Check for coin pickup collisions
					if (SDL_HasIntersection(&player1.pos, &coinPickup3.pos))
					{
						coins += 1;
						coin3 = true;
					}
				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[3][0]))
				{
					CURRENT_ROOM = MID;
					player1.pos.x = 725;
					player1.pos.y = 515;
					jumping = false;
					jumpCount = 0;
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
					canJump = true;
				}

				//draw enemy
				if(enemy3.health > 0)
				{
					enemy3.draw(game1, player1.pos.x);
					if (SDL_HasIntersection(&enemy3.pos, &pBulletPos) && enemy3.active == true)
					{
						enemy3.health--;
						player1.resetBullet();
					}
				}
				if (SDL_HasIntersection(&player1.pos, &enemy3.pos) && enemy3.health > 0)
				{
					health--;
					if(player1.pos.x > enemy3.pos.x)
					{
						enemy3.pos.x -= 50;
					}
					else
					{
						enemy3.pos.x += 50;
					}
				}
				if(enemy3.health <= 0 && coin4 == false)
				{
					//draw coin pickup
					coinPickup4.draw(game1, enemy3.pos.x, 550);
					// Check for coin pickup collisions
					if (SDL_HasIntersection(&player1.pos, &coinPickup4.pos))
					{
						coins += 1;
						coin4 = true;
					}
				}

				//draw turret
				if (turret2.health > 0)
				{
					turret2.draw(game1, player1.pos.x);
					eBulletPos = turret2.shoot(game1);
					if (SDL_HasIntersection(&turret2.pos, &pBulletPos) && turret2.active == true)
					{
						turret2.health--;
						player1.resetBullet();
					}
				}
				if(turret2.health <= 0 && coin5 == false)
				{
					//draw coin pickup
					coinPickup5.draw(game1, turret2.pos.x, 550);
					// Check for coin pickup collisions
					if (SDL_HasIntersection(&player1.pos, &coinPickup5.pos))
					{
						coins += 1;
						coin5 = true;
					}
				}

				if (SDL_HasIntersection(&player1.pos, &gameRoom.door[4][0]))
				{
					CURRENT_ROOM = MID;
					player1.pos.x = 475;
					player1.pos.y = 75;
					jumping = false;
					jumpCount = 0;
				}

				//draw decorations
				flowerArr[0].draw(game1, 80, 520);
				flowerArr[1].draw(game1, 400, 520);
				flowerArr[3].draw(game1, 700, 520);
				flowerArr[4].draw(game1, 850, 520);
				flowerArr[5].draw(game1, 900, 520);
			}

			if (CURRENT_ROOM < 6)
			{
				//update player
				if (playerFaceRight == true)
				{
					player1.draw_rightFacing(game1, shot);
				}
				if (playerFaceLeft == true)
				{
					player1.draw_leftFacing(game1, shot);
				}
				pBulletPos = player1.shoot(game1);

				//update health GUI
				healthGUI1.draw(game1, health);

				//update ammo GUI
				ammoGUI1.draw(game1, player1.ammo);

				//update inventory GUI
				coinGUI1.draw(game1, coins);
			}

			pVelY = 0;

			// Draw "Present" the SDL RenderTarget to the user
			SDL_RenderPresent(game1.renderTarget);

		// ******************* End the SDL Draw Process *******************


		// Delay so that we are at 60 FPS
		SDL_Delay(16);

	}

	// ******************* GAME LOOP - END *******************

    // Cleanup and Quit
	SDL_DestroyWindow(game1.window);
    SDL_Quit();

    return 0;
}
