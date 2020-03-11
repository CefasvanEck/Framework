#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>

Entity::Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = new Sprite(texture);
	this->position = glm::vec3(500, 500, 0);
	this->rotation = glm::vec3(0, 0, 0),
	this->scale = glm::vec3(1, 1, 1);
}


void Entity::updateOnFrame(){}



void Entity::updateFixed(){}

Entity::~Entity(){}