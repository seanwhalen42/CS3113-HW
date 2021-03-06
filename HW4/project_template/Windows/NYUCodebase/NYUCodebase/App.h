#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "SheetSprite.h"
#include "Entity.h"

const int SPRITE_COUNT_X;
const int SPRITE_COUNT_Y;
const int LEVEL_WIDTH = 16;
const int LEVEL_HEIGHT = 16;
const float TILE_SIZE;

class App{
public:
	App();
	~App();

	void init();
	void updateAndRender();

	void draw();
	void processEvents();
	void update(float elapsed);
	GLuint LoadTexture(std::string image_path_str);
	void drawTitle();
	void drawGameOver();

	void drawTiles();

	void collisionCheck(Entity* entityA, Entity* entityB);
	float calculatePenetrationX(Entity* entityA, Entity* entityB);
	float calculatePenetrationY(Entity* entityA, Entity* entityB);
	void applyPenetration(Entity* entityA, Entity* entityB);

	int encodeChar(char charToEncode);
	SheetSprite decodeFromIndex(int index, int spriteCountX, int spriteCountY, GLuint texture);
	void renderFont(std::string str);

private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
	unsigned char levelData[LEVEL_WIDTH][LEVEL_HEIGHT];
};