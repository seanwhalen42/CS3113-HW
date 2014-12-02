#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include "Config.h"
#include "Entity.h"

Entity::Entity(){}

Entity::Entity(float x, float y, float width, float height) :x(x), y(y), width(width), height(height){
	scale = 1.0f;
}

Entity::~Entity(){}

void Entity::draw(){
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