#include <demo/Main.h>
#include <common/renderer.h>
#include "common/Entity.h"


Main::Main()
{
}

Main::~Main()
{

}

/**
 * Called when starting the game
 */
void Main::start()
{
    this->addEntity(new Entity("assets/rgba.tga", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)));
    this->addEntity(new Entity("assets/kingkong.tga", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)));
    this->addEntity(new Entity("assets/pencils.tga", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)));
    
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
