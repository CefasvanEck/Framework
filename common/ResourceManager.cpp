//This file was added by Cefas

#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/ResourceManager.h"
#include "common/Entity.h"
#include "demo/Main.h"


ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager()
{

}

Sprite* ResourceManager::loadTexture(std::string texturePath)
{
	Sprite* sprite = new Sprite(texturePath);
	if (textureMap.find(texturePath) != textureMap.end())
	{
		sprite->setTextureID(textureMap[texturePath]);
		Main::getInstance().getConsole()->println("Use Texture from memory");
	}
	else
	{
		textureMap[texturePath] = sprite->loadNewTGA(texturePath);
		Main::getInstance().getConsole()->println("Created new Texture");
	}
	return sprite;
}

GLuint ResourceManager::loadShader(ShaderProgram* programOfShader, std::string shaderPath)
{
	if (shaderMap.find(shaderPath) != shaderMap.end())
	{
		Main::getInstance().getConsole()->println("Use Shader from memory");
		return shaderMap[shaderPath];
	}
	else
	{
		Main::getInstance().getConsole()->println("Created new Shader");
		GLuint idOfShader = programOfShader->loadShaders(shaderPath + ".vert", shaderPath + ".frag");
		shaderMap[shaderPath] = idOfShader;
		return idOfShader;
	}
}