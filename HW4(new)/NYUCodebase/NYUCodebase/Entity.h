#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>

class Entity{
public:
	Entity();
	Entity(float x, float y, float height, float width, std::string img_path_str);
	~Entity();
	void draw();
private:
	float x;
	float y;
	float height;
	float width;
	GLuint texture;
};