#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"
#include "SheetSprite.h"
#include "LoadTexture.h"

const float FRICTION = 0.1f;

class Entity{
public:
	Entity();
	Entity(SheetSprite sprite, float x, float y, bool isStatic = false, float scale = 1);
	~Entity();
	void draw();
	void update();

	//Accessors
	bool isStatic();

	//Mutators
	void rescale(float newScale);

private:
	float x;
	float y;
	float height;
	float width;
	float scale;
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