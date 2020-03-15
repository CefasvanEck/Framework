//This file was added by Cefas

#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>
#include "demo/Main.h"

Entity::Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = new Sprite(texture);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);
}


void Entity::updateOnFrame(){}



void Entity::updateFixed(){}

Entity::~Entity(){}