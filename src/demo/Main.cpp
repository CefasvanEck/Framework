//This file was added by Cefas

#include <demo/Main.h>
#include <common/renderer.h>
#include "common/Entity.h"


Main::Main()
{
    console = new ConsoleOutput();
}

Main::~Main()
{

}

/**
 * Called when starting the game
 */
void Main::start()
{
    this->addEntity(new Entity("assets/rgba.tga", glm::vec3(100, 100, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    this->addEntity(new Entity("assets/kingkong.tga", glm::vec3(100, 200, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    this->addEntity(new Entity("assets/pencils.tga", glm::vec3(200, 300, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    
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
