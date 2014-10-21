#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Config.h"

class App{
public:
	void fixedUpdate();
private:
	float timeLeftOver = 0.0f;
};