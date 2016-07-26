/*
 * player.h
 *
 *  Created on: Jul 26, 2016
 *      Author: joshuaalexander
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

//include SDL on windows
#if defined(_WIN32) || (_WIN64)
#include "SDL.h"
#endif
//include SDL on mac
#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#endif

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class player
{
public:

	player();
	~player();
	void displayPlayer();
};

#endif /* _PLAYER_H_ */
