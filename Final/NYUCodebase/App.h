#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "Entity.h"
#include "Config.h"

const float COLLISION_BUFFER = 0.001;
const float BARRIER_SPEED = 0.001;

class App{
public:
	App();
	~App();
	void setup();
	void processInput();
	bool collisionDetect(Entity* entityA, Entity* entityB);
	float calcXPenetration(Entity* entityA, Entity* entityB);
	float calcYPenetration(Entity* entityA, Entity* entityB);
	void update(float elapsed);
	void render();
	void updateAndRender();
	void reset();
	bool isDone();
private:
	bool done;
	Entity* player;
	Entity* bottomWall;
	Entity* topWall;
	Entity* topBarrier;
	Entity* bottomBarrier;
	std::vector <Entity*> entities;
	std::vector <SheetSprite*> sprites;
	float lastFrameTicks;
	SDL_Event event;
	SDL_Window* displayWindow;
};