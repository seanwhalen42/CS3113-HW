
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "main.h"

SDL_Window* displayWindow;

void drawNet() {
	float net[8] = { -0.05, 1, -0.05, -1, 0.05, -1, 0.05, 1 };
	glVertexPointer(2, GL_FLOAT, 0, net);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
};



int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

	bool done = false;
	
	SDL_Event event;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
			drawNet();
		}
		SDL_GL_SwapWindow(displayWindow);
	}

	SDL_Quit();
	return 0;
}