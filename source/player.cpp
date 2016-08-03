//Joshua Alexander

#include "player.h"

void player::setup(game *game1)
{
	// Load Room BITMAP to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/player.png");
	// Load Room BITMAP to a SDL Texture
	playerTexture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	// Set the x, y, width and height SDL Rectangle values
	playerPos.x = 200;
	playerPos.y = 515;
	playerPos.w = 64;
	playerPos.h = 128;
	//Release the SDL surface for later use
	SDL_FreeSurface(surface);
}

void player::draw(game *game1)
{

}
