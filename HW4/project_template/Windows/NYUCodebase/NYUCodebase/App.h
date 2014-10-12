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
	void drawText(std::string str, float x, float y);

	bool collisionDetect(Entity* entityA, Entity* entityB);

private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
	
};