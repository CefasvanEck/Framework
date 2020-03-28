#include <glm/glm.hpp>
#include <common/StaticShader.h>


StaticShader::StaticShader(GLuint theShaderID)
{
	this->shaderID = theShaderID;
	this->maxLights = 8;
	this->location_lightPosition = new int*[maxLights];
	this->location_lightColour = new int*[maxLights];
	this->location_attenuation = new int*[maxLights];
	this->getAllUniformLocations();
}

GLuint StaticShader::getShaderID()
{
	return this->shaderID;
}

void StaticShader::setShaderID(GLuint theShaderID)
{
	this->shaderID = theShaderID;
}

int StaticShader::getMaxLights()
{
	return this->maxLights;
}

StaticShader::~StaticShader()
{
	delete this->location_lightPosition;
	delete this->location_lightColour;
	delete this->location_attenuation;
}

void StaticShader::getAllUniformLocations()
{
	this->idPos = glGetUniformLocation(this->shaderID, "lightPosition");
	this->idCol = glGetUniformLocation(this->shaderID, "lightColour");
	this->idAtt = glGetUniformLocation(this->shaderID, "lightAttenuation");
	this->maxLightsID = glGetUniformLocation(this->shaderID, "maxLights"); 
}
