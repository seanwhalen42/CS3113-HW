#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"

class Entity{
	//Constructors
	Entity();
	Entity(float x, float y, float mass, SheetSprite sprite);
	~Entity();

	//Accessors
	float getX();
	float getY();
	void update();
	void draw();

	//Mutators
	void setVelocity_x(float newX);
	void setVelocity_y(float newY);
	void setAcceleration_x(float newX);
	void setAcceleration_y(float newY);
	void reset();

private:
	//Position
	float x;
	float y;

	//Physics
	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	float friction_x;
	float friction_y;
	float mass;

	//Collision Flags
	bool collidingTop;
	bool collidingBottom;
	bool collidingLeft;
	bool collidingRight;

	SheetSprite sprite;
};