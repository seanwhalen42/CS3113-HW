#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "SheetSprite.h"

class Entity {
public:
	Entity();

	Entity(float x, float y, float speed, SheetSprite sprite);

	//Accessors

	float getX();

	float getY();

	float getHeight();

	float getWidth();

	float getSpeed();

	bool getVisible();

	bool getCollide();

	float getTop();

	float getBottom();

	float getLeft();

	float getRight();
	
	void draw(float scale);
	
	//Mutators

	void setDirection_x(float newX);

	void setDirection_y(float newY);

	void update(float elapsed);

	void setCollide(bool c);

	void setVisible(bool v);

	void bounceX();

	void bounceY();

	void reset();

private:
	float x;
	float y;
	float rotation;

	SheetSprite sprite;
	float width;
	float height;

	float speed;
	float direction_x;
	float direction_y;

	bool isVisible;
	bool collides;

	//float vertexArray[8];
};