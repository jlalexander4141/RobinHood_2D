//Joshua Alexander

#ifndef _player_h
#define _player_h

#include "game.h"

class player
{
public:
	//variables
	const int PLAYER_VEL = 5;
	int pVelX;
	int pVelY;

	//functions
	player()
	{
		pVelX = 0;
		pVelY = 0;
	}
	~player();
	void setup(game *game1);
	void draw(game *game1);
};

#endif
