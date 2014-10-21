#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(float x, float y, float height, float width) :x(x), y(y), height(height), width(width) {}

void Entity::draw(){
	float vertexArray[8] = { x - (width / 2), y + (height / 2), x - (width / 2), y - (height / 2), x + (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertexArray);
	glLoadIdentity();
	glDrawArrays(GL_QUADS, 0, 4);
}