#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class SheetSprite {
public:
	SheetSprite();
	SheetSprite(unsigned int textureID, float u, float v, float width, float height);
	void Draw(float scale);
private:
	float scale;
	unsigned int textureID;
	float u;
	float v;
	float width;
	float height;
};