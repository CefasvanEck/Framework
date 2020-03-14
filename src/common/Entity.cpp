#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>
#include "demo/Main.h"

Entity::Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = new Sprite(texture);
	//this->setScale(glm::vec3(1,1,1));
	Main::getInstance().getConsole()->println(this->getScale().x);
}


void Entity::updateOnFrame(){}



void Entity::updateFixed(){}

Entity::~Entity(){}