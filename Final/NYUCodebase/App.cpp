#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "App.h"

App::App(){
	//timeLeftOver = 0.0f;
	lastFrameTicks = 0.0f;

	bool done = false;
}

App::~App(){
	for (Entity* e : entities){
		delete e;
	}
	for (SheetSprite* s : sprites){
		delete s;
	}
}

void App::setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1.0, 1.0, -1.0, 1.0);

	GLuint metalTexture = LoadTexture("spritesheet_metal.png");
	GLuint aliensTexture = LoadTexture("spritesheet_aliens.png");

	SheetSprite* aliensSprite = new SheetSprite(aliensTexture, 512, 256, 140, 140, 70, 70);

	sprites.push_back(aliensSprite);

	player = new Entity(0.0f, 2.0f, aliensSprite);
	
	bottomWall = new Entity(0.0f, -1.1f, NULL, true, 1.5, 0.05, 1);
	entities.push_back(player);
	entities.push_back(bottomWall);
	//entities.push_back(platform);
}

void App::processInput(){
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_UP]){
		player->setVelocityY(1.0f);
	}
}

bool App::collisionDetect(Entity* entityA, Entity* entityB){
	float entityABottom = (entityA->getY()) - ((entityA->getHeight()) / 2);
	float entityATop = (entityA->getY()) + ((entityA->getHeight()) / 2);
	float entityALeft = (entityA->getX()) - ((entityA->getWidth()) / 2);
	float entityARight = (entityA->getX()) + ((entityA->getWidth()) / 2);

	float entityBBottom = (entityB->getY()) - ((entityB->getHeight()) / 2);
	float entityBTop = (entityB->getY()) + ((entityB->getHeight()) / 2);
	float entityBLeft = (entityB->getX()) - ((entityB->getWidth()) / 2);
	float entityBRight = (entityB->getX()) + ((entityB->getWidth()) / 2);

	return !(entityABottom > entityBTop || entityATop < entityBBottom || entityALeft > entityBRight || entityARight < entityBLeft);
}

float App::calcXPenetration(Entity* entityA, Entity* entityB){
	float distance = abs(entityA->getX() - entityB->getX()); //Absolute distance between centers
	float minDist = (entityA->getWidth() / 2) + (entityB->getWidth() / 2); //Distance of zero penetration
	return distance- minDist;
}

float App::calcYPenetration(Entity* entityA, Entity* entityB){
	float distance = abs(entityA->getY() - entityB->getY()); //Absolute distance between centers
	float minDist = (entityA->getHeight() / 2) + (entityB->getHeight() / 2); //Distance of zero penetration
	return distance - minDist;
}

void App::update(float elapsed){
	for (Entity* e : entities){
		if (!e->isStatic()){
			e->update(elapsed);
		}
	}
	
	std::vector<Entity*>::iterator iter = entities.begin();
	iter = entities.begin();
	while (iter != entities.end()){
		if ((*iter) != player){
			if (collisionDetect((*iter), (player))){
				reset();
			}
		}
		iter++;
	}
}

/*void App::update(float elapsed){
	std::vector<Entity*>::iterator iter = entities.begin();
	std::vector<Entity*>::iterator iter2 = entities.begin();
	iter = entities.begin();
	while (iter != entities.end()){
		if (!((*iter)->isStatic())){
			(*iter)->moveY(elapsed);
			iter2 = entities.begin();
			while (iter2 != entities.end()){
				if (iter != iter2){
					if (collisionDetect((*iter), (*iter2))){
						float yPenetration = calcYPenetration((*iter), (*iter2));
						(*iter)->setVelocityY(0.0f);
						if (((*iter)->getY()) > ((*iter2)->getY())){
							(*iter)->setY(((*iter)->getY()) + yPenetration + COLLISION_BUFFER);
						}
						else {
							(*iter)->setY(((*iter)->getY()) - yPenetration - COLLISION_BUFFER);
						}
						reset();
					}
				}
				iter2++;
			}
		}
		iter++;
	}

	iter = entities.begin();
	iter2 = entities.begin();
	/*while (iter != entities.end()){
		if (!((*iter)->isStatic())){
			(*iter)->moveX(elapsed);
			while (iter2 != entities.end()){
				if (iter != iter2){
					if (collisionDetect(*iter, *iter2)){
						float xPenetration = calcXPenetration((*iter), (*iter2));
						(*iter)->setVelocityY(0.0f);
						if (((*iter)->getX()) > (*iter)->getX()){
							(*iter)->setX((*iter)->getX() + xPenetration + COLLISION_BUFFER);
						}
						else {
							(*iter)->setX((*iter)->getX() - xPenetration - COLLISION_BUFFER);
						}
					}
				}
				iter2++;
			}
		}
		iter++;
	}
}*/

void App::render(){
	glClear(GL_COLOR_BUFFER_BIT);
	std::vector<Entity*>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(**iter).draw();
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
		processInput();
		float ticks = (float)SDL_GetTicks() / 1000.0f;
		float elapsed = ticks - lastFrameTicks;
		lastFrameTicks = ticks;

		//std::cout << "Player: " << player->getY();

		update(elapsed);
		//player->update(elapsed);

		SDL_GL_SwapWindow(displayWindow);
		render();
	}

	SDL_Quit();
}

void App::reset(){
	player->reset();
}

bool App::isDone(){
	return done;
}