//This file was added by Cefas

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <common/ShaderProgram.h>

#include "common/Sprite.h"


class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Sprite* loadTexture(std::string texturePath);
	GLuint loadShader(ShaderProgram* programOfShader, std::string shaderPath);

private:
	std::map<std::string, int> textureMap;
	std::map<std::string, int> shaderMap;

protected:

};

#endif /* SPRITE_H */