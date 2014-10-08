#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "Entity.h"
#include "SheetSprite.h"


class ClassDemoApp {
public:
	ClassDemoApp();
	~ClassDemoApp();
	void Init();
	void processEvents(Entity* player);
	bool UpdateAndRender();
	void Render();
	void Update(float elapsed);
	void killEntity(Entity* entity);
	void fireBullet(Entity* shooter);
	GLuint LoadTexture(std::string image_path_str);
private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
	Entity* player;
	std::vector<Entity*> enemies;
	std::vector<Entity*> bullets;
	enum gameState;
};