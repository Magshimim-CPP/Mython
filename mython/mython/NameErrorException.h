#pragma once
#include "InterpreterException.h"
#include <iostream>
#include <string>
class NameErrorException : public InterpreterException
{
private:
	std::string msg;
public:
	NameErrorException(std::string s)
	{
		msg = s;
	}
	virtual const char* what() const noexcept override;
};