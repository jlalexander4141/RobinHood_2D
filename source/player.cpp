//Joshua Alexander

#include "player.h"

void player::setup(game *game1)
{
	// Load Room PNG to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/player.png");
	// Load Room PNG to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	//Release the SDL surface for later use
	SDL_FreeSurface(surface);
}

void player::draw(game *game1)
{
	SDL_RenderCopy(game1->renderTarget, texture, NULL, &pos);
}
