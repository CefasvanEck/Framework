//This file was changed a bit by Cefas

#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>

class Sprite
{
	public:
		Sprite(const std::string& imagepath);
		virtual ~Sprite();

		GLuint texture() { return _texture; };
		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint uvbuffer() { return _uvbuffer; };

		unsigned int getWidth() { return _width; };
		unsigned int getHeight() { return _height; };

		void setWidth(float width);
		void setHeight(float height);

		GLuint loadNewTGA(const std::string& imagepath);

		void setTextureID(GLuint textureID);
		void setShaderID(GLuint shaderID);
		void setShaderPath(const std::string& imagepath);

		GLuint getShaderID();

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint shaderProgramID;

		std::string shaderpath;

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		unsigned int _width;
		unsigned int _height;
};

#endif /* SPRITE_H */
