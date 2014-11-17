#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Config.h"
#include "SheetSprite.h"
#include "Entity.h"

const float COLLISION_BUFFER = 0.0001;

class App{
public:
	App();
	~App();
	void setup();
	void fixedUpdate();
	void render();
	void updateAndRender();
	bool isDone();
	void processEvents();
private:
	Entity* player;
	std::vector<Entity> entities;
	float timeLeftOver;
	SDL_Window* displayWindow;
	float lastFrameTicks;
	bool done;
	SDL_Event event;
};