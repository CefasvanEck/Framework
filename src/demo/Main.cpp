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
    this->addEntity(new Entity("assets/missingtexture.tga"));
    this->addEntity(new Entity());
    this->addEntity(new Entity());
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
