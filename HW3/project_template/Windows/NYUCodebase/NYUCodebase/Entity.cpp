#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Entity.h"
#include "SheetSprite.h"

Entity::Entity(){}

Entity::Entity(float x, float y, float speed, SheetSprite sprite) : x(x), y(y), speed(speed), sprite(sprite){

	width = sprite.getWidth();
	height = sprite.getHeight();


	direction_x = 0;
	direction_y = 0;
	isVisible = true;
	collides = true;
}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y;
}

float Entity::getHeight() {
	return height;
}

float Entity::getWidth() {
	return width;
}

float Entity::getSpeed() {
	return speed;
}

bool Entity::getVisible(){
	return isVisible;
}

bool Entity::getCollide(){
	return collides;
}

float Entity::getTop() {
	float top = (y + (height / 2));
	return top;
}

float Entity::getBottom(){
	float bottom = (y - (height / 2));
	return bottom;
}

float Entity::getLeft(){
	float left = (x - (width / 2));
	return left;
}

float Entity::getRight(){
	float right = (x + (width / 2));
	return right;
}

void Entity::draw(float scale){
	if (isVisible){
		sprite.Draw(x, y, scale);
	}
}

void Entity::setDirection_x(float newX){
	direction_x = newX;
}

void Entity::setDirection_y(float newY){
	direction_y = newY;
}

void Entity::setCollide(bool c){
	collides = c;
}

void Entity::setVisible(bool v){
	isVisible = v;
}

void Entity::bounceX(){
	direction_x *= -1;
}

void Entity::bounceY(){
	direction_y *= -1;
}

void Entity::reset(){
	x = 0;
	y = 0;
}

