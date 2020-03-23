#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

class Light
{
public:
	Light(glm::vec3 position, float colourR, float colourG, float colourB);
	virtual ~Light();

	glm::vec3 getPosition();

	void setPosition(glm::vec3 position);

	glm::vec3 getColour();

	void setColour(glm::vec3 colour);

	glm::vec3 getAttenuation();

private:
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec3 attenuation;

protected:

};

#endif /* LIGHT_H */