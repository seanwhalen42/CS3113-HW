
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
	top = y + height / 2;
	bottom = y - height / 2;
	left = x - width / 2;
	right = x + width / 2;
	friction_x = FRICTION;
	friction_y = FRICTION;
}

void Entity::draw(){
	sprite.draw(x, y, scale);
}

float Entity::getTop(){
	return top;
}

float Entity::getBottom(){
	return bottom;
}

float Entity::getRight(){
	return right;
}

float Entity::getLeft(){
	return left;
}

bool Entity::isStatic(){
	return staticEntity;
}

bool Entity::dynamicCollisionDetect(Entity* otherEntity){
	if (top > otherEntity->getBottom() && top < otherEntity->getTop()){
		topCollide = true;
		otherEntity->setBottomCollide(true);
		return true;
	}
	else if (bottom < otherEntity->getTop() && bottom > otherEntity->getBottom()){
		bottomCollide = true;
		otherEntity->setTopCollide(true);
		return true;
	}
	else if (left < otherEntity->getRight() && left > otherEntity->getLeft()){
		leftCollide = true;
		otherEntity->setRightCollide(true);
		return true;
	}
	else if (right > otherEntity->getLeft() && right < otherEntity->getRight()){
		rightCollide = true;
		otherEntity->setLeftCollide(true);
		return true;
	}
	else {
		return false;
	}
}

void Entity::rescale(float newScale){
	scale = newScale;
}

void Entity::clearFlags(){
	topCollide = false;
	bottomCollide = false;
	leftCollide = false;
	rightCollide = false;
}

void Entity::setTopCollide(bool newBool){
	topCollide = newBool;
}

void Entity::setBottomCollide(bool newBool){
	bottomCollide = newBool;
}

void Entity::setLeftCollide(bool newBool){
	leftCollide = newBool;
}

void Entity::setRightCollide(bool newBool){
	rightCollide = newBool;
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

