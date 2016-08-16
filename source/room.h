//Joshua Alexander

#ifndef _room_h
#define _room_h

#include "game.h"

class room
{
public:
	//variables
	SDL_Texture *texture[12];
	SDL_Rect pos;
	SDL_Rect wall[5][6];
	SDL_Rect door[5][3];

	room()
	{
		for (int i = 0; i < 12; i++)
		{
			texture[i] = nullptr;
		}
		pos.x = 0;
		pos.y = 0;
		pos.w = 1024;
		pos.h = 768;
	}

	void setup(game game1);
	void draw(game game1, int currentRoom);
	void walls(game game1);
};

#endif
