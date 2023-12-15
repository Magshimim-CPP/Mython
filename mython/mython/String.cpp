#include "String.h"
#include "Helper.h"

bool String::isPrintable()
{
	return true;
}

std::string String::toString()
{
	if (Helper::stringContains(value, '\"'))
	{
		return "'" + value + "'";
	}
	if (Helper::stringContains(value, '\''))
	{
		return "\"" + value + "\"";
	}
	return '\'' + value + '\'';
}

std::string String::getType()
{
	return "string";
}

void String::printLen()
{
	std::cout << value.size() << std::endl;
}

int String::sizeOf()
{
	return sizeof(std::string);
}