#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "Entity.h"
#include "SheetSprite.h"
#include "LoadTexture.h"

SDL_Window* displayWindow;

std::vector<Entity> entities;

float timeLeftOver = 0.0f; //TRied to put this in Config.h, gave error
void setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1, 1, -1, 1);//Affects projection matrix
}

void fixedUpdateAndRender(){
	std::vector<Entity>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(*iter).update();
		(*iter).draw();
		iter++;
	}
}


int main(int argc, char *argv[])
{
	setup();
	
	//Entity testEntityB(0.5, 0.5, 0.1, 0.1);
	GLuint testSpriteSheet = LoadTexture("enemies_spritesheet.png");
	SheetSprite testSprite(testSpriteSheet, 353, 153, 136, 66, 51, 51);
	Entity testEntityA(testSprite, 0.1, 0.2);

	entities.push_back(testEntityA);

	bool done = false;
	
	SDL_Event event;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
		float lastFrameTicks = 0.0f;
		float ticks = (float)SDL_GetTicks() / 1000.0f;
		float elapsed = ticks - lastFrameTicks;
		lastFrameTicks = ticks;
		float fixedElapsed = elapsed + timeLeftOver;
		
		if (fixedElapsed > FIXED_TIMESTEP * MAX_TIMESTEPS){
			fixedElapsed = FIXED_TIMESTEP * MAX_TIMESTEPS;
		}
		while (fixedElapsed >= FIXED_TIMESTEP){
			fixedElapsed -= FIXED_TIMESTEP;
			fixedUpdateAndRender();
		}
		//testEntityA.draw();
		//testEntityB.draw();
		//testSprite.draw(0.5, 0.5, 1);
		SDL_GL_SwapWindow(displayWindow);
	}

	SDL_Quit();
	return 0;
}

