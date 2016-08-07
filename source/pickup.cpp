//Joshua Alexander

#include "pickup.h"

void healthPickup::setup(game game1)
{
	// Load Room BITMAP to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/healthPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL surface for later use
	SDL_FreeSurface(game1.surface);
}

void healthPickup::draw(game game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1.renderTarget, texture, NULL, &pos);
}

void ammoPickup::setup(game game1)
{
	// Load Room BITMAP to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/ammoPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL surface for later use
	SDL_FreeSurface(game1.surface);
}

void ammoPickup::draw(game game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1.renderTarget, texture, NULL, &pos);
}

void coinPickup::setup(game game1)
{
	// Load Room BITMAP to a SDL Surface
	game1.surface = IMG_Load("RobinHood_2D/image/coinPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	//Release the SDL surface for later use
	SDL_FreeSurface(game1.surface);
}

void coinPickup::draw(game game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1.renderTarget, texture, NULL, &pos);
}
