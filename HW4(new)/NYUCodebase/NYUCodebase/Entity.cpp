#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Config.h"

Entity::Entity(){}

Entity::Entity(float x, float y){
	acceleration_y = -9.8; //Gravity
}

void Entity::update(){
	velocity_x = lerp(velocity_x, 0.0f, FIXED_TIMESTEP * friction_x);
	velocity_y = lerp(velocity_y, 0.0f, FIXED_TIMESTEP * friction_y);
	velocity_x += acceleration_x * FIXED_TIMESTEP;
	velocity_y += acceleration_y * FIXED_TIMESTEP;
	x += velocity_x * FIXED_TIMESTEP;
	y += velocity_y * FIXED_TIMESTEP;
}

float lerp(float v0, float v1, float t) {
	return (1.0 - t)*v0 + t*v1;
}