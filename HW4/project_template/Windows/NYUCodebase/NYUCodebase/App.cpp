#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "App.h"

enum GameState { STATE_TITLE, STATE_GAME, STATE_GAME_OVER };

App::App(){
	init();
	done = false;
	lastFrameTicks = 0;
}

App::~App(){
	SDL_Quit();
}

void App::init() {
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	GameState state = STATE_TITLE;
}

void App::update(float elapsed) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
	}
}

void App::drawText(std::string str, float x, float y){

}

void App::collisionCheck(Entity* entityA, Entity* entityB){
	entityA->clearCollisionFlags();
	entityB->clearCollisionFlags();
	if (entityA->getBottom() < entityB->getTop() && entityA->getBottom() > entityB->getBottom()){
		entityA->setCollisionBottom(true);
		entityB->setCollisionTop(true);
	}
	
	if (entityA->getTop() > entityB->getBottom() && entityA->getTop() < entityB->getTop()){
		entityA->setCollisionTop(true);
		entityB->setCollisionBottom(true);
	}

	if (entityA->getRight() > entityB->getLeft() && entityA->getLeft() < entityB->getRight()){
		entityA->setCollisionRight(true);
		entityB->setCollisionLeft(true);
	}
	
	if (entityA->getLeft() < entityB->getRight() && entityA->getRight() < entityB->getRight()){
		entityA->setCollisionLeft(true);
		entityB->setCollisionRight(true);
	}
}