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
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
	bool isStatic();
	bool dynamicCollisionDetect(Entity* otherEntity);

	//Mutators
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