#ifndef STATICSHADER_H
#define STATICSHADER_H

#include <glm/glm.hpp>
#include <common/ShaderProgram.h>

class StaticShader : public ShaderProgram
{
public:
	StaticShader(GLuint shaderID);
	virtual ~StaticShader();
	void getAllUniformLocations();

	GLuint idPos;
	GLuint idCol;
	GLuint idAtt;

	GLuint getShaderID();
	void setShaderID(GLuint shaderID);
	int getMaxLights();

private:
	int maxLights;
	int maxLightsID;
	int **location_lightPosition;
	int **location_lightColour;
	int **location_attenuation;
	GLuint shaderID;

protected:

};

#endif /* STATICSHADER_H */