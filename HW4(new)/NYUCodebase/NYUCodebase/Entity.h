#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "SheetSprite.h"
#include "LoadTexture.h"

class Entity{
public:
	Entity();
	Entity(SheetSprite sprite, float x, float y);
	~Entity();
	void draw(float scale);
private:
	float x;
	float y;
	float height;
	float width;
	SheetSprite sprite;
};