#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "sprite.h"

class Bullet {
	Bullet();
	Bullet(float x, float y, SheetSprite sprite);
	void Draw();
	float x;
	float y;
	float speed;
	SheetSprite sprite;
	float vertexArray[8];
};