#pragma once

#include <vector>
#include <iostream>

#ifndef __SDL_H__
#define __SDL_H__
#include "SDL.h"
#endif
#ifndef __SDL_image_h__
#define __SDL_image_h__
#include "SDL_image.h"
#endif

#define MISSING_TEXTURE_PATH "textures\\missing.png"

class Sprite {
private:
	SDL_Surface* image;
	SDL_Rect rect;
	int originX, originY;
public:
	Sprite(const char imageFilePath[], int x, int y, int w = 48, int h = 64);
	~Sprite();
	void update(); // Can be overridden
	void draw(SDL_Surface* destination);
	void setPos(int newX, int newY);
};

std::vector<Sprite*> allSprites;