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
	Entity(float x, float y, SheetSprite* sprite = NULL, bool isStatic = false, float screenWidth = -1, float screenHeight = -1, float scale = 1);
	~Entity();
	void draw();
	void update(float elapsed);
	void moveX(float elapsed);
	void moveY(float elapsed);

	//Accessors
	float getX();
	float getY();
	float getHeight();
	float getWidth();
	bool isStatic();
	bool isTopCollide();
	bool isBottomCollide();
	bool isLeftCollide();
	bool isRightCollide();

	//Mutators
	void setX(float newX);
	void setY(float newY);
	void setVelocityX(float newX);
	void setVelocityY(float newY);
	void setAccelerationX(float newX);
	void setAccelerationY(float newX);
	void setTopCollide(bool newBool);
	void setBottomCollide(bool newBool);
	void setLeftCollide(bool newBool);
	void setRightCollide(bool newBool);
	void clearCollisionFlags();

private:
	float x;
	float y;
	float height;
	float width;
	float scale;
	SheetSprite* sprite;

	//Physics
	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	bool staticBool;

	//Collision Flags
	bool topCollide;
	bool bottomCollide;
	bool leftCollide;
	bool rightCollide;
};