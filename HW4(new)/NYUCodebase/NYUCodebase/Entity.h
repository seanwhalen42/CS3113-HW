#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"
#include "SheetSprite.h"
#include "LoadTexture.h"

class Entity{
public:
	Entity();
	Entity(SheetSprite sprite, float x, float y);
	~Entity();
	void draw(float scale);
	void update();

	//Accessors
	bool isStatic();

private:
	float x;
	float y;
	float height;
	float width;
	SheetSprite sprite;

	//Physics
	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	float friction_x;
	float friction_y;
	bool staticEntity;
};