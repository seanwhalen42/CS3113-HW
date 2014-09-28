#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>

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
	std::vector<Entity> entities;
	SDL_Window* displayWindow;
};