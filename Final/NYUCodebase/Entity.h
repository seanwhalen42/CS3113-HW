#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "SheetSprite.h"
#include "Config.h"

class Entity{
public:
	Entity();
	Entity(float x, float y, SheetSprite sprite, float screenWidth = -1, float screenHeight = -1, float scale = 1);
	~Entity();
	void draw();
	void update(float elapsed);

	//Accessors
	float getX();
	float getY();
	float getHeight();
	float getWidth();

	//Mutators
	void setX(float newX);
	void setY(float newY);
	void setVelocityX(float newX);
	void setVelocityY(float newY);
	void setAccelerationX(float newX);
	void setAccelerationY(float newX);

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
};