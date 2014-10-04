#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "Entity.h"
#include "SheetSprite.h"

class ClassDemoApp {
public:
	ClassDemoApp();
	~ClassDemoApp();
	void Init();
	bool UpdateAndRender();
	void Render();
	void Update(float elapsed);
	void killEntity(Entity* entity);
private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
	std::vector<Entity*> entities;
};