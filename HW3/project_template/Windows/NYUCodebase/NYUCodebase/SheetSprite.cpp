#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"

SheetSprite::SheetSprite(){

}

SheetSprite::SheetSprite(GLuint textureID, float u, float v, float width, float height) : textureID(textureID), u(u), v(v), width(width), height(height) {
	scale = 1;
}

void SheetSprite::Draw(float x, float y, float scale) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	GLfloat quad[] = { -width * scale, height * scale, -width * scale, -height * scale,
	width * scale, -height * scale, width * scale, height * scale };
	GLfloat quadUVs[] = { u, v, u, v + height, u + width, v + height, u + width, v };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 0, quad);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY); // this is also broken: See slides #3
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
}

float SheetSprite::getU(){
	return u;
}

float SheetSprite::getV(){
	return v;
}

float SheetSprite::getWidth(){
	return width;
}

float SheetSprite::getHeight(){
	return height;
}