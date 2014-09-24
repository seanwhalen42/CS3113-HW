
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <vector>
#include "main.h"

//SDL_Window* displayWindow;

void drawNet() {
	float net[8] = { -0.025, 1, -0.025, -1, 0.025, -1, 0.025, 1 };
	glVertexPointer(2, GL_FLOAT, 0, net);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
};

std::vector < Entity* > Entities ;

float paddleArray[8] = { -0.025, .1, -0.025, -.1, 0.025, -0.1, 0.025, 0.1 };
float goalArray[8] = { -0.2, 1, -0.2, -1, 0.2, -1, 0.2, 1 };
float ballArray[8] = { -0.05, 0.05, -0.05, -0.05, 0.05, -0.05, 0.05, 0.05 };

Entity leftPaddle(paddleArray, -1.28, 0);
Entity rightPaddle(paddleArray, 1.28, 0);
Entity leftGoal(goalArray, -1.66, 0);
Entity rightGoal(goalArray, 1.66, 0);
Entity ball(ballArray, 0, 0);


int main(int argc, char *argv[])
{
	setup();
	Entities.push_back(&leftPaddle);
	Entities.push_back(&rightPaddle);
	Entities.push_back(&leftGoal);
	Entities.push_back(&rightGoal);
	Entities.push_back(&ball);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.33, 1.33, -1.0, 1.0, -1.0, 1.0);
	ball.setDirection_x(1);
	ball.setDirection_y(1);
	bool done = false;
	
	SDL_Event event;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		processEvents(leftPaddle, rightPaddle);
		update(Entities);
		draw(Entities);
		drawNet();
		SDL_GL_SwapWindow(displayWindow);
	}

	SDL_Quit();
	return 0;
}