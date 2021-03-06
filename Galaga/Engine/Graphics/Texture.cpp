#include "Texture.h"

Texture::Texture()
{
	// because the GL id are >= 0, this creates something like an 'empty' texture or a non-initialized texture
	id = -1;
}

Texture::Texture(const int& _id)
{
	// to copy a texture, just grab the id from an existing texture and pass it into here. the texture is already loaded in gl
	// and only needs the id to relate to what is stored in memory by GL
	id = _id;
	if (!GetTextureParams()) {
		std::cout << "Error loading image with ID: " << id << std::endl;
	}
}

Texture::Texture(const std::string& path)
{
	// deals with GL directly, loads the texture and gives it an id
	// textures are loading into memory tied to an id > 0. if the id is <= 0, then the texture does not exist or failed to load
	// after the texture is assigned an id, flags are sent in to handle alpha and invert the y
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams()) {
		std::cout << "Error loading image: " << path << std::endl;
	}
}

int Texture::GetID() const
{
	return id;
}

int Texture::GetWidth() const 
{
	return width;
}

int Texture::GetHeight() const
{
	return height;
}


bool Texture::GetTextureParams()
{
	
	if (id > 0) {
		int mipLevel = 0;
		// to get the parameters, we need to let GL know which texture we are referring to. binds the id to GL_TEXTURE_2D
		glBindTexture(GL_TEXTURE_2D, id);

		// get the width and height from the bound texture, set to width and height (given the pointers)
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}

	return false;
}