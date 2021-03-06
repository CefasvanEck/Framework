#include <common/camera.h>

glm::mat4 viewMatrix;
glm::mat4 getViewMatrix()
{
	return viewMatrix;
}

glm::vec3 cursor = glm::vec3( 0, 0, 0 );
glm::vec3 getCursor()
{
	return cursor;
}

void computeMatricesFromInputs(GLFWwindow* window, float deltaTime)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );

	// Right and Up vector
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);

	static glm::vec3 position = glm::vec3( 0, 0, 10 ); // Initial position : on +Z
	float speed = 300.0f; // units / second

	// Move up
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += up * deltaTime * speed;
	}
	// Move down
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position -= up * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position -= right * deltaTime * speed;
	}

	// View matrix
	viewMatrix = glm::lookAt(
	position, /* Camera is at (xpos,ypos,zpos), in World Space */
	position + glm::vec3(0, 0, -1), /* and looks towards Z */
	glm::vec3(0, 1, 0)  /* Head is up (set to 0,-1,0 to look upside-down) */
	);
}
