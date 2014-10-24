#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class SheetSprite{
public:
	SheetSprite();
	SheetSprite(GLuint texture, float sheetX, float sheetY, float pixelU, float pixelV, float pixelHeight, float pixelWidth);
	~SheetSprite();
	void draw(float scale);
private:
	GLuint texture;
	float u;
	float v;
	float height;
	float width;
	float sheetX;
	float sheetY;
	float aspectRatio;
};