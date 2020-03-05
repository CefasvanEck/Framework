// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/Entity.h>

#include <vector>
#include <fstream>
#include <iostream> 

std::vector<Entity*> entityList;

void println(std::string texttoconsole)
{
	std::cout << texttoconsole << std::endl;
}

std::string toS(float toString)
{
	return std::to_string(toString);
}

std::string toS(int toString)
{
	return std::to_string(toString);
}

int main( void )
{
	Renderer renderer(1280, 720);

	entityList.push_back(new Entity("rgba", glm::vec3(400,300,0)));
	entityList.push_back(new Entity("kingkong", glm::vec3(900, 400, 0)));
	entityList.push_back(new Entity("pencils", glm::vec3(200, 400, 0)));

	do 
	{
		// Update deltaTime
		float deltaTime = renderer.updateDeltaTime();

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window(), deltaTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glm::vec3 cursor = getCursor(); // from Camera
		// printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		for (int i = 0; i < entityList.size(); i++)
		{
			renderer.renderSprite(entityList[i]->getSprite(), entityList[i]->getPosition().x, entityList[i]->getPosition().y, entityList[i]->getScale().x, entityList[i]->getScale().y, entityList[i]->getRotation().x);
			entityList[i]->updateOnFrame();
			
			println(toS(deltaTime));
		}

		static float rot_z = 0.0f;
		rot_z += 3.141592f / 2 * deltaTime;

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0 );
	for (int i = 0; i < entityList.size(); i++)
	{
		delete entityList[i]->getSprite();
	}

	entityList.clear();
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
