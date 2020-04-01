//This file was added by Cefas

#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>
#include "demo/Main.h"

Entity::Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = Main::getInstance().getResourcemanager()->loadTexture(texture);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);
}

Entity::Entity(std::string texture, std::string shaderPath, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->sprite = Main::getInstance().getResourcemanager()->loadTextureWithShader(texture, shaderPath);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);
}

void Entity::updateOnFrame(){}

void Entity::updateFixed(){}

Entity::~Entity(){}