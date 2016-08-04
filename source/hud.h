//Joshua Alexander

#include "game.h"

class hud
{
public:
	//variables
	SDL_Rect pos;
	SDL_Texture *texture[20];

	hud();
};

class healthGUI : hud
{
public:

	healthGUI()
	{
		pos.x = 10;
		pos.y = 10;
		pos.w = 368;
		pos.h = 44;
	}

	void setup(game *game);
	void draw(game *game1, int health);
};

class ammoGUI : hud
{
public:

	ammoGUI();

	void setup(game *game);
	void draw(game *game1, int ammo);
};

class coinGUI : hud
{
public:

	coinGUI();

	void setup(game *game);
	void draw(game *game1, int coins);
};
