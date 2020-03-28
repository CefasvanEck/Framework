#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>
#include <common/sprite.h>
#include <common/ShaderProgram.h>
#include <common/StaticShader.h>
#include <demo/Main.h>
#include "common/Light.h"

class Renderer
{
	public:
		Renderer(unsigned int w, unsigned int h);
		virtual ~Renderer();

		void renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);
		GLFWwindow* window() { return _window; };

		unsigned int width() { return _window_width; };
		unsigned int height() { return _window_height; };

		float updateDeltaTime();

		std::vector<Light*> getLightList();
		void addLight(Light* light);

		std::vector<StaticShader*> getStaticShaderList();
		void addStaticShader(StaticShader* shader);

	private:
		int init();
		std::vector<StaticShader*> staticShaderList;
		std::vector<Light*> lightList;

		ShaderProgram* shaderProgram;
		StaticShader* staticShader;

		GLFWwindow* _window;
		unsigned int _window_width;
		unsigned int _window_height;

		glm::mat4 _projectionMatrix;
};

#endif /* RENDERER_H */
