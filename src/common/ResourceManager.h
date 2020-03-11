#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	void addTextureToMap(std::string texturePath,Sprite sprite)
	{
		this->textureMap[texturePath] = 23;
	}

	
private:
	std::map<std::string, int> textureMap;

protected:

};

#endif /* SPRITE_H */