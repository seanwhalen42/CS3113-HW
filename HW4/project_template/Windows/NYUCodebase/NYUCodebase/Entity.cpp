#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity(){}

Entity::Entity(float x, float y, float mass, SheetSprite sprite, bool isStatic) : x(x), y(y), mass(mass), sprite(sprite), isStatic(isStatic){
	if (!isStatic){
		acceleration_y = -9.8;
	}
}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y;
}

float Entity::getBottom(){
	float bottom = y - sprite.getHeight() / 2;
	return bottom;
}

float Entity::getTop(){
	float top = y + sprite.getHeight() / 2;
	return top;
}

float Entity::getLeft(){
	float left = x - sprite.getWidth() / 2;
	return left;
}

float Entity::getRight(){
	float right = x + sprite.getWidth() / 2;
	return right;
}

void Entity::update(){
	velocity_x = lerp(velocity_x, 0.0f, FIXED_TIMESTEP * friction_x);
	velocity_y = lerp(velocity_y, 0.0f, FIXED_TIMESTEP * friction_y);

	velocity_x += acceleration_x * FIXED_TIMESTEP;
	velocity_y += acceleration_y * FIXED_TIMESTEP;

	x += velocity_x;
	y += velocity_y;
}

void Entity::draw(){
	sprite.draw(x, y, 1);
}

void Entity::setVelocity_x(float newX){
	velocity_x = newX;
}

void Entity::setVelocity_y(float newY){
	velocity_y = newY;
}

void Entity::setAcceleration_x(float newX){
	acceleration_x = newX;
}

void Entity::setAcceleration_y(float newY){
	acceleration_y = newY;
}

float lerp(float v0, float v1, float t){
	return (1.0 - t)*v0 + t*v1;
}