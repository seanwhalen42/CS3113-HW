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

void Entity::update(float elapsed){

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