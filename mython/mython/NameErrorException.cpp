#include "NameErrorException.h"
#include <format>

const char* NameErrorException::what() const noexcept
{
	std::string* temp = new std::string[(std::string("NameError : name '") + msg + std::string("' is not defined")).size()];
	*temp = (std::string("NameError : name '") + msg + std::string("' is not defined"));
	return temp->c_str();
}