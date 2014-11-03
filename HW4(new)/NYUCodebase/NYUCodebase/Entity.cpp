
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(SheetSprite sprite, float x, float y, bool isStatic, float scale):sprite(sprite), x(x), y(y), staticEntity(isStatic), scale(scale){
	height = sprite.getHeight();
	width = sprite.getWidth();
	velocity_x = 0;
	velocity_y = 0;
	acceleration_x = 0;
	acceleration_y = -10.0f; //Gravity
	friction_x = FRICTION;
	friction_y = FRICTION;
}

void Entity::draw(){
	sprite.draw(x, y, scale);
}

bool Entity::isStatic(){
	return staticEntity;
}

void Entity::rescale(float newScale){
	scale = newScale;
}

void Entity::update(){
	if (!staticEntity){
		//velocity_x = lerp(velocity_x, 0.0f, FIXED_TIMESTEP * friction_x);
		//velocity_y = lerp(velocity_y, 0.0f, FIXED_TIMESTEP * friction_y);
		velocity_x += acceleration_x * FIXED_TIMESTEP;
		velocity_y += acceleration_y * FIXED_TIMESTEP;
		x += velocity_x * FIXED_TIMESTEP;
		y += velocity_y * FIXED_TIMESTEP;
	}
}

