#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"
// 60 FPS (1.0f/60.0f)
#define FIXED_TIMESTEP 0.0166666f
#define MAX_TIMESTEPS 6
float timeLeftOver = 0.0f;

class Entity{
public:
	//Constructors
	Entity();
	Entity(float x, float y, float mass, SheetSprite sprite, bool isStatic);
	~Entity();

	//Accessors
	float getX();
	float getY();
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
	void update();
	void draw();

	//Mutators
	void setVelocity_x(float newX);
	void setVelocity_y(float newY);
	void setAcceleration_x(float newX);
	void setAcceleration_y(float newY);

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

	bool isStatic;
	bool isVisible;
	bool collisionEnabled;

	//Collision Flags
	bool collidingTop;
	bool collidingBottom;
	bool collidingLeft;
	bool collidingRight;

	SheetSprite sprite;
};

float lerp(float v0, float v1, float t);