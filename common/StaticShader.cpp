#include <glm/glm.hpp>
#include <common/StaticShader.h>


StaticShader::StaticShader(int shaderID)
{
	this->shaderID = shaderID;
	this->maxLights = 8;
	this->location_lightPosition = new int*[maxLights];
	this->location_lightColour = new int*[maxLights];
	this->location_attenuation = new int*[maxLights];
	this->getAllUniformLocations();
}

StaticShader::~StaticShader()
{
	delete this->location_lightPosition;
	delete this->location_lightColour;
	delete this->location_attenuation;
}

void StaticShader::getAllUniformLocations()
{
	idPos = glGetUniformLocation(this->shaderID, "lightPosition");
	idCol = glGetUniformLocation(this->shaderID, "lightColour");
	idAtt = glGetUniformLocation(this->shaderID, "lightAttenuation");
}
