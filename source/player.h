//Joshua Alexander

#ifndef _player_h
#define _player_h

#include "game.h"

class player
{
public:
	//variables
	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Texture *bulletTexture1;
	SDL_Texture *bulletTexture2;
	const int PLAYER_VEL = 5;
	int pVelX;
	int pVelY;
	SDL_Rect pos;
	SDL_Rect bulletPos;
	bool bulletActive;
	int bulletDir;
	string bulletFacing;
	int ammo;

	//functions
	player()
	{
		texture1 = nullptr;
		texture2 = nullptr;
		bulletTexture1 = nullptr;
		bulletTexture2 = nullptr;
		pos.x = 200;
		pos.y = 515;
		pos.w = 64;
		pos.h = 128;
		pVelX = 0;
		pVelY = 0;
		bulletPos.x = -200;
		bulletPos.y = -200;
		bulletPos.w = 32;
		bulletPos.h = 7;
		bulletActive = true;
		bulletDir = 0;
		bulletFacing = "right";
		ammo = 20;
	}

	void setup(game game1);
	void draw_rightFacing(game game1, bool shot);
	void draw_leftFacing(game game1, bool shot);
	SDL_Rect shoot(game game1);
	void resetBullet();
};

#endif
