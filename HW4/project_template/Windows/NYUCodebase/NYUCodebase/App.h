#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "SheetSprite.h"
#include "Entity.h"

class App{
public:
	App();
	~App();

	void init();
	void updateAndRender();

	void draw();
	void update(float elapsed);
	void drawTitle();
	void drawGameOver();

	void collisionCheck(Entity* entityA, Entity* entityB);
	float calculatePenetration(Entity* entityA, Entity* entityB);

	SheetSprite decodeFromIndex(int index, int spriteCountX, int spriteCountY, GLuint texture);
	void renderFont(std::string str);

private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
	
};