#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <string>

class Entity
{

public:

	Entity(std::string texture);
	Entity(std::string texture, glm::vec3 position);
	Entity(std::string texture, glm::vec3 position, glm::vec3 rotation);
	Entity(glm::vec3 position, glm::vec3 scale, std::string texture);
	Entity(std::string texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

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

	int getRotationType()
	{
		return this->rotateType;
	}

	void setRotationType(int theRotationType)
	{
		this->rotateType = theRotationType;
	}

	void updateOnDeltaTime() {}
	void updateOnFrame() {}

private:

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	Sprite* sprite;

	/*
	* 0 is no rotation,1 is clockwise and 2 is against the clock rotation
	*/
	int rotateType;

protected:

};

#endif /* SPRITE_H */