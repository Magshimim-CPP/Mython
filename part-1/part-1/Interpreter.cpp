#include "Type.h"
#include "IndentationException.h"
#include "Parser.h"
#include <exception>
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Ohad Shaked"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		Type* input = nullptr;
		// parsing command
		try
		{
			input = Parser::parseString(input_string);
		}

		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		if (input && input->isPrintable())
		{
			std::cout << input->toString() << std::endl;
		}
		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
		
	}

	return 0;
}
