#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"
#include "LoadTexture.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(float x, float y, float height, float width, std::string img_path_str) :x(x), y(y), height(height), width(width) {
	texture = LoadTexture(img_path_str);
}

void Entity::draw(){
	float vertexArray[8] = { x - (width / 2), y + (height / 2), x - (width / 2), y - (height / 2), 
		x + (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnableClientState(GL_VERTEX_ARRAY);
	GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
	glVertexPointer(2, GL_FLOAT, 0, vertexArray);
	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisable(GL_TEXTURE_2D);
}

