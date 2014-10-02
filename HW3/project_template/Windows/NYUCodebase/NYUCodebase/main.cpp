
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"
#include "SheetSprite.h"
#include "App.h"

SDL_Window* displayWindow;

int main(int argc, char *argv[])
{
	ClassDemoApp app;
	while (!app.UpdateAndRender()) {}
	return 0;
}