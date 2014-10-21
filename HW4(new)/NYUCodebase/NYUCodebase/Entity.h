#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class Entity{
public:
	Entity();
	Entity(float x, float y, float height, float width);
	~Entity();
	void draw();
private:
	float x;
	float y;
	float height;
	float width;
};