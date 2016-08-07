//Joshua Alexander

#ifndef _hud_h
#define _hud_h

#include "game.h"

class hud
{
public:
	//variables
	SDL_Texture *texture[21];

	hud()
	{
		for (int i = 0; i < 20; i++)
		{
			texture[i] = nullptr;
		}
	}
};

class healthGUI : hud
{
public:
	SDL_Rect pos;

	healthGUI()
	{
		pos.x = 10;
		pos.y = 10;
		pos.w = 368;
		pos.h = 44;
	}

	void setup(game game1);
	void draw(game game1, int health);
};

class ammoGUI : hud
{
public:
	SDL_Rect pos;

	ammoGUI()
	{
		pos.x = 10;
		pos.y = 50;
		pos.w = 367;
		pos.h = 51;
	}

	void setup(game game1);
	void draw(game game1, int ammo);
};

class coinGUI : hud
{
public:
	SDL_Rect pos;

	coinGUI()
	{
		pos.x = 710;
		pos.y = 10;
		pos.w = 307;
		pos.h = 117;
	}

	void setup(game game1);
	void draw(game game1, int coins);
};

#endif
