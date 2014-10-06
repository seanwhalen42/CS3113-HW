#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Entity.h"
#include "SheetSprite.h"
#include "App.h"

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

void ClassDemoApp::processEvents(Entity* player){
	player->setDirection_x(0);
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_LEFT]){
		player->setDirection_x(-1);
	}
	else if (keys[SDL_SCANCODE_RIGHT]){
		player->setDirection_x(1);
	}
}

void ClassDemoApp::Render() {
	player->draw(1.0f);
	for (Entity* entity : enemies){
		entity->draw(1.0f);
	}
	for (Entity* bullet : bullets){
		bullet->draw(1.0f);
	}
	SDL_GL_SwapWindow(displayWindow);
}

void ClassDemoApp::Update(float elapsed) {
	SDL_Event event;
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

void ClassDemoApp::killEntity(Entity* entity){
	for (Entity* entityPtr : enemies){
		if (entityPtr == entity){
			entityPtr == NULL;
		}
	}
}

void ClassDemoApp::fireBullet(Entity* shooter){
	Entity newBullet();
}

GLuint ClassDemoApp::LoadTexture(std::string image_path_str){
	const char* image_path = image_path_str.c_str();
	SDL_Surface *surface = IMG_Load(image_path);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(surface);
	return textureID;
}