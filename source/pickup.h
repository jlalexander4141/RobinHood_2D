//Joshua Alexander

#include "game.h"

class pickup
{
public:
	//variables
	SDL_Texture *texture;
	SDL_Rect pos;

	pickup()
	{
		texture = nullptr;
		pos.x = 0;
		pos.y = 0;
		pos.w = 64;
		pos.h = 64;
	}
};

class healthPickup : pickup
{
public:

	healthPickup();

	void setup(game *game1);
	void draw(game *game1, int posX, int posY);
};

class ammoPickup : pickup
{
public:

	ammoPickup();

	void setup(game *game1);
	void draw(game *game1, int posX, int posY);
};

class coinPickup : pickup
{
public:

	coinPickup();

	void setup(game *game1);
	void draw(game *game1, int posX, int posY);
};
