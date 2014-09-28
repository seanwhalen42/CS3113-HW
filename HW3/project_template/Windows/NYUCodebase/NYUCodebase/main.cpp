
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "ClassDemoApp.h"
#include "sprite.h"
#include "Entity.h"

SDL_Window* displayWindow;
std::vector<Entity> entities;

ClassDemoApp::ClassDemoApp() {
	Init();
	done = false;
	lastFrameTicks = 0.0f;
}

void ClassDemoApp::Init() {
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
}

ClassDemoApp::~ClassDemoApp() {
	SDL_Quit();
}

void ClassDemoApp::Render() {
	// render stuff
	SDL_GL_SwapWindow(displayWindow);
}

void ClassDemoApp::Update(float elapsed) {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
	}
}

bool ClassDemoApp::UpdateAndRender() {
	float ticks = (float)SDL_GetTicks() / 1000.0f;
	float elapsed = ticks - lastFrameTicks;
	lastFrameTicks = ticks;
	Update(elapsed);
	Render();
	return done;
}

void ClassDemoApp::Update(float elapsed) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i].Update(elapsed);
	}
}

int main(int argc, char *argv[])
{
	ClassDemoApp app;
	while (!app.UpdateAndRender()) {}
	return 0;
}