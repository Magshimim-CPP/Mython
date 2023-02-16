#include "Boolean.h"

Boolean::Boolean(bool setBool)
{
	this->_bool = setBool;
}

bool Boolean::getBool() const
{
	return this->_bool;
}

void Boolean::setBool(bool newBool)
{
	this->_bool = newBool;
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	return _bool ? "True" : "False";
}