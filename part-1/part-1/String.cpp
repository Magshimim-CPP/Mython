#include "String.h"

String::String(string str)
{
	_string = str;
}

string String::getString() const
{
	return _string;
}

void String::setString(string str)
{
	_string = str;
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	return _string;
}