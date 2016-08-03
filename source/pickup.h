//Joshua Alexander

#include "game.h"

class pickup
{
public:
	//variables
	SDL_Texture *texture;
	SDL_Rect pickupPos;

	pickup()
	{
		texture = nullptr;
		pickupPos.w = 64;
		pickupPos.h = 64;
	}
};

class healthPickup : pickup
{
public:

	healthPickup();

	void setup(game *game1, int posX, int posY);
	void draw(game *game1);
};

class ammoPickup : pickup
{
public:

	ammoPickup();

	void setup(game *game1, int posX, int posY);
	void draw(game *game1);
};

class coinPickup : pickup
{
public:

	coinPickup();

	void setup(game *game1, int posX, int posY);
	void draw(game *game1);
};
