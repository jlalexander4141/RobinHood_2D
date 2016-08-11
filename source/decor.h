//Joshua Alexander

#ifndef _decor_h
#define _decor_h

#include "game.h"

class decor
{
public:
	SDL_Texture *texture;
	SDL_Rect pos;

	decor()
	{
		texture = nullptr;
		pos.h = 128;
		pos.w = 64;
	}
};

class sign : decor
{
public:

	void setup(game game1);
	void draw(game game1, int posX, int posY);
};

class flower : decor
{
public:

	void setup(game game1);
	void draw(game game1, int posX, int posY);
};

#endif
