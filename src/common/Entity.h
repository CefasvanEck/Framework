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

	float getDeltaTime()
	{
		return this->updateOnDeltaTimer;
	}

	void Entity::setUpdateOnDeltaTimer(float setTime) 
	{
		this->updateOnDeltaTimer += setTime;
	}

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
	float updateOnDeltaTimer;

protected:

};

#endif /* SPRITE_H */