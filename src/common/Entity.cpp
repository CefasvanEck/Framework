//This file was added by Cefas

#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>
#include "demo/Main.h"

Entity::Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = new Sprite(texture);

	/**
	 * For some reason the scale wil have a negative value while it is set in the constructor(see Entity.h)
	 Note: why is scale -431602080.000000 and not 1? (glm::vec3 scale = glm::vec3(0, 0, 0) in constructor Entity.h)
	 For some reason the scale is uninitialized?
	 */
	Main::getInstance().getConsole()->println(this->getScale().x);
	this->setScale(glm::vec3(1,1,1));
	Main::getInstance().getConsole()->println(this->getScale().x);
}


void Entity::updateOnFrame(){}



void Entity::updateFixed(){}

Entity::~Entity(){}