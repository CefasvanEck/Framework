//This file was changed a bit by Cefas

#include <demo/Main.h>
#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/Entity.h>

#include <vector>
#include <fstream>
#include <iostream> 
#include "demo/Main.h"

float updateOnDeltaTimer;

int main( void )
{
	Renderer renderer(1280, 720);
	Main main;
	
	main.start();
	
	do 
	{
		main.running();
		// Update deltaTime
		float deltaTime = renderer.updateDeltaTime();

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window(), deltaTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glm::vec3 cursor = getCursor(); // from Camera
		// printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		for (int i = 0; i < main.getEntityList().size(); i++)
		{
			Entity* entity = main.getEntityList()[i];
			renderer.renderSprite(entity->getSprite(), entity->getPosition().x, entity->getPosition().y, entity->getScale().x, entity->getScale().y, entity->getRotation().x);
			entity->updateOnFrame();

			updateOnDeltaTimer += deltaTime;
			if (updateOnDeltaTimer > 1)
			{
				entity->updateFixed();
				main.fixedRunning();
			}
		}

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0 );
	for (int i = 0; i < main.getEntityList().size(); i++)
	{
		delete main.getEntityList()[i]->getSprite();
	}
	main.closing();
	main.getEntityList().clear();
	
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
