//Joshua Alexander

#ifndef _turret_h
#define _turret_h

#include "game.h"

class turret
{
public:
	//variables
	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Texture *bulletTexture1;
	SDL_Texture *bulletTexture2;
	SDL_Rect pos;
	SDL_Rect bulletPos;
	bool active;
	bool bulletActive;
	int bulletDir;
	string bulletFacing;
	int health;

	turret()
	{
		texture1 = nullptr;
		texture2 = nullptr;
		bulletTexture1 = nullptr;
		bulletTexture2 = nullptr;
		pos.w = 64;
		pos.h = 128;
		bulletPos.x = -200;
		bulletPos.y = -200;
		bulletPos.w = 32;
		bulletPos.h = 7;
		active = false;
		bulletActive = true;
		bulletDir = 0;
		bulletFacing = "right";
		health = 5;
	}

	void setup(game game1, int posX, int posY);
	void draw(game game1, int playerPosX);
	SDL_Rect shoot(game game1);
	void resetBullet();
};

#endif
