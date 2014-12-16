#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"
#include "Entity.h"

const float GRAVITY = -0.9;

Entity::Entity(){}

Entity::Entity(float x, float y, SheetSprite* sprite, bool isStatic, float screenWidth, float screenHeight, float scale):x(x), y(y), staticBool(isStatic),
scale(scale), sprite(sprite){
	if (sprite != NULL) {
		if (screenWidth == -1){
			width = sprite->getWidth() * scale;
		}
		else {
			width = screenWidth * scale;
		}
		if (screenHeight == -1){
			height = sprite->getHeight() * scale;
		}
		else{
			height = screenHeight * scale;
		}
	}
	else {
		width = screenWidth;
		height = screenHeight;
	}
	velocity_x = 0;
	velocity_y = 0;
	acceleration_x = 0;
	acceleration_y = GRAVITY;
}

Entity::~Entity(){}

void Entity::draw(){
	if (sprite == NULL){
		GLfloat quad[] = { -width / 2 * scale, height / 2 * scale, -width / 2 * scale, -height / 2 * scale,
			width / 2 * scale, -height / 2 * scale, width / 2 * scale, height / 2 * scale };
		glMatrixMode(GL_MODELVIEW);
		glEnableClientState(GL_VERTEX_ARRAY);
		glTranslatef(x, y, 0);
		glVertexPointer(2, GL_FLOAT, 0, quad);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		glLoadIdentity();
	}
	else {
		sprite->draw(x, y, scale);
	}
}

void Entity::update(float elapsed){
	if (!staticBool){
		velocity_x += acceleration_x * elapsed;
		velocity_y += acceleration_y * elapsed;
		x += velocity_x * elapsed;
		y += velocity_y * elapsed;
	}
}

void Entity::moveX(float elapsed){
	if (!staticBool){
		velocity_x += acceleration_x * elapsed;
		x += velocity_x * elapsed;
	}
}

void Entity::moveY(float elapsed){
	if (!staticBool){
		velocity_y += acceleration_y * elapsed;
		y += velocity_y * elapsed;
	}
}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y;
}

float Entity::getWidth(){
	return width;
}

float Entity::getHeight(){
	return height;
}

bool Entity::isStatic(){
	return staticBool;
}

bool Entity::isTopCollide(){
	return topCollide;
}

bool Entity::isBottomCollide(){
	return bottomCollide;
}

bool Entity::isLeftCollide(){
	return leftCollide;
}

bool Entity::isRightCollide(){
	return rightCollide;
}

void Entity::setX(float newX){
	x = newX;
}

void Entity::setY(float newY){
	y = newY;
}

void Entity::setVelocityX(float newX){
	velocity_x = newX;
}

void Entity::setVelocityY(float newY){
	velocity_y = newY;
}

void Entity::setAccelerationX(float newX){
	acceleration_x = newX;
}

void Entity::setAccelerationY(float newY){
	acceleration_y = newY;
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

void Entity::clearCollisionFlags(){
	topCollide = false;
	bottomCollide = false;
	leftCollide = false;
	rightCollide = false;
}

void Entity::reset(){
	velocity_x = 0.0f;
	velocity_y = 0.0f;
	x = 0;
	y = 0;
}