/*
 * room.h
 *
 *  Created on: Jul 26, 2016
 *      Author: joshuaalexander
 */

#ifndef _ROOM_H_
#define _ROOM_H_

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

class room
{
public:
	room();
	~room();
	void setup();
	void display();
};

#endif /* _ROOM_H_ */
