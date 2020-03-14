//This file was added by Cefas

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Sprite addTextureToMap(std::string texturePath)
	{
		this->textureMap[texturePath] = 23;
	}

	
private:
	std::map<std::string, int> textureMap;

protected:

};

#endif /* SPRITE_H */