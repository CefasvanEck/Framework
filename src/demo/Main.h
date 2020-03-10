#ifndef MAIN_H
#define MAIN_H

#include <demo/Demo.h>
#include <vector>
#include <common/renderer.h>
#include "common/Entity.h"

class Main
{
public:
	Main();
	virtual ~Main();

	/**
	 * Called when starting the game
	 */
	void start();

	/**
	 * Called when running the game
	 */
	void running();

	/**
	 * Called when closing the game
	 * can be used for deleting
	 */
	void closing();

	std::vector<Entity*> Main::getEntityList()
	{
		return entityList;
	}

	void Main::spawnEntity(Entity* entity)
	{
		entityList.push_back(entity);
	}

private:
	
	std::vector<Entity*> entityList;

protected:

};

#endif /* SPRITE_H */