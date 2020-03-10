#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	
private:
	std::vector<Sprite*> entityList;

protected:

};

#endif /* SPRITE_H */