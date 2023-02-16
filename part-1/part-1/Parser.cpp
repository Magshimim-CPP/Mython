#include "Parser.h"
#include "IndentationException.h"
#include "Boolean.h"
#include "String.h"
#include "Integer.h"
#include "Helper.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Void.h"
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str)
{
	if (str.length() > 0)
	{
		if (str[0] == '\t' || str[0] == ' ')
		{
			throw IndentationException();
		}

		Helper::trim(str);
		Type* inp;

		if (makeAssignment(str))
		{
			return new Void();
		}
		if (getVariableValue(str))
		{
			return getVariableValue(str);
		}
		if (getType(str))
		{
			inp = getType(str);
			inp->setTemp(true);
			return inp;
		}
		else
		{
			throw SyntaxException();
		}
		
	}

	return nullptr;
}

Type* Parser::getType(std::string& str)
{
	if (Helper::isInteger(str))
	{
		return new Integer(stoi(str));
	}
	else if (Helper::isBoolean(str))
	{
		return new Boolean(str == "True" ? true : false);
	}
	else if (Helper::isString(str))
	{
		return new String(str);
	}

	return nullptr;
}

bool Parser::isLegalVarName(std::string& str)
{
	if (str == "True" || str == "False")
	{
		return false;
	}
	if (str.length() > 0)
	{
		if (Helper::isDigit(str[0]))
		{
			return false;
		}

		for (int i = 0; i < str.length(); i++)
		{
			if (!(Helper::isDigit(str[i]) || Helper::isLetter(str[i]) || Helper::isUnderscore(str[i])))
			{
				return false;
			}
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string& str)
{

	if (str.length() <= 3 || std::count(str.begin(), str.end(), '=') != 1)
	{
		return false;

	}

	std::string name = str.substr(0, str.find('='));
	Helper::trim(name);
	std::string value = str.substr(str.find('=') + 1, str.length());
	Helper::trim(value);

	if (isLegalVarName(name) && isLegalVarName(value))
	{
		_variables[name] = getVariableValue(value);
	}
	if (isLegalVarName(name))
	{
		if (getVariableValue(value))
		{
			Type* newValue = getVariableValue(value);
			std::string stringValue = newValue->toString();
			Type* oldValue = getType(stringValue);
			_variables[name] = oldValue;
		}
		else
		{

			Type* newtype = getType(value);

			if (!newtype)
			{
				throw NameErrorException(value);
			}

			_variables[name] = newtype;
		}
		return true;
	}
	else
	{
		return false;
	}
}

Type* Parser::getVariableValue(std::string& str)
{
	auto placeIterator = _variables.find(str);

	if (placeIterator != _variables.end())
	{
		return _variables[str];
	}

	return nullptr;
}

void Parser::Clear()
{
	for (auto i = _variables.begin(); i != _variables.end(); i++)
	{
		delete i->second;
	}
}