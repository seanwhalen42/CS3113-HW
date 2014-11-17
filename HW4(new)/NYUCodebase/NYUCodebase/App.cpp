#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "App.h"

App::App(){
	timeLeftOver = 0.0f;
	lastFrameTicks = 0.0f;

	bool done = false;
}

App::~App(){}

void App::setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1, 1, -1, 1);//Affects projection matrix
	
	GLuint testSpriteSheet = LoadTexture("enemies_spritesheet.png");
	GLuint floorSpriteSheet = LoadTexture("spritesheet_metal.png");
	SheetSprite testSprite(testSpriteSheet, 353, 153, 136, 66, 51, 51);
	SheetSprite floorSprite(floorSpriteSheet, 1024, 1024, 0, 140, 70, 220);
	Entity testEntityA(testSprite, 0.1, 0.2);
	Entity testFloor(floorSprite, 0.1, -0.5, true);

	entities.push_back(testEntityA);
	player = &entities[0];
	entities.push_back(testFloor);
}

void App::fixedUpdate(){
	std::vector<Entity>::iterator iter = entities.begin();
	std::vector<Entity>::iterator iter2 = entities.begin();
	while (iter != entities.end()){
		(*iter).update();
		iter++;
	}
	iter = entities.begin();
	while (iter != entities.end()){
		if (!(*iter).isStatic()){
			(*iter).moveY();
			iter2 = entities.begin();
			while (iter2 != entities.end()){
				if (iter != iter2){
					if (iter->collisionDetect(&(*iter2))){
						float yPenetration = iter->calculatePenetrationY(&(*iter2));
						(*iter).setVelocity_Y(0);
						if ((*iter).getY() > (*iter2).getY()){
							(*iter).setY((*iter).getY() + yPenetration + COLLISION_BUFFER);
						}
						else {
							(*iter).setY((*iter).getY() - yPenetration - COLLISION_BUFFER);
						}
					}
				}
				iter2++;
			}
		}
		iter++;
	}

	iter = entities.begin();
	iter2 = entities.begin();
	while (iter != entities.end()){
		if (!(*iter).isStatic()){
			(*iter).moveX();
			iter2 = entities.begin();
			while (iter2 != entities.end()){
				if (iter != iter2){
					if (iter->collisionDetect(&(*iter2))){
						float xPenetration = iter->calculatePenetrationX(&(*iter2));
						(*iter).setVelocity_X(0);
						if ((*iter).getX() > (*iter2).getX()){
							(*iter).setX((*iter).getX() + xPenetration + 0.0001);
						}
						else {
							(*iter).setX((*iter).getX() - xPenetration - 0.0001);
						}
					}
				}
				iter2++;
			}
		}
		iter++;
	}
}

void App::render(){
	glClear(GL_COLOR_BUFFER_BIT);
	std::vector<Entity>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(*iter).draw();
		iter++;
	}
}

void App::updateAndRender(){
	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
		processEvents();
		float ticks = (float)SDL_GetTicks() / 1000.0f;
		float elapsed = ticks - lastFrameTicks;
		lastFrameTicks = ticks;
		float fixedElapsed = elapsed + timeLeftOver;

		if (fixedElapsed > FIXED_TIMESTEP * MAX_TIMESTEPS){
			fixedElapsed = FIXED_TIMESTEP * MAX_TIMESTEPS;
		}
		while (fixedElapsed >= FIXED_TIMESTEP){
			fixedElapsed -= FIXED_TIMESTEP;
			fixedUpdate();
		}
		timeLeftOver = fixedElapsed;
		render();
		//testEntityA.draw();
		//testEntityB.draw();
		//testSprite.draw(0.5, 0.5, 1);
		SDL_GL_SwapWindow(displayWindow);
	}
}

bool App::isDone(){
	return done;
}

void App::processEvents(){
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_UP]){
		player->setVelocity_Y(10.0f);
	}
}