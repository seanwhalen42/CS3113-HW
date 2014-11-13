#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Config.h"
#include "SheetSprite.h"
#include "Entity.h"

const float COLLISION_BUFFER = 0.0001;

class App{
	App();
	~App();
	void setup();
	void fixedUpdate();
private:
	std::vector<Entity> entities;
	float timeLeftOver;
	SDL_Window* displayWindow;
};