#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class SheetSprite{
public:
	SheetSprite();
	SheetSprite(GLuint textureID, int index, int spriteCountX, int spriteCountY); //For loading sprites from uniform spritesheets
	SheetSprite(GLuint textureID, float u, float v, float width, float height); //For loading sprites from non-uniform spritesheets
	~SheetSprite();
	void draw(float x, float y, float scale);
	float getU();
	float getV();
	float getWidth();
	float getHeight();
private:
	GLuint texture;
	float u;
	float v;
	float width;
	float height;
};