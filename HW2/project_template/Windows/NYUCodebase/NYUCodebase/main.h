#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>
#include <vector>

SDL_Window* displayWindow;

GLuint LoadTexture(std::string image_path_str) {
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

class Entity {
public:
	Entity(float array[], float x, float y, std::string texture = " "): x(x), y(y){
		if (texture != " "){
			texture = LoadTexture(texture);
		}

		//x = (array[1] + array[7]) / 2;
		//y = (array[2] + array[4]) / 2;
		
		width = array[3] - array[1];
		height = array[2] - array[4];

		for (int i = 0; i<8; i++){
			vertexArray[i] = array[i];
		}
		speed = 1;
		direction_x = 0;
		direction_y = 0;
	}

	//Accessors

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	float getHeight() {
		return height;
	}

	float getWidth() {
		return width;
	}
	
	float getSpeed() {
		return speed;
	}

	float getTop() {
		float top = (y + (height / 2));
		return top;
	}

	float getBottom(){
		float bottom = (y - (height / 2));
		return bottom;
	}

	float getLeft(){
		float left = (x - (width / 2));
		return left;
	}

	float getRight(){
		float right = (x + (width / 2));
		return right;
	}
	void draw(){
		glMatrixMode(GL_MODELVIEW);
		glEnableClientState(GL_VERTEX_ARRAY);
		glTranslatef(x, y, 0);
		glVertexPointer(2, GL_FLOAT, 0, vertexArray);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		glLoadIdentity();
	}
	//Mutators

	void setDirection_x(float newX){
		direction_x = newX;
	}

	void setDirection_y(float newY){
		direction_y = newY;
	}

	void update() {
		x += direction_x * speed;
		y += direction_y * speed;
	}

	

private:
	float x;
	float y;
	float rotation;

	GLuint textureID;
	float width;
	float height;
	
	float speed;
	float direction_x;
	float direction_y;

	float vertexArray[8];
};

bool collisionDetect(Entity entityA, Entity entityB) {
	return (entityA.getBottom() >= entityB.getTop() || entityA.getTop() <= entityB.getBottom() || entityA.getLeft() >= entityB.getRight() ||
		entityA.getRight() <= entityB.getLeft());
}

void setup() {
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);
};

void update(std::vector<Entity> Entities) {
	for (Entity i : Entities){
		i.update();
	}
}

void draw(std::vector<Entity> Entities) {
	for (Entity i : Entities){
		i.draw();
	}
}

void processEvents(Entity leftPaddle, Entity rightPaddle){
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_UP]){
		rightPaddle.setDirection_y(1);
	}
	else if (keys[SDL_SCANCODE_DOWN]){
		rightPaddle.setDirection_y(-1);
	}
	if (keys[SDL_SCANCODE_W]){
		leftPaddle.setDirection_y(1);
	}
	else if (keys[SDL_SCANCODE_S]){
		rightPaddle.setDirection_y(-1);
	}
}