#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class SheetSprite {
public:
	SheetSprite();
	SheetSprite(GLuint textureID, float u, float v, float width, float height);
	void Draw(float x, float y, float scale);
	unsigned int getTextureID();
	float getU();
	float getV();
	float getWidth();
	float getHeight();
private:
	float scale;
	unsigned int textureID;
	float u;
	float v;
	float width;
	float height;
};