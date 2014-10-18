#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "App.h"

enum GameState { STATE_TITLE, STATE_GAME, STATE_GAME_OVER };

App::App(){
	init();
	done = false;
	lastFrameTicks = 0;
}

App::~App(){
	SDL_Quit();
}

void App::init() {
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	GameState state = STATE_TITLE;
}

void App::update(float elapsed) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
			done = true;
		}
	}
}

GLuint App::LoadTexture(std::string image_path_str){
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

void App::drawTitle(){
	GLuint fontTexture = LoadTexture("font1.png");
	int titleArray[14] = { 83, 112, 97, 99, 101, 32, 73, 110, 118, 97, 100, 101, 114, 115 }; //Space Invaders
	for (int i : titleArray){
		SheetSprite charSprite = decodeFromIndex(i, 16, 16, fontTexture);
		charSprite.draw(-216 + 32 * i, 0, 1);
	}
}

void App::makeWall(GLuint texture, float wallStart, float wallHeight){

}

void App::collisionCheck(Entity* entityA, Entity* entityB){
	entityA->clearCollisionFlags();
	entityB->clearCollisionFlags();
	if (entityA->getBottom() < entityB->getTop() && entityA->getBottom() > entityB->getBottom()){
		entityA->setCollisionBottom(true);
		entityB->setCollisionTop(true);
	}
	
	if (entityA->getTop() > entityB->getBottom() && entityA->getTop() < entityB->getTop()){
		entityA->setCollisionTop(true);
		entityB->setCollisionBottom(true);
	}

	if (entityA->getRight() > entityB->getLeft() && entityA->getLeft() < entityB->getRight()){
		entityA->setCollisionRight(true);
		entityB->setCollisionLeft(true);
	}
	
	if (entityA->getLeft() < entityB->getRight() && entityA->getRight() < entityB->getRight()){
		entityA->setCollisionLeft(true);
		entityB->setCollisionRight(true);
	}
}

float App::calculatePenetrationX(Entity* entityA, Entity* entityB){
	return abs(entityA->getX() - entityB->getX());
}

float App::calculatePenetrationY(Entity* entityA, Entity* entityB){
	return abs(entityA->getX() - entityB->getX());
}

SheetSprite App::decodeFromIndex(int index, int spriteCountX, int spriteCountY, GLuint texture){
	float u = (index % spriteCountX) / spriteCountX;
	float v = (index / spriteCountX) / spriteCountY;
	float spriteWidth = 1 / spriteCountX;
	float spriteHeight = 1 / spriteCountY;
	SheetSprite sprite = SheetSprite(texture, u, v, spriteWidth, spriteHeight);
	return sprite;
}

void App::renderFont(std::string str){

}