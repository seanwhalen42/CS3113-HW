#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "App.h"

App::App(){
	timeLeftOver = 0.0f;
}

App::~App(){}

void App::setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1, 1, -1, 1);//Affects projection matrix
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