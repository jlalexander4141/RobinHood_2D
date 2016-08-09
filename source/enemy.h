//Joshua Alexander

#ifndef _enemy_h
#define _enemy_h

#include "game.h"

class enemy
{
public:
	//variables
	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Rect pos;
	bool active;
	int health;

	enemy()
	{
		texture1 = nullptr;
		texture2 = nullptr;
		pos.w = 64;
		pos.h = 128;
		active = false;
		health = 5;
	}

	void setup(game game1, int posX, int posY);
	void draw(game game1, int playerPosX);
};

#endif
