#include "Void.h"

bool Void::isPrintable()
{
	return false;
}

std::string Void::toString()
{
	return "";
}

std::string Void::getType()
{
	return "void";
}

void Void::printLen()
{
	std::cout << "TypeError: Object of type 'void' has no function 'len()'." << std::endl;
}

int Void::sizeOf()
{
	return 0;
}