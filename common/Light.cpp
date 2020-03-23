#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "common/Light.h"

Light::Light(glm::vec3 pos, float colourR, float colourG, float colourB)
{
	this->colour = glm::vec3(colourR * 0.00392156862745098F, colourG * 0.00392156862745098F, colourB * 0.00392156862745098F);
	this->attenuation = glm::vec3(1, 0, 0);
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

glm::vec3 Light::getColour()
{
	return colour;
}

void Light::setColour(glm::vec3 theColour)
{
	colour = theColour;
}

glm::vec3 Light::getAttenuation()
{
	return attenuation;
}