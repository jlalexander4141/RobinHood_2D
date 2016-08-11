//Joshua Alexander

#include "decor.h"

void sign::setup(game game1)
{
	game1.surface = IMG_Load("RobinHood_2D/image/sign.png");
	texture = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);
}

void sign::draw(game game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;

	SDL_RenderCopy(game1.renderTarget, texture, NULL, &pos);
}

void flower::setup(game game1)
{
	game1.surface = IMG_Load("RobinHood_2D/image/flower.png");
	texture = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);
}

void flower::draw(game game1, int posX, int posY)
{
	pos.x = posX;
	pos.y = posY;

	SDL_RenderCopy(game1.renderTarget, texture, NULL, &pos);
}
