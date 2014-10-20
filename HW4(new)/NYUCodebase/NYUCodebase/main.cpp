
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

SDL_Window* displayWindow;

void drawBox(float x, float y, float height, float width){
	float vertexArray[8] = { x - (width / 2), y + (height / 2), x - (width / 2), y - (height / 2), x + (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };
	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertexArray);
	glLoadIdentity();
	glDrawArrays(GL_QUADS, 0, 4);
}

void setup(){
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1, 1, -1, 1);//Affects projection matrix
}

int main(int argc, char *argv[])
{
	setup();

	bool done = false;
	
	SDL_Event event;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
		drawBox(0, 0, 0.5, 0.5);
		drawBox(1, 1, 0.1, 0.1);
		SDL_GL_SwapWindow(displayWindow);
	}

	SDL_Quit();
	return 0;
}

