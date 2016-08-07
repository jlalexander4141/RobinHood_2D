//Joshua Alexander

#ifndef _pickup_h
#define _pickup_h

#include "game.h"

class pickup
{
public:
	//variables
	SDL_Texture *texture;

	pickup()
	{
		texture = nullptr;
	}
};

class healthPickup : pickup
{
public:
	SDL_Rect pos;

	healthPickup()
	{
		pos.x = 0;
		pos.y = 0;
		pos.w = 64;
		pos.h = 64;
	}

	void setup(game game1);
	void draw(game game1, int posX, int posY);
};

class ammoPickup : pickup
{
public:
	SDL_Rect pos;

	ammoPickup()
	{
		pos.x = 0;
		pos.y = 0;
		pos.w = 64;
		pos.h = 64;
	}

	void setup(game game1);
	void draw(game game1, int posX, int posY);
};

class coinPickup : pickup
{
public:
	SDL_Rect pos;

	coinPickup()
	{
		pos.x = 0;
		pos.y = 0;
		pos.w = 64;
		pos.h = 64;
	}

	void setup(game game1);
	void draw(game game1, int posX, int posY);
};

#endif
