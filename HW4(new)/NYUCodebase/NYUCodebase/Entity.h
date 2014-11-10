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
	Entity(float x, float y, float width, float height, bool isStatic = false, float scale = 1);
	Entity(SheetSprite sprite, float x, float y, bool isStatic = false, float scale = 1);
	~Entity();
	void draw();
	void update();

	//Accessors
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
	bool isStatic();
	float calculatePenetrationX(Entity* otherEntity);
	float calculatePenetrationY(Entity* otherEntity);
	bool collisionDetect(Entity* otherEntity);
	//bool dynamicCollisionDetect(Entity* otherEntity);
	void resolveCollision(Entity* otherEntity);

	//Mutators
	void setX(float newX);
	void setY(float newY);
	void moveX();
	void moveY();
	void rescale(float newScale);
	void clearFlags();
	void setTopCollide(bool newBool);
	void setBottomCollide(bool newBool);
	void setLeftCollide(bool newBool);
	void setRightCollide(bool newBool);

private:
	float x;
	float y;
	float height;
	float width;
	float scale;
	float top;
	float bottom;
	float left;
	float right;
	SheetSprite sprite;
	bool topCollide;
	bool bottomCollide;
	bool leftCollide;
	bool rightCollide;

	//Physics
	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	float friction_x;
	float friction_y;
	bool staticEntity;
};