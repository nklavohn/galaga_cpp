#ifndef ENGINE_TEXTURE
#define ENGINE_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL2/SOIL2.h"

#include <iostream>
#include <string>

class Texture {

public:
	Texture();
	Texture(int _id);
	Texture(std::string path);

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};

#endif