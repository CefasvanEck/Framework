#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <common/camera.h>
#include <common/renderer.h>
#include <common/ShaderProgram.h>
#include <demo/Main.h>
#include "common/Light.h"

Renderer::Renderer(unsigned int w, unsigned int h)
{
	_window_width = w;
	_window_height = h;
	this->shaderProgram = new ShaderProgram();
	this->init();
	//Note to myself: do not forget the .0F or else it will be a double and NOT a float
	
	float sunLight = 55.0F;
	


	//Create the first light in the framework
	this->addLight(new Light(glm::vec3(0.0F, 0.0F, 0.0F), glm::vec3(255.0F, 0.0F, 0.0F), glm::vec3(1.0F, 3.0F, 0.00001F)));


	this->addLight(new Light(glm::vec3(0.0F, 0.0F, 0.0F), glm::vec3(sunLight, sunLight, sunLight), glm::vec3(1.0F, 0.0F, 0.0F)));
}

Renderer::~Renderer()
{
	// Cleanup VBO and shader
	this->shaderProgram->deleteShader();
	delete this->shaderProgram;
	for (int i = 0; i < this->getLightList().size(); ++i)
	{
		delete this->getLightList()[i];
	}
	this->getLightList().clear();
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

std::vector<Light*> Renderer::getLightList()
{
	return this->lightList;
}

void Renderer::addLight(Light* light)
{
	this->lightList.push_back(light);
}

std::vector<StaticShader*> Renderer::getStaticShaderList()
{
	return this->staticShaderList;
}

void Renderer::addStaticShader(StaticShader* shader)
{
	this->staticShaderList.push_back(shader);
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
		sprite->setShaderID(Main::getInstance().getResourcemanager()->loadShader(this->shaderProgram, sprite->getShaderPath()));
		//Load shader
		this->addStaticShader(new StaticShader(sprite->getShaderID()));
	}
	else
	{
		//Use shader
		this->shaderProgram->useShaderProgram(sprite->getShaderID());
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

	//Send vieuwMatrix, translationMatrix/transformationMatrix and modelMatrix to the shader for 2D lightning calculation
	//Vieuw matrix to shader
	GLuint vieuwMatrixID = glGetUniformLocation(sprite->getShaderID(), "viewMatrix");
	glUniformMatrix4fv(vieuwMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);
	//transformation Matrix to shader
	GLuint translationMatrixID = glGetUniformLocation(sprite->getShaderID(), "transformationMatrix");
	glUniformMatrix4fv(translationMatrixID, 1, GL_FALSE, &translationMatrix[0][0]);
	//model ViewMatrix Matrix to shader
	GLuint modelMatrixMatrixID = glGetUniformLocation(sprite->getShaderID(), "modelViewMatrix");
	glUniformMatrix4fv(modelMatrixMatrixID, 1, GL_FALSE, &modelMatrix[0][0]);

	GLuint idMaxLights = glGetUniformLocation(sprite->getShaderID(), "maxLights");

	int maxLights = this->getStaticShaderList()[0]->getMaxLights();
	glUniform1i(idMaxLights, this->getLightList().size());

	//Loading and sending to shader
	for (int i = 0; i < this->getLightList().size(); ++i)
	{
		Light* light = this->getLightList()[i];
		//Load position of the light
		std::string lightPositionString = "lightPosition[" + std::to_string(i) + "]";
		GLuint idPos = glGetUniformLocation(sprite->getShaderID(), lightPositionString.c_str());
		//End
		//Load colour/color of the light
		std::string lightColourString = "lightColour[" + std::to_string(i) + "]";
		GLuint idCol = glGetUniformLocation(sprite->getShaderID(), lightColourString.c_str());
		//Load attenuation of the light
		std::string lightAttenuationString = "lightAttenuation[" + std::to_string(i) + "]";
		GLuint idAtt = glGetUniformLocation(sprite->getShaderID(), lightAttenuationString.c_str());
		//End
		//Movinh the red light just for testing, later removed
		if (i == 0)
		{
			light->setPosition(glm::vec3(light->getPosition()[0] + 0.5F, light->getPosition()[1], light->getPosition()[2]));
		}
		
		//Position
		glUniform3f(idPos, light->getPosition()[0], light->getPosition()[1], light->getPosition()[2]);
		//Colour RGBA
		glUniform3f(idCol, light->getColour()[0], light->getColour()[1], light->getColour()[2]);
		//Attenuation
		glUniform3f(idAtt, light->getAttenuation()[0], light->getAttenuation()[1], light->getAttenuation()[2]);
	}

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