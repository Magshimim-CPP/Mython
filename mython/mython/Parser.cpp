#include "Parser.h"
#include "IndentationException.h"
#include <iostream>
#include "Helper.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "SyntaxException.h"
#include "Type.h"
#include "Void.h"
#include "List.h"
#include "Functions.h"
#include "Set.h"
#include "NameErrorException.h"
std::unordered_map<std::string, Type*>* Parser::vars = new std::unordered_map<std::string, Type*> ();

Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw IndentationException();
	}
	else if (Functions::isFunc(str))
	{
		return (new Void())->setIsTempS(true);
	}
	else if (getType(str))
	{
		return getType(str);
	}
	else if (makeAssignment(str))
	{
		return (new Void())->setIsTempS(true);
	}
	else if (getVariableValue(str))
	{
		Type* t = getVariableValue(str);
		return t;
	}
	
	throw SyntaxException();
}


Type* Parser::getType(std::string& str)
{
	Helper::rtrim(str);
	if (Helper::isInteger(str))
	{
		return (new Integer(atoi(str.c_str())))->setIsTempS(true);
	}
	else if (Helper::isBoolean(str))
	{
		return (new Boolean(Helper::stringToBoolean(str)))->setIsTempS(true);
	}
	else if (Helper::isString(str))
	{
		return (new String(str))->setIsTempS(true);
	}
	else if (Helper::isList(str))
	{
		return (new List(Helper::isList(str)))->setIsTempS(true);
	}
	else if (Helper::isSet(str))
	{
		return (new Set(Helper::isSet(str)))->setIsTempS(true);
	}
	else
	{
		return nullptr;
	}
}

bool Parser::isLegalVarName(std::string str)
{
	if (Helper::isDigit(str[0]))
	{
		throw SyntaxException();
	}
	for (char ch : str)
	{
		if (!(Helper::isDigit(ch) || Helper::isLetter(ch) || ch == '_'))
		{
			throw SyntaxException();
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	if (Helper::stringContains(str, '=') && str[0] != '=' && str[str.size()-1] != '=')
	{
		std::string name = Helper::getVarNmae(str);
		std::string val = Helper::getAssignmentVal(str);
		if (getType(val) && isLegalVarName(name))
		{
			if (Helper::mapContains(*vars, name))
			{
				if (vars->at(name)->getRefs() == 1)
				{
					delete vars->at(name);
				}
				else
				{
					vars->at(name)->removeRef();
				}
				vars->at(name) = getType(val);
			}
			else
			{
				vars->insert(std::pair<std::string, Type*>(name, getType(val)));
			}
			return true;
		}
		else if (getVariableValue(val) && isLegalVarName(name))
		{
			if (Helper::mapContains(*vars, name))
			{
				if (vars->at(name)->getRefs() == 1)
				{
					delete vars->at(name);
				}
				else
				{
					vars->at(name)->removeRef();
				}
				vars->at(name) = getVariableValue(val);
				vars->at(name)->addRef();
			}
			else
			{
				vars->insert(std::pair<std::string, Type*>(name, getVariableValue(val)));
				getVariableValue(val)->addRef();
			}
			return true;
		}
		else if (isLegalVarName(name))
		{
			throw NameErrorException(val);
		}
	}
	return false;
}

Type* Parser::getVariableValue(std::string str)
{
	try
	{
		return (vars->at(str));
	}
	catch (...)
	{
		throw NameErrorException(str);
	}
}

Type* Parser::checkVariableExists(std::string str)
{
	try
	{
		return (vars->at(str));
	}
	catch (...)
	{
		return nullptr;
	}
}

Type& Parser::checkVariableExistsRef(std::string str)
{
	try
	{
		return (*vars->at(str));
	}
	catch (...)
	{
	}
}

void Parser::clearMemory()
{
	for (auto var : *vars)
	{
		if (var.second->getRefs() == 1)
		{
			delete var.second;
		}
		else
		{
			var.second->removeRef();
		}
	}
	delete vars;
}