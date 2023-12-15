#include "Boolean.h"

bool Boolean::isPrintable()
{
	return true;
}

std::string Boolean::toString()
{
	return value ? "True" : "False";
}

std::string Boolean::getType()
{
	return "bool";
}

void Boolean::printLen()
{
	std::cout << "TypeError: Object of type 'bool' has no function 'len()'." << std::endl;
}

int Boolean::sizeOf()
{
	return sizeof(bool);
}