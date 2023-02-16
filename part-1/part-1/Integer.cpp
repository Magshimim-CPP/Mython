#include "Integer.h"
#include <iostream>
#include <string>

Integer::Integer(int integer)
{
	_integer = integer;
}

int Integer::getInt() const
{
	return _integer;
}

void Integer::setInt(int integer)
{
	_integer = integer;
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(_integer);
}