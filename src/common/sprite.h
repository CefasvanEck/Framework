#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>

class Sprite
{
	public:
		Sprite(const std::string& imagepath);
		Sprite(const std::string& imagepath, float scaleX, float scaleY);
		virtual ~Sprite();

		GLuint texture() { return _texture; };
		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint uvbuffer() { return _uvbuffer; };

		unsigned int width() { return _width; };
		unsigned int height() { return _height; };

		void loadNewTGA(const std::string& imagepath);

	private:
		GLuint loadTGA(const std::string& imagepath);

		GLuint _texture;
		GLuint _vertexbuffer;
		GLuint _uvbuffer;

		unsigned int _width;
		unsigned int _height;
};

#endif /* SPRITE_H */
