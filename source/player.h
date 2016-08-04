//Joshua Alexander

#ifndef _player_h
#define _player_h

#include "game.h"

class player
{
public:
	//variables
	SDL_Texture *texture;
	SDL_Rect pos;
	const int PLAYER_VEL = 5;
	int pVelX;
	int pVelY;

	//functions
	player()
	{
		texture = nullptr;
		pos.x = 200;
		pos.y = 515;
		pos.w = 64;
		pos.h = 128;
		pVelX = 0;
		pVelY = 0;
	}
	~player();
	void setup(game *game1);
	void draw(game *game1);
};

#endif
