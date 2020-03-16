//This file was added by Cefas

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Sprite* loadTexture(std::string texturePath);

private:
	std::map<std::string, int> textureMap;

protected:

};

#endif /* SPRITE_H */