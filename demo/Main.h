//This file was added by Cefas

#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <common/renderer.h>
#include "common/Entity.h"
#include "common/ConsoleOutput.h"
#include "common/ResourceManager.h"

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
	 * Called when running.
	 It's fixed so it doesn't update on deltaTime
	 */
	void fixedRunning();

	/**
	 * Called when running the game
	 */
	void running();

	/**
	 * Called when closing the game
	 * can be used for deleting
	 */
	void closing();

	std::vector<Entity*> getEntityList();

	void addEntity(Entity* entity);

	ConsoleOutput* getConsole();

	ResourceManager* getResourcemanager();

private:

	std::vector<Entity*> entityList;
	ConsoleOutput* console;
	ResourceManager* resourcemanager;

protected:
};

#endif /* SPRITE_H */