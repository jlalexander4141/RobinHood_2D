//Joshua Alexander

#include "room.h"

void room::setup(game game1)
{
	// ROOM START
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomStart.png");
	// Load Room PNG to a SDL Texture
	texture[0] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	// ROOM START
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomFirst.png");
	// Load Room PNG to a SDL Texture
	texture[5] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	// ROOM FIRST
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomStart.png");
	// Load Room PNG to a SDL Texture
	texture[1] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//ROOM MID
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomMid.png");
	// Load Room PNG to a SDL Texture
	texture[02] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//ROOM LOWER
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomLower.png");
	// Load Room PNG to a SDL Texture
	texture[3] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//ROOM UPPER
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/roomUpper.png");
	// Load Room PNG to a SDL Texture
	texture[4] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//MENU TITLE
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/menu_title.png");
	// Load Room PNG to a SDL Texture
	texture[6] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//MENU CREDITS
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/menu_credits.png");
	// Load Room PNG to a SDL Texture
	texture[7] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//MENU INSTRUCTIONS
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/menu_instructions.png");
	// Load Room PNG to a SDL Texture
	texture[8] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//MENU WIN
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/menu_win.png");
	// Load Room PNG to a SDL Texture
	texture[9] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);

	//MENU LOSE
	// Load Room PNG to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/menu_lose.png");
	// Load Room PNG to a SDL Texture
	texture[10] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL game1.surface for later use
	SDL_FreeSurface(game1.surface);
}

void room::draw(game game1, int currentRoom)
{
	SDL_RenderCopy(game1.renderTarget, texture[currentRoom], NULL, &pos);
}

void room::walls(game game1)
{
	// DOORS
	// Set the x, y, width and height SDL Rectangle values
	door[0][0].x = 1024;
	door[0][0].y = 0;
	door[0][0].w = 1;
	door[0][0].h = 768;

	// Set the x, y, width and height SDL Rectangle values
	door[1][0].x = 1024;
	door[1][0].y = 0;
	door[1][0].w = 1;
	door[1][0].h = 768;

	// Set the x, y, width and height SDL Rectangle values
	door[1][1].x = 0;
	door[1][1].y = 0;
	door[1][1].w = 1;
	door[1][1].h = 768;

	// Set the x, y, width and height SDL Rectangle values
	door[2][0].x = 0;
	door[2][0].y = 0;
	door[2][0].w = 1;
	door[2][0].h = 768;

	// Set the x, y, width and height SDL Rectangle values
	door[2][1].x = 845;
	door[2][1].y = 768;
	door[2][1].w = 200;
	door[2][1].h = 1;

	// Set the x, y, width and height SDL Rectangle values
	door[2][2].x = 470;
	door[2][2].y = 0;
	door[2][2].w = 200;
	door[2][2].h = 1;

	// Set the x, y, width and height SDL Rectangle values
	door[3][0].x = 845;
	door[3][0].y = 0;
	door[3][0].w = 200;
	door[3][0].h = 1;

	// Set the x, y, width and height SDL Rectangle values
	door[4][0].x = 470;
	door[4][0].y = 768;
	door[4][0].w = 200;
	door[4][0].h = 1;

	// ROOM START
	// Set the x, y, width and height SDL Rectangle values
	wall[0][0].x = 0;
	wall[0][0].y = 0;
	wall[0][0].w = 35;
	wall[0][0].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[0][1].x = 0;
	wall[0][1].y = 655;
	wall[0][1].w = 1024;
	wall[0][1].h = 10;

	// ROOM FIRST
	// Set the x, y, width and height SDL Rectangle values
	wall[1][0].x = 0;
	wall[1][0].y = 655;
	wall[1][0].w = 1024;
	wall[1][0].h = 10;

	// ROOM MID
	// Set the x, y, width and height SDL Rectangle values
	wall[2][0].x = 990;
	wall[2][0].y = 0;
	wall[2][0].w = 10;
	wall[2][0].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[2][1].x = 0;
	wall[2][1].y = 655;
	wall[2][1].w = 845;
	wall[2][1].h = 10;
	// Set the x, y, width and height SDL Rectangle values
	wall[2][2].x = 722;
	wall[2][2].y = 433;
	wall[2][2].w = 300;
	wall[2][2].h = 30;
	// Set the x, y, width and height SDL Rectangle values
	wall[2][3].x = 430;
	wall[2][3].y = 220;
	wall[2][3].w = 290;
	wall[2][3].h = 30;
	// Set the x, y, width and height SDL Rectangle values
	wall[2][4].x = 430;
	wall[2][4].y = 0;
	wall[2][4].w = 37;
	wall[2][4].h = 220;
	// Set the x, y, width and height SDL Rectangle values
	wall[2][5].x = 615;
	wall[2][5].y = 0;
	wall[2][5].w = 500;
	wall[2][5].h = 35;

	// ROOM LOWER
	// Set the x, y, width and height SDL Rectangle values
	wall[3][0].x = 0;
	wall[3][0].y = 0;
	wall[3][0].w = 35;
	wall[3][0].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[3][1].x = 990;
	wall[3][1].y = 0;
	wall[3][1].w = 35;
	wall[3][1].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[3][2].x = 0;
	wall[3][2].y = 655;
	wall[3][2].w = 1024;
	wall[3][2].h = 10;
	// Set the x, y, width and height SDL Rectangle values
	wall[3][3].x = 0;
	wall[3][3].y = 0;
	wall[3][3].w = 845;
	wall[3][3].h = 35;
	// Set the x, y, width and height SDL Rectangle values
	wall[3][4].x = 775;
	wall[3][4].y = 218;
	wall[3][4].w = 500;
	wall[3][4].h = 500;
	// Set the x, y, width and height SDL Rectangle values
	wall[3][5].x = 560;
	wall[3][5].y = 433;
	wall[3][5].w = 500;
	wall[3][5].h = 500;

	// ROOM UPPER
	// Set the x, y, width and height SDL Rectangle values
	wall[4][0].x = 0;
	wall[4][0].y = 0;
	wall[4][0].w = 35;
	wall[4][0].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[4][1].x = 990;
	wall[4][1].y = 0;
	wall[4][1].w = 35;
	wall[4][1].h = 768;
	// Set the x, y, width and height SDL Rectangle values
	wall[4][2].x = 0;
	wall[4][2].y = 655;
	wall[4][2].w = 470;
	wall[4][2].h = 10;
	// Set the x, y, width and height SDL Rectangle values
	wall[4][3].x = 615;
	wall[4][3].y = 655;
	wall[4][3].w = 500;
	wall[4][3].h = 10;
}
