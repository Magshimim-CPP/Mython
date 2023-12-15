#include "Integer.h"
#include "Helper.h"
bool Integer::isPrintable()
{
	return true;
}

std::string Integer::toString()
{
	std::string strVal = std::to_string(value);
	Helper::removeLeadingZeros(strVal);
	return strVal;
}

std::string Integer::getType()
{
	return "int";
}

void Integer::printLen()
{
	std::cout << "TypeError: Object of type 'int' has no function 'len()'." << std::endl;
}

int Integer::sizeOf()
{
	return sizeof(int);
}