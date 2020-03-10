#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/Entity.h"
#include <string>

Entity::Entity(std::string texture)
{
	this->sprite = new Sprite("assets/" + texture + ".tga");
	this->position = glm::vec3(0, 0, 0);
	this->rotation = glm::vec3(0, 0, 0);
	this->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->updateOnDeltaTimer = 0;
}

Entity::Entity(std::string texture, glm::vec3 thePosition)
{
	this->sprite = new Sprite("assets/" + texture + ".tga");
	this->position = thePosition;
	this->rotation = glm::vec3(0, 0, 0);
	this->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->updateOnDeltaTimer = 0;
}

Entity::Entity(std::string texture, glm::vec3 thePosition, glm::vec3 theRotation)
{
	this->sprite = new Sprite("assets/" + texture + ".tga");
	this->position = thePosition;
	this->rotation = theRotation;
	this->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->updateOnDeltaTimer = 0;
}

Entity::Entity(glm::vec3 thePosition, glm::vec3 theScale, std::string texture)
{
	this->sprite = new Sprite("assets/" + texture + ".tga");
	this->position = thePosition;
	this->rotation = glm::vec3(0, 0, 0);
	this->scale = theScale;
	this->updateOnDeltaTimer = 0;
}

Entity::Entity(std::string texture,glm::vec3 thePosition, glm::vec3 theRotation, glm::vec3 theScale)
{
	this->sprite = new Sprite("assets/" + texture + ".tga");
	this->position = thePosition;
	this->rotation = theRotation;
	this->scale = theScale;
	this->updateOnDeltaTimer = 0;
}

void Entity::updateOnFrame(){}


int type;

void Entity::updateFixed() 
{	
	if (type == 0)
	{
		delete this->sprite;
		this->sprite = new Sprite("assets/kingkong.tga");
	}
	if (type == 1)
	{
		delete this->sprite;
		this->sprite = new Sprite("assets/pencils.tga");
	}
	if (type == 2)
	{
		delete this->sprite;
		this->sprite = new Sprite("assets/rgba.tga");
	}
	++type;
	if (type > 2)
	{
		type = 0;
	}
}

//pencils
//rgba

Entity::~Entity(){}