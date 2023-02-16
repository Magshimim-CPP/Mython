#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
	_name = name;
}

const char* NameErrorException::what() const noexcept
{
	return ("NameError : name '" + _name + "' is not defined").c_str();
}