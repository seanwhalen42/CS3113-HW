#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "SheetSprite.h"

SheetSprite::SheetSprite(){

}

SheetSprite::SheetSprite(unsigned int textureID, float u, float v, float width, float height) : textureID(textureID), u(u), v(v), width(width), height(height) {

}

void SheetSprite::Draw(float x, float y, float scale) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	GLfloat quad[] = { -width * scale, height * scale, -width * scale, -height * scale,
	width * scale, -height * scale, width * scale, height * scale };
	GLfloat quadUVs[] = { u, v, u, v + height, u + width, v + height, u + width, v };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 0, quad);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();
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