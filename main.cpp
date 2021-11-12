#ifndef __SDL_H__
#define __SDL_H__
#include "SDL.h"
#endif
#ifndef __SDL_image_h__
#define __SDL_image_h__
#include "SDL_image.h"
#endif
#include <iostream>

#include "Sprite.cpp"

#define FPS 60
#define TITLE "2DGame"
#define WIDTH 800
#define HEIGHT 600

int main(int argc, char *argv[]) {
	// Run necessary init for SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	// Load a window
	SDL_Window* window;
	window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (window == NULL)
		std::cerr << "SDL window failed to load" << std::endl << "^ Error: " << SDL_GetError() << std::endl;

	SDL_Surface* screen = SDL_GetWindowSurface(window);
	Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);

	/* 
	 * Create sprites here and push them to allSprites vector
	 * Push from back to front, (ex. background, then foreground)
	 */

	// Main loop
	SDL_Event event;
	Uint32 startingTick;
	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();

		/*
		 * Draw on the screen
		 */

		// Clear the screen
		SDL_FillRect(screen, NULL, black);

		// Update and draw each sprite
		for (Sprite* spritePtr : allSprites) {
			spritePtr->update();
			spritePtr->draw(screen);
		}

		// Update screen
		SDL_UpdateWindowSurface(window);

		/*
		 * Poll for events
		 */

		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				// https://wiki.libsdl.org/SDL_Event
				case SDL_QUIT:
					running = false;
					break;
			}
		}

		// Enforce frame rate limit
		if ((1000 / FPS) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
		}
	}

	// Quit and cleaup
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}
