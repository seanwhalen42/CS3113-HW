#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "App.h"

App::App(){
	//timeLeftOver = 0.0f;
	lastFrameTicks = 0.0f;

	bool done = false;
}

App::~App(){
	for (Entity* e : entities){
		delete e;
	}
}

void App::setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1.0, 1.0, -1.0, 1.0);

	GLuint metalTexture = LoadTexture("spritesheet_metal.png");
	GLuint aliensTexture = LoadTexture("spritesheet_aliens.png");

	SheetSprite metalSprite(metalTexture, 1024, 1024, 500, 0, 140, 140);
	SheetSprite aliensSprite(aliensTexture, 512, 256, 140, 140, 70, 70);
	player = new Entity(0.0f, 1.0f, aliensSprite);
	Entity* platform;
	platform = new Entity(0.0f, -0.5f, metalSprite, true);
	entities.push_back(player);
	entities.push_back(platform);
}

void App::processInput(){
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_UP]){
		player->setVelocityY(1.0f);
	}
}

void App::render(){
	glClear(GL_COLOR_BUFFER_BIT);
	std::vector<Entity*>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(**iter).draw();
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
		processInput();
		float ticks = (float)SDL_GetTicks() / 1000.0f;
		float elapsed = ticks - lastFrameTicks;
		lastFrameTicks = ticks;

		player->update(elapsed);

		SDL_GL_SwapWindow(displayWindow);
		render();
	}

	SDL_Quit();
}

bool App::isDone(){
	return done;
}