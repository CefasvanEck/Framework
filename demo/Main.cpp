//This file was added by Cefas

#include <demo/Main.h>
#include <common/renderer.h>
#include <common/Entity.h>

Main::Main()
{
    console = new ConsoleOutput();
    resourcemanager = new ResourceManager();
}

Main::~Main()
{
    delete console;
    delete resourcemanager;
	for (int i = 0; i < this->getEntityList().size(); ++i)
	{
		delete this->getEntityList()[i];
	}
	this->getEntityList().clear();
}

/**
 * Called when starting the game
 */
void Main::start()
{
	//lighting
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(75, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(200, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(325, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(450, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(575, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(700, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(75, 300, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(75, 425, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(75, 550, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(75, 675, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));

	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(325, 300, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(450, 425, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	this->addEntity(new Entity("assets/rgba.tga", "shaders/sprite-redfilter", glm::vec3(575, 550, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	//No lighting
	this->addEntity(new Entity("assets/kingkong.tga", glm::vec3(700, 500, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    this->addEntity(new Entity("assets/pencils.tga", glm::vec3(800, 300, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    this->addEntity(new Entity("assets/pencils.tga", glm::vec3(1000, 600, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
}

/**
* Called when running.
It's fixed so it doesn't update on deltaTime
*/
void Main::fixedRunning()
{

}

/**
 * Called when running the game
 */
void Main::running()
{
    
}

/**
 * Called when closing the game
 * can be used for deleting
 */
void Main::closing()
{

}

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

ResourceManager* Main::getResourcemanager()
{
	return resourcemanager;
}