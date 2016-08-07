//Joshua Alexander

#include "player.h"

void player::setup(game game1)
{
	game1.surface = IMG_Load("RobinHood_2D/image/player_right.png");
	texture1 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/player_left.png");
	texture2 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/bullet_right.png");
	bulletTexture1 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);

	game1.surface = IMG_Load("RobinHood_2D/image/bullet_left.png");
	bulletTexture2 = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
	SDL_FreeSurface(game1.surface);
}

void player::draw_rightFacing(game game1, bool shot)
{
	SDL_RenderCopy(game1.renderTarget, texture1, NULL, &pos);

	int random_number = rand() % 50;

	if ((bulletActive) == false && (shot == true))
	{
		// move to player's position
		bulletPos.x = pos.x;
		bulletPos.y = (pos.y + 55);

		bulletDir = 5;
		bulletFacing = "right";

		// active bullet
		bulletActive = true;
		shot = false;
		ammo--;
	}
}

void player::draw_leftFacing(game game1, bool shot)
{
	SDL_RenderCopy(game1.renderTarget, texture2, NULL, &pos);

	if ((bulletActive) == false && (shot == true))
	{
		// move to player's position
		bulletPos.x = pos.x;
		bulletPos.y = (pos.y + 55);

		bulletDir = -5;
		bulletFacing = "left";

		// active bullet
		bulletActive = true;
		shot = false;
		ammo--;
	}
}

SDL_Rect player::shoot(game game1)
{
	//if the enemy bullet is active - update
	if (bulletActive) 
	{
		bulletPos.x += bulletDir;
	}

	// check for off screen - LEFT or RIGHT
	if (bulletPos.x > 1024 || bulletPos.x < 0) 
	{
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

void player::resetBullet()
{
	bulletPos.x = -200;
	bulletPos.y = -200;
}
