#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"

class Entity{
public:
	Entity();
	Entity(float x, float y, float width, float height);
	~Entity();
	void draw();

	//Accessors
	float getX();
	float getY();
	float getHeight();
	float getWidth();


private:
	float x;
	float y;
	float height;
	float width;
	float scale;
};