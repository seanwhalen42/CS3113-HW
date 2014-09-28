
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "ClassDemoApp.h"
#include "sprite.h"
#include "Entity.h"
#include "Bullet.h"

SDL_Window* displayWindow;
std::vector<Entity> bullets;

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

SheetSprite::SheetSprite(unsigned int textureID, float u, float v, float width, float height) : textureID(textureID), u(u), v(v), width(width), height(height) {}

void SheetSprite::Draw(float x, float y, float scale) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	GLfloat quad[] = { -width * scale, height * scale, -width * scale, -height * scale,
	width * scale, -height * scale, width * scale, height * scale };
	GLfloat quadUVs[] = { u, v, u, v + height, u + width, v + height, u + width, v };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 0, quadUVs);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();
}

Bullet::Bullet(float x, float y, SheetSprite sprite) : x(x), y(y), sprite(sprite) {}

void Bullet::Draw(){
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 0, );
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glLoadIdentity();
}

void fireBullet(float x, float y, float direction_y){
	Entity newBullet;
}

enum GameState { STATE_MAIN_MENU, STATE_GAME_LEVEL };

int state;

void ClassDemoApp::Render() {
	switch (state) {
	case STATE_MAIN_MENU:
		//RenderMainMenu();
		break;
	case STATE_GAME_LEVEL:
		//RenderGameLevel();
		break;
	}
}

void ClassDemoApp::Update() {
	switch (state) {
	case STATE_MAIN_MENU:
		//UpdateMainMenu();
		break;
	case STATE_GAME_LEVEL:
		//UpdateGameLevel();
		break;
	}
}

int main(int argc, char *argv[])
{
	ClassDemoApp app;
	while (!app.UpdateAndRender()) {}
	return 0;
}