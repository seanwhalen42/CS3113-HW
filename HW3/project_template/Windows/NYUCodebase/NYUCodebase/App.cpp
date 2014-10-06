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
	GLuint sheet = ClassDemoApp::LoadTexture("sheet.png");
	playerSprite = SheetSprite(sheet, 224.0f/*u*/, 832.0f/*v*/, 99.0f/*width*/, 75.0f/*height*/);
	enemySprite = SheetSprite(sheet, 144.0f, 156.0f, 103.0f, 84.0f);
	bulletSprite = SheetSprite(sheet, 856.0f, 869.0f, 9.0f, 57.0f);
	Entity playerEntity = Entity(-0.8f, 0.0f, 1, playerSprite);
	player = &playerEntity;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 5; j++){
			Entity enemyEntity = Entity((j*0.5) - 1, 0.8 - i*0.26, 1, enemySprite);
			enemies.push_back(&enemyEntity);
		}
	}
}

ClassDemoApp::~ClassDemoApp() {
	SDL_Quit();
}

void ClassDemoApp::processEvents(){
	player->setDirection_x(0);
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_LEFT]){
		player->setDirection_x(-1);
	}
	else if (keys[SDL_SCANCODE_RIGHT]){
		player->setDirection_x(1);
	}
	else if (keys[SDL_SCANCODE_SPACE]){
		fireBullet(player);
	}
	for (Entity* enemy : enemies){
		if (rand() % 100 == 0){//emeies should fire about once every two seconds
			fireBullet(enemy);
		}
		for (Entity* bullet : bullets){
			if (collisionDetect(enemy, bullet)){
				killEntity(enemy);
			}
		}
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
	processEvents();
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
	if (shooter == player){
		Entity newBullet(shooter->getX(), shooter->getTop() + (1/600), 2, bulletSprite);
		newBullet.setDirection_x(0);
		newBullet.setDirection_y(1);
		bullets.push_back(&newBullet);
	}
	else{
		Entity newBullet(shooter->getX(), shooter->getBottom() - (1 / 600), 2, bulletSprite);
		newBullet.setDirection_x(0);
		newBullet.setDirection_y(-1);
		bullets.push_back(&newBullet);
	}
}

bool ClassDemoApp::shouldRemove(Entity* bullet){
	return (bullet->getBottom() > 1 || bullet->getTop() < -1);
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

bool ClassDemoApp::collisionDetect(Entity* entityA, Entity* entityB) {
	if (entityA->getCollide() && entityB->getCollide()){
		return !(entityA->getBottom() >= entityB->getTop() || entityA->getTop() <= entityB->getBottom() || entityA->getLeft() >= entityB->getRight() ||
			entityA->getRight() <= entityB->getLeft());
	}
	else {
		return false;
	}
}