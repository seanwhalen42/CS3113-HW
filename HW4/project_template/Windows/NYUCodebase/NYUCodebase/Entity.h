#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "SheetSprite.h"

class Entity {
public:
	Entity(/*float array[],*/ float x, float y, float speed, SheetSprite sprite);

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

	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	float friction_x;
	float friction_y;
	float mass;
	bool collidedTop;
	bool collidedBottom;
	bool collidedLeft;
	bool collidedRight;

	bool isVisible;
	bool collides;
	bool isStatic;

	//float vertexArray[8];
};