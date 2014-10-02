#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
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
private:
	bool done;
	float lastFrameTicks;
	SDL_Window* displayWindow;
};