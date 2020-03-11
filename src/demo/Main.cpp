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
    this->addEntity(new Entity("kingkong", glm::vec3(400, 300, 0),100,100));
    this->addEntity(new Entity("rgba", glm::vec3(400, 600, 0), 100, 100));
    this->addEntity(new Entity("pencils", glm::vec3(200, 400, 0), 100, 100));
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
