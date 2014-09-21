#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>

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
	Entity(float array[8], std::string texture, float r){
		texture = LoadTexture(texture);
		x = (array[1] + array[7]) / 2;
		y = (array[2] + array[4]) / 2;
		
		rotation = r;
		
		width = array[3] - array[1];
		height = array[2] - array[4];

		top = array[2];
		bottom = array[4];
		left = array[1];
		right = array[7];
	}

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
		return top;
	}

	float getBottom(){
		return bottom;
	}

	float getLeft(){
		return left;
	}

	float getRight(){
		return right;
	}

	void draw(){

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

	float top;
	float bottom;

	float left;
	float right;
};

bool collisionDetect(Entity entityA, Entity entityB) {
	return (entityA.getBottom() >= entityB.getTop() || entityA.getTop() <= entityB.getBottom() || entityA.getLeft() >= entityB.getRight() ||
		entityA.getRight() <= entityB.getLeft());
}