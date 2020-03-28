#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "common/Light.h"

/*
This will set a light with a position, color RGB and attenuation(distance of the light)
Color goes from 0 to 255
*/
Light::Light(glm::vec3 position, glm::vec3 color, glm::vec3 attenuation)
{
	this->setPosition(glm::vec3(position.x / 100.0F, position.y / 100.0F, position.z / 100.0F));
	this->setColour(glm::vec3(color.x, color.y, color.z));
	this->attenuation = attenuation;
}

Light::~Light()
{

}

glm::vec3 Light::getPosition()
{
	return position;
}

void Light::setPosition(glm::vec3 thePosition)
{
	position = thePosition;
}

/*
Get the light color from 0 to 1
*/
glm::vec3 Light::getColour()
{
	return colour;
}

/*
Set the color from 0 to 255
*/
void Light::setColour(glm::vec3 theColour)
{
	colour = glm::vec3(theColour.x * 0.00392156862745098F, theColour.y * 0.00392156862745098F, theColour.z * 0.00392156862745098F);
}

glm::vec3 Light::getAttenuation()
{
	return attenuation;
}