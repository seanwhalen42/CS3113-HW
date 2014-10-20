#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"

class Entity{
public:
	Entity();
	Entity(float x, float y);
	~Entity();
	void update();

private:
	float x;
	float y;
	float height;
	float width;

	//Physics
	float acceleration_x;
	float acceleration_y;
	float velocity_x;
	float velocity_y;
	float mass;
	float friction_x;
	float friction_y;
};