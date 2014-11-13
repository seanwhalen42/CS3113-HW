#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "Entity.h"
#include "SheetSprite.h"
#include "LoadTexture.h"
#include "App.h"



void render(){
	glClear(GL_COLOR_BUFFER_BIT);
	std::vector<Entity>::iterator iter = entities.begin();
	while (iter != entities.end()){
		(*iter).draw();
		iter++;
	}
}

float lastFrameTicks = 0.0f;

int main(int argc, char *argv[])
{
	setup();
	
	//Entity testEntityB(0.5, 0.5, 0.1, 0.1);
	GLuint testSpriteSheet = LoadTexture("enemies_spritesheet.png");
	GLuint floorSpriteSheet = LoadTexture("spritesheet_metal.png");
	SheetSprite testSprite(testSpriteSheet, 353, 153, 136, 66, 51, 51);
	SheetSprite floorSprite(floorSpriteSheet, 1024, 1024, 0, 140, 70, 220);
	Entity testEntityA(testSprite, 0.1, 0.2);
	Entity testFloor(floorSprite, 0.1, -0.5, true);

	entities.push_back(testEntityA);
	entities.push_back(testFloor);

	bool done = false;
	
	SDL_Event event;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
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

	SDL_Quit();
	return 0;
}

