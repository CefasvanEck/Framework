#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <string>

class Entity
{

public:
	Entity(std::string texture = "assets/missingtexture.tga", glm::vec3 position = glm::vec3(500,500,0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));

	virtual ~Entity();


	glm::vec3 getPosition()
	{
		return this->position;
	}

	glm::vec3 getRotation()
	{
		return this->rotation;
	}

	glm::vec3 getScale()
	{
		return this->scale;
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