#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Entity.h"
#include "SheetSprite.h"

float lerp(float v0, float v1, float t) {
	return (1.0 - t)*v0 + t*v1;
}

Entity::Entity(float x, float y, SheetSprite sprite) : x(x), y(y) {

	width = sprite.getWidth();
	height = sprite.getHeight();

	velocity_x = 0;
	velocity_y = 0;
	acceleration_x = 0;
	acceleration_y = -9.8; //Gravity
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

void Entity::setVelocity_x(float newX){
	velocity_x = newX;
}

void Entity::setVelocity_y(float newY){
	velocity_y = newY;
}

void Entity::update(float elapsed){
	x += velocity_x * elapsed;
	y += velocity_y * elapsed;
	velocity_x += acceleration_x * elapsed;
	velocity_y += acceleration_y * elapsed;
	velocity_x = lerp(velocity_x, 0.0f, elapsed * friction_x);
	velocity_y = lerp(velocity_y, 0.0f, elapsed * friction_y);
}

void Entity::setCollide(bool c){
	collides = c;
}

void Entity::setVisible(bool v){
	isVisible = v;
}

void Entity::bounceX(){
	velocity_x *= -1;
}

void Entity::bounceY(){
	velocity_y *= -1;
}

void Entity::reset(){
	x = 0;
	y = 0;
}

