#include "Sprite.hpp"

Sprite::Sprite(const char imageFilePath[], int x, int y, int w, int h) {
	// Create the surface
	if (imageFilePath != NULL)
		image = IMG_Load(imageFilePath);
	else
		image = IMG_Load(MISSING_TEXTURE_PATH);
	if (image == NULL) {
		image = IMG_Load(MISSING_TEXTURE_PATH);
		std::cerr << "Problem loading sprite at path=" << imageFilePath << std::endl << "^ Error: " << SDL_GetError() << std::endl;
	}

	originX = 0;
	originY = 0;

	rect = image->clip_rect;

	// Offsets
	rect.x = x - originX;
	rect.y = y - originY;
}

Sprite::~Sprite() {
	SDL_FreeSurface(image);
}

void Sprite::draw(SDL_Surface* destination) {
	SDL_BlitSurface(image, NULL, destination, &rect);
}

void Sprite::setPos(int newX, int newY) {
	rect.x = newX - originX;
	rect.y = newY - originY;
}

void Sprite::update() {} // Override this!