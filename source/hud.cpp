//Joshua Alexander

#include "hud.h"

void healthGUI::setup(game game1)
{
	for (int i = 0; i <= 10; i++)
	{
		if (i == 0)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health00.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 1)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health01.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 2)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health02.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 3)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health03.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 4)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health04.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 5)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health05.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 6)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health06.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 7)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health07.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 8)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health08.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 9)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health09.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 10)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/health10.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
	}
}

void healthGUI::draw(game game1, int health)
{
	if (health <= 0)
	{
		SDL_RenderCopy(game1.renderTarget, texture[0], NULL, &pos);
	}
	else
	{
		SDL_RenderCopy(game1.renderTarget, texture[health], NULL, &pos);
	}
}

void ammoGUI::setup(game game1)
{
	for (int i = 0; i <= 20; i++)
	{
		if (i == 0)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo00.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 1)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo01.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 2)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo02.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 3)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo03.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 4)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo04.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 5)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo05.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 6)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo06.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 7)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo07.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 8)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo08.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 9)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo09.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 10)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo10.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 11)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo11.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 12)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo12.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 13)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo13.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 14)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo14.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 15)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo15.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 16)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo16.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 17)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo17.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 18)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo18.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 19)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo19.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if(i == 20)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/ammo20.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
	}
}

void ammoGUI::draw(game game1, int ammo)
{
	SDL_RenderCopy(game1.renderTarget, texture[ammo], NULL, &pos);
}

void coinGUI::setup(game game1)
{
	for (int i = 0; i <= 10; i++)
	{
		if (i == 0)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins0.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 1)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins1.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 2)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins2.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 3)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins3.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 4)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins4.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
		else if (i == 5)
		{
			game1.surface = IMG_Load("RobinHood_2D/image/coins5.png");
			texture[i] = SDL_CreateTextureFromSurface(game1.renderTarget, game1.surface);
			SDL_FreeSurface(game1.surface);
		}
	}
}

void coinGUI::draw(game game1, int coins)
{
	SDL_RenderCopy(game1.renderTarget, texture[coins], NULL, &pos);
}
