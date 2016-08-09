//Joshua Alexander

#include "enemy.h"

void enemy::setup(game game1, int posX, int posY)
{
	game1.surface = IMG_Load("RobinHood_2D/image/turret_right.png");
	texture1 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/turret_left.png");
	texture2 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	pos.x = posX;
	pos.y = posY;
}

void enemy::draw(game game1, int playerPosX)
{
	if (playerPosX > pos.x)
	{
		SDL_RenderCopy(game1.renderTarget, texture1, NULL, &pos);
	}
	else
	{
		SDL_RenderCopy(game1.renderTarget, texture2, NULL, &pos);
	}

	double distancex = ((pos.x + (pos.w / 2))
		- (playerPosX + 32))
		* ((pos.x + 32)
		- (playerPosX + 32));

	double calcdistance = sqrt(distancex);

	if (calcdistance <= 500)
	{
		active = true;

		if(playerPosX > pos.x)
		{
			pos.x +=  3;
		}
		else
		{
			pos.x -= 3;
		}
	}
	else
	{
		active = false;
	}
}
