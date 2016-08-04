//Joshua Alexander

#include "pickup.h"

void healthPickup::setup(game *game1, int posX, int posY)
{
	// Load Room BITMAP to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/healthPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	//Release the SDL surface for later use
	SDL_FreeSurface(surface);
}

void healthPickup::draw(game *game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1->renderTarget, texture, NULL, &pos);
}

void ammoPickup::setup(game *game1, int posX, int posY)
{
	// Load Room BITMAP to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/healthPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	// Set the x, y, width and height SDL Rectangle values
	pos.x = posX;
	pos.y = posY;
	//Release the SDL surface for later use
	SDL_FreeSurface(surface);
}

void ammoPickup::draw(game *game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1->renderTarget, texture, NULL, &pos);
}

void coinPickup::setup(game *game1, int posX, int posY)
{
	// Load Room BITMAP to a SDL Surface
	game1->surface = IMG_Load("RobinHood_2D/image/healthPickup.png");
	// Load Room BITMAP to a SDL Texture
	texture = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);
	// Set the x, y, width and height SDL Rectangle values
	pos.x = posX;
	pos.y = posY;
	//Release the SDL surface for later use
	SDL_FreeSurface(surface);
}

void coinPickup::draw(game *game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;
	SDL_RenderCopy(game1->renderTarget, texture, NULL, &pos);
}
