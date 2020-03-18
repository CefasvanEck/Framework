//This file was added by Cefas

#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <string>

class Entity
{

public:
	Entity(std::string texture = "assets/missingtexture.tga", glm::vec3 position = glm::vec3(0,0,0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));
	Entity(std::string texture = "assets/missingtexture.tga", std::string shaderPath = "shader/sprite", glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));

	virtual ~Entity();

	glm::vec3 getPosition()
	{
		return this->position;
	}

	void setPosition(glm::vec3 setPosition)
	{
		this->position = setPosition;
	}

	glm::vec3 getRotation()
	{
		return this->rotation;
	}

	void setRotation(glm::vec3 setRotation)
	{
		this->rotation = setRotation;
	}

	void setScale(glm::vec3 setScale)
	{
		this->scale = setScale;
	}

	void addScale(glm::vec3 addScale)
	{
		this->scale += addScale;
	}

	glm::vec3 getScale()
	{
		return this->scale;
	}

	void setSprite(Sprite* theSpirte)
	{
		this->sprite = theSpirte;
	}

	Entity::Sprite *getSprite()
	{
		return this->sprite;
	}

	void updateFixed();
	void updateOnFrame();

private:

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	Sprite* sprite;

protected:

};

#endif /* SPRITE_H */