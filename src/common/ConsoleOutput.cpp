//This file was added by Cefas

#include <glm/glm.hpp>
#include <common/renderer.h>
#include "common/ConsoleOutput.h"
#include <fstream>
#include <iostream> 

ConsoleOutput::ConsoleOutput(){}

/*
A wrapper around std::cout << "text here" << std::endl;
*/
void ConsoleOutput::println(std::string texttoconsole)
{
	std::cout << texttoconsole << std::endl;
}

/*
Print a float
*/
void ConsoleOutput::println(float toString)
{
	std::cout << std::to_string(toString) << std::endl;
}

//Print an int
void ConsoleOutput::println(int toString)
{
	std::cout << std::to_string(toString) << std::endl;
}

void ConsoleOutput::println(unsigned int toString)
{
	std::cout << std::to_string(toString) << std::endl;
}

std::string ConsoleOutput::toS(float toString)
{
	return std::to_string(toString);
}

std::string ConsoleOutput::toS(int toString)
{
	return std::to_string(toString);
}


ConsoleOutput::~ConsoleOutput()
{

}
