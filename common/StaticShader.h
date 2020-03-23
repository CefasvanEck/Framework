#ifndef STATICSHADER_H
#define STATICSHADER_H

#include <glm/glm.hpp>
#include <common/ShaderProgram.h>

class StaticShader : public ShaderProgram
{
public:
	StaticShader(int shaderID);
	virtual ~StaticShader();
	void getAllUniformLocations();
	int idPos;
	int idCol;
	int idAtt;

private:
	int maxLights;
	int **location_lightPosition;
	int **location_lightColour;
	int **location_attenuation;
	int shaderID;

protected:

};

#endif /* STATICSHADER_H */