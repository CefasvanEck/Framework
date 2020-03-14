#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <glm/glm.hpp>

class ConsoleOutput
{
public:
	ConsoleOutput();
	virtual ~ConsoleOutput();

	void println(std::string texttoconsole);

	void  println(float toString);

	void  println(int toString);

	void  println(unsigned int toString);

	std::string  toS(float toString);

	std::string toS(int toString);

private:



protected:

};

#endif /* SPRITE_H */