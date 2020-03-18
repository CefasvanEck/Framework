#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <common/camera.h>
#include <common/renderer.h>
#include <common/ShaderProgram.h>

#include "demo/Main.h"

Renderer::Renderer(unsigned int w, unsigned int h)
{
	_window_width = w;
	_window_height = h;
	shaderProgram = new ShaderProgram();
	this->init();
}

Renderer::~Renderer()
{
	// Cleanup VBO and shader
	shaderProgram->deleteShader();
	delete shaderProgram;
}

int Renderer::init()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Open a window and create its OpenGL context
	_window = glfwCreateWindow(_window_width, _window_height, "Demo", NULL, NULL);
	if (_window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	_projectionMatrix = glm::ortho(0.0f, (float)_window_width, (float)_window_height, 0.0f, 0.1f, 100.0f);

	return 0;
}

float Renderer::updateDeltaTime() {
	// lastTime is initialised only the first time this function is called
	static double lastTime = glfwGetTime();
	// get the current time
	double currentTime = glfwGetTime();

	// Compute time difference between current and last time
	float deltaTime = float(currentTime - lastTime);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
	return deltaTime;
}

void Renderer::renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot)
{
	//When an Entity has been added to the scene, the sprite will be created with the option for a different shader.
	//I added the code below in the renderSprite and not the init() because I don't want to go through the list again to check if there is a
	//new Entity with a Sprite.
	//Also, there can be a new Entity with a new Shader that didn't exists when you started the game so now it will load while "playing" the game.
	//Just make sure you don't add to many new Entities with new Shaders case that can created fps issues.
	if (sprite->getShaderID() == -1)
	{
		// Create and compile our GLSL program from the shaders	
		sprite->setShaderID(Main::getInstance().getResourcemanager()->loadShader(shaderProgram, sprite->getShaderPath()));
		//Load shader
		std::string shaderIDLoaded = Main::getInstance().getConsole()->toS(sprite->getShaderID());
	}
	else
	{
		//Use shader
		shaderProgram->useShaderProgram(sprite->getShaderID());
	}

	glm::mat4 viewMatrix = getViewMatrix(); // get from Camera (Camera position and direction)

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(px, py, 0.0f));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, rot);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(sx, sy, 1.0f));


	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = _projectionMatrix * viewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint matrixID = glGetUniformLocation(sprite->getShaderID(), "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sprite->texture());
	// Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = glGetUniformLocation(sprite->getShaderID(), "textureSampler");
	glUniform1i(textureID, 0);

	// 1st attribute buffer : vertices
	GLuint vertexPositionID = glGetAttribLocation(sprite->getShaderID(), "vertexPosition");
	glEnableVertexAttribArray(vertexPositionID);
	glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexbuffer());
	glVertexAttribPointer(
		vertexPositionID, // The attribute we want to configure
		3,          // size : x+y+z => 3
		GL_FLOAT,   // type
		GL_FALSE,   // normalized?
		0,          // stride
		(void*)0    // array buffer offset
	);

	// 2nd attribute buffer : UVs
	GLuint vertexUVID = glGetAttribLocation(sprite->getShaderID(), "vertexUV");
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, sprite->uvbuffer());
	glVertexAttribPointer(
		vertexUVID, // The attribute we want to configure
		2,          // size : U+V => 2
		GL_FLOAT,   // type
		GL_FALSE,   // normalized?
		0,          // stride
		(void*)0    // array buffer offset
	);

	// Draw the triangles
	glDrawArrays(GL_TRIANGLES, 0, 2 * 3); // 2*3 indices starting at 0 -> 2 triangles

	glDisableVertexAttribArray(vertexPositionID);
	glDisableVertexAttribArray(vertexUVID);
}