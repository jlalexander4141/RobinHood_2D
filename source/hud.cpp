//Joshua Alexander

#include "hud.h"

void healthGUI::setup(game *game1)
{
	for(int i = 0; i <= 10; i++)
	{
		if(i == 0)
			game1->surface = IMG_Load("RobinHood_2D/image/health00.png");
		else if(i == 1)
			game1->surface = IMG_Load("RobinHood_2D/image/health01.png");
		else if(i == 2)
			game1->surface = IMG_Load("RobinHood_2D/image/health02.png");
		else if(i == 3)
			game1->surface = IMG_Load("RobinHood_2D/image/health03.png");
		else if(i == 4)
			game1->surface = IMG_Load("RobinHood_2D/image/health04.png");
		else if(i == 5)
			game1->surface = IMG_Load("RobinHood_2D/image/health05.png");
		else if(i == 6)
			game1->surface = IMG_Load("RobinHood_2D/image/health06.png");
		else if(i == 7)
			game1->surface = IMG_Load("RobinHood_2D/image/health07.png");
		else if(i == 8)
			game1->surface = IMG_Load("RobinHood_2D/image/health08.png");
		else if(i == 9)
			game1->surface = IMG_Load("RobinHood_2D/image/health09.png");
		else if(i == 10)
			game1->surface = IMG_Load("RobinHood_2D/image/health10.png");

		texture[i] = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);

		SDL_FreeSurface(game1->surface);
	}
}

void healthGUI::draw(game *game1, int health)
{
	SDL_RenderCopy(game1->renderTarget, texture[health], NULL, &pos);
}

void ammoGUI::setup(game *game1)
{
	for(int i = 0; i <= 20; i++)
	{
		if(i == 0)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo00.png");
		else if(i == 1)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo01.png");
		else if(i == 2)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo02.png");
		else if(i == 3)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo03.png");
		else if(i == 4)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo04.png");
		else if(i == 5)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo05.png");
		else if(i == 6)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo06.png");
		else if(i == 7)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo07.png");
		else if(i == 8)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo08.png");
		else if(i == 9)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo09.png");
		else if(i == 10)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo10.png");
		else if(i == 11)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo11.png");
		else if(i == 12)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo12.png");
		else if(i == 13)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo13.png");
		else if(i == 14)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo14png");
		else if(i == 15)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo15.png");
		else if(i == 16)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo16.png");
		else if(i == 17)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo17.png");
		else if(i == 18)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo18.png");
		else if(i == 19)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo19.png");
		else if(i == 20)
			game1->surface = IMG_Load("RobinHood_2D/image/ammo20.png");

		texture[i] = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);

		SDL_FreeSurface(game1->surface);
	}
}

void ammoGUI::draw(game *game1, int ammo)
{
	SDL_RenderCopy(game1->renderTarget, texture[ammo], NULL, &pos);
}

void coinGUI::setup(game *game1)
{
	for(int i = 0; i <= 10; i++)
	{
		if(i == 0)
			game1->surface = IMG_Load("RobinHood_2D/image/coins0.png");
		else if(i == 1)
			game1->surface = IMG_Load("RobinHood_2D/image/coins1.png");
		else if(i == 2)
			game1->surface = IMG_Load("RobinHood_2D/image/coins2.png");
		else if(i == 3)
			game1->surface = IMG_Load("RobinHood_2D/image/coins3.png");
		else if(i == 4)
			game1->surface = IMG_Load("RobinHood_2D/image/coins4.png");
		else if(i == 5)
			game1->surface = IMG_Load("RobinHood_2D/image/coins5.png");

		texture[i] = SDL_CreateTextureFromSurface(game1->renderTarget, game1->surface);

		SDL_FreeSurface(game1->surface);
	}
}

void coinGUI::draw(game *game1, int coins)
{
	SDL_RenderCopy(game1->renderTarget, texture[coins], NULL, &pos);
}
