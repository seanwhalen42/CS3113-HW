
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Config.h"
#include "Entity.h"
#include "App.h"

App app;

int main(int argc, char *argv[]){
	
	app.setup();

	while (!app.isDone()){
		app.updateAndRender();
	}

	SDL_Quit();
	return 0;
}