#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"
#include "Entity.h"

Entity::Entity(){}

Entity::Entity(float x, float y, SheetSprite sprite, float screenWidth, float screenHeight, float scale):x(x), y(y), scale(scale), sprite(sprite){
	if (width == -1){
		width = sprite.getWidth();
	}
	else {
		width = screenWidth;
	}
	if (height == -1){
		height = sprite.getHeight();
	}
	else{
		height = screenHeight;
	}
	velocity_x = 0;
	velocity_y = 0;
	acceleration_x = 0;
	acceleration_y = -0.9;
}

Entity::~Entity(){}

void Entity::draw(){
	/*GLfloat quad[] = { -width / 2 * scale, height / 2 * scale, -width / 2 * scale, -height / 2 * scale,
		width / 2 * scale, -height / 2 * scale, width / 2 * scale, height / 2 * scale };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 0, quad);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();*/

	sprite.draw(x, y, scale);
}

void Entity::update(float elapsed){
	velocity_x += acceleration_x * elapsed;
	velocity_y += acceleration_y * elapsed;
	x += velocity_x * elapsed;
	y += velocity_y * elapsed;
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