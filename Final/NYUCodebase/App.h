#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "Entity.h"
#include "Config.h"

class App{
public:
	App();
	~App();
	void setup();
	void processInput();
	void update();
	void render();
	void updateAndRender();
	bool isDone();
private:
	bool done;
	Entity* player;
	std::vector <Entity*> entities;
	//float timeLeftOver;
	float lastFrameTicks;
	SDL_Event event;
	SDL_Window* displayWindow;
};