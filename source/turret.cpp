//Joshua Alexander

#include "turret.h"

void turret::setup(game game1, int posX, int posY)
{
	game1.surface = IMG_Load("RobinHood_2D/image/turret_right.png");
	texture1 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/turret_left.png");
	texture2 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	pos.x = posX;
	pos.y = posY;

	game1.surface = IMG_Load("RobinHood_2D/image/bullet_right.png");
	bulletTexture1 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/bullet_left.png");
	bulletTexture2 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);
}

void turret::draw(game game1, int playerPosX)
{
	if (playerPosX > pos.x)
	{
		SDL_RenderCopy(game1.renderTarget, texture1, NULL, &pos);
	}
	if (playerPosX < pos.x)
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

		int random_number = rand() % 50;

		if ((bulletActive) == false && (random_number == 5))
		{
			// move to player's position
			bulletPos.x = pos.x;
			bulletPos.y = (pos.y + 55);

			// check to see if the player is to the left or right of the turret and set the
			// player's bulletDir as needed
			if (playerPosX < pos.x)
			{
				bulletDir = -5;
				bulletFacing = "left";
			}
			else 
			{
				bulletDir = 5;
				bulletFacing = "right";
			}
			// active bullet
			bulletActive = true;
		}
	}
	else 
	{
		active = false;
	}
}

SDL_Rect turret::shoot(game game1)
{
	//if the enemy bullet is active - update
	if (bulletActive) {
		bulletPos.x += bulletDir;
	}

	// check for off screen - LEFT or RIGHT
	if (bulletPos.x > 1024 || bulletPos.x < 0) {
		bulletActive = false;
		bulletPos.x = -200;
		bulletPos.y = -200;
		bulletDir = 0;
	}

	if (bulletActive)
	{
		if (bulletFacing == "right")
		{
			SDL_RenderCopy(game1.renderTarget, bulletTexture1, NULL, &bulletPos);
		}
		if (bulletFacing == "left")
		{
			SDL_RenderCopy(game1.renderTarget, bulletTexture2, NULL, &bulletPos);
		}
	}

	return bulletPos;
}

void turret::resetBullet()
{
	bulletPos.x = -200;
	bulletPos.y = -200;
}
