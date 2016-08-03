//Joshua Alexander

#include "game.h"

class hud
{
public:

	hud();
};

class healthGUI : hud
{
public:

	healthGUI();

	void setup(game *game);
};

class ammoGUI : hud
{
public:

	ammoGUI();
};

class coinGUI : hud
{
public:

	coinGUI();
};
