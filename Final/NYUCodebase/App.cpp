#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "App.h"

App::App(){
	timeLeftOver = 0.0f;
	lastFrameTicks = 0.0f;

	bool done = false;
}

App::~App(){}

void App::setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1.0, 1.0, -1.0, 1.0);

	Entity testEntity(0, 0, 0.5, 0.5);
	entities.push_back(testEntity);
}

void App::render(){
	glClear(GL_COLOR_BUFFER_BIT);
	std::vector<Entity>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(*iter).draw();
		iter++;
	}
}

void App::updateAndRender(){
	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
		SDL_GL_SwapWindow(displayWindow);
		render();
	}

	SDL_Quit();
}

bool App::isDone(){
	return done;
}