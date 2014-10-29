
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(SheetSprite sprite, float x, float y):sprite(sprite), x(x), y(y){
	height = sprite.getHeight();
	width = sprite.getWidth();
	acceleration_y = -9.8; //Gravity
}

void Entity::draw(float scale){
	sprite.draw(x, y, scale);
}

bool Entity::isStatic(){
	return staticEntity;
}

void Entity::update(){
	if (!staticEntity){
		velocity_x = lerp(velocity_x, 0.0f, FIXED_TIMESTEP * friction_x);
		velocity_y = lerp(velocity_y, 0.0f, FIXED_TIMESTEP * friction_y);
		velocity_x += acceleration_x * FIXED_TIMESTEP;
		velocity_y += acceleration_y * FIXED_TIMESTEP;
		x += velocity_x * FIXED_TIMESTEP;
		y += velocity_y * FIXED_TIMESTEP;
	}
}

