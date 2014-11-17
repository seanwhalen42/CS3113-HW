#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "Entity.h"
#include "SheetSprite.h"
#include "LoadTexture.h"
#include "App.h"

App app;

int main(int argc, char *argv[])
{
	app.setup();
	
	while (!app.isDone()){
		app.updateAndRender();
	}
	
	SDL_Quit();
	return 0;
}

