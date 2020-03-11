#include <demo/Main.h>
#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/Entity.h>

#include <vector>
#include <fstream>
#include <iostream> 

/*
A wrapper around std::cout << "text here" << std::endl;
*/
void println(std::string texttoconsole)
{
	std::cout << texttoconsole << std::endl;
}

/*
Print a float
*/
void  println(float toString)
{
	std::cout << std::to_string(toString) << std::endl;
}

//Print an int
void  println(int toString)
{
	std::cout << std::to_string(toString) << std::endl;
}

std::string  toS(float toString)
{
	return std::to_string(toString);
}

std::string toS(int toString)
{
	return std::to_string(toString);
}

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
			renderer.renderSprite(main.getEntityList()[i]->getSprite(), main.getEntityList()[i]->getPosition().x, main.getEntityList()[i]->getPosition().y, main.getEntityList()[i]->getScale().x, main.getEntityList()[i]->getScale().y, main.getEntityList()[i]->getRotation().x);
			main.getEntityList()[i]->updateOnFrame();
			updateOnDeltaTimer += deltaTime;
			if (updateOnDeltaTimer > 1)
			{
				main.getEntityList()[i]->updateFixed();	
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
