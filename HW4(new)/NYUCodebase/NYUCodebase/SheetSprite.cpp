#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"

SheetSprite::SheetSprite(){}

SheetSprite::SheetSprite(GLuint texture, float u, float v, float height, float width) : texture(texture), u(u), v(v), height(height), width(width){

}

SheetSprite::~SheetSprite(){}

void SheetSprite::draw(float scale){
	GLfloat quad[] = { -width * scale, height * scale, -width * scale, -height * scale,
		width * scale, -height * scale, width * scale, height * scale };
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnableClientState(GL_VERTEX_ARRAY);
	
	GLfloat quadUVs[] = { u, v, u, v + height, u + width, v + height, u + width, v };
	glVertexPointer(2, GL_FLOAT, 0, quad);
	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glDrawArrays(GL_QUADS, 0, 4);
	glDisable(GL_TEXTURE_2D);
}