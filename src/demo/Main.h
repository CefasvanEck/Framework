#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <common/renderer.h>
#include "common/Entity.h"
#include "common/ConsoleOutput.h"

class Main
{
public:

	static Main& getInstance()
	{
		static Main instance;				  
		return instance;
	}

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

	void Main::addEntity(Entity* entity)
	{
		entityList.push_back(entity);
	}

	ConsoleOutput* Main::getConsole()
	{
		return console;
	}

private:

	std::vector<Entity*> entityList;
	ConsoleOutput* console;
protected:
};

#endif /* SPRITE_H */