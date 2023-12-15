#include "Functions.h"
#include "List.h"
#include "Set.h"
bool Functions::isFunc(std::string& str)
{
	if ((str.substr(0, 5)) == "type(")
	{
		type(str);
		return true;
	}
	if ((str.substr(0, 4)) == "len(")
	{
		len(str);
		return true;
	}
	if ((str.substr(0, 7)) == "sizeof(")
	{
		sizeOf(str);
		return true;
	}
	if (push(str) == true)
	{
		return true;
	}
	if (combine(str) == true)
	{
		return true;
	}
	return false;
}

void Functions::type(std::string& str)
{
	std::string varName = (str.substr(5, str.size() - 6));
	if (Parser::getType(varName))
	{
		std::cout << "<type '" + Parser::getType(varName)->getType() + "'>" << std::endl;
	}
	else if (Parser::getVariableValue(varName))
	{
		std::cout << "<type '" + Parser::getVariableValue(varName)->getType() + "'>" << std::endl;
	}
}

void Functions::len(std::string& str)
{
	std::string varName = (str.substr(4, str.size() - 5));
	if (Parser::getType(varName))
	{
		Parser::getType(varName)->printLen();
	}
	else if (Parser::getVariableValue(varName))
	{
		Parser::getVariableValue(varName)->printLen();
	}
}

void Functions::sizeOf(std::string& str)
{
	std::string varName = (str.substr(7, str.size() - 8));
	if (Parser::getType(varName))
	{
		std::cout << Parser::getType(varName)->sizeOf() << std::endl;
	}
	else if (Parser::getVariableValue(varName))
	{
		std::cout << Parser::getVariableValue(varName)->sizeOf() << std::endl;
	}
}

bool Functions::push(std::string& str)
{
	try
	{
		Type* var1 = Parser::checkVariableExists(str.substr(0, str.find('.')));
		bool var2 = str.substr(str.find('.') + 1, 5) == "push(";
		std::string tmp1 = (str.substr(str.find('.') + 6, str.size() - str.find('.') - 7));
		Type* var3 = Parser::getType(tmp1);
		Type* var4 = Parser::checkVariableExists(tmp1);
		bool var5 = str[str.size() - 1] == ')';

		if (var1 && var2 && var4 && var5)
		{
			if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "list")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = (str.substr(str.find('.') + 6, str.size() - str.find('.') - 7));
				tempStr.append(Parser::checkVariableExists(tmp)->toString());
				tempStr.append("]");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new List(Helper::isList(tempStr)))->setIsTempS(true));
				return true;
			}
			else if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "set")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = (str.substr(str.find('.') + 6, str.size() - str.find('.') - 7));
				tempStr.append(Parser::checkVariableExists(tmp)->toString());
				tempStr.append("}");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new Set(Helper::isSet(tempStr)))->setIsTempS(true));
				return true;
			}
		}

		if (var1 && var2 && var3 && var5)
		{
			if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "list")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = (str.substr(str.find('.') + 6, str.size() - str.find('.') - 7));
				tempStr.append(Parser::getType(tmp)->toString());
				tempStr.append("]");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new List(Helper::isList(tempStr)))->setIsTempS(true));
				return true;
			}
			else if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "set")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = (str.substr(str.find('.') + 6, str.size() - str.find('.') - 7));
				tempStr.append(Parser::getType(tmp)->toString());
				tempStr.append("}");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new Set(Helper::isSet(tempStr)))->setIsTempS(true));
				return true;
			}

		}
	}
	catch (...)
	{
		return false;
	}
	return false;
}

bool Functions::combine(std::string& str)
{
	try
	{
		Type* var1 = Parser::checkVariableExists(str.substr(0, str.find('.')));
		bool var2 = str.substr(str.find('.') + 1, 8) == "combine(";
		std::string tmp1 = (str.substr(str.find('.') + 9, str.size() - str.find('.') - 10));
		Type* var3 = Parser::getType(tmp1);
		Type* var4 = Parser::checkVariableExists(tmp1);
		bool var6 = false;
		bool var7 = false;
		if (var4 != nullptr)
		{
			var6 = var4->getType() == "list" || var4->getType() == "set";;
		}
		if (var3 != nullptr)
		{
			var7 = var3->getType() == "list" || var3->getType() == "set";;
		}

		bool var5 = str[str.size() - 1] == ')';

		if (var1 && var2 && var4 && var5 && var6)
		{
			if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "list")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = tmp1;
				tempStr.append(var4->toString().substr(1, var4->toString().size()-2));
				tempStr.append("]");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new List(Helper::isList(tempStr)))->setIsTempS(true));
				return true;
			}
			else if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "set")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = tmp1;
				tempStr.append(var4->toString().substr(1, var4->toString().size() - 2));
				tempStr.append("}");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new Set(Helper::isSet(tempStr)))->setIsTempS(true));
				return true;
			}
		}

		if (var1 && var2 && var3 && var5 && var6)
		{
			if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "list")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = tmp1;
				tempStr.append(var3->toString().substr(1, var3->toString().size() - 2));
				tempStr.append("]");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new List(Helper::isList(tempStr)))->setIsTempS(true));
				return true;
			}
			else if (Parser::checkVariableExists(str.substr(0, str.find('.')))->getType() == "set")
			{
				std::string tempStr = Parser::checkVariableExists(str.substr(0, str.find('.')))->toString();
				tempStr[tempStr.size() - 1] = ',';
				std::string tmp = tmp1;
				tempStr.append(var3->toString().substr(1, var3->toString().size() - 2));
				tempStr.append("}");
				std::string tmp3 = str.substr(0, str.find('.'));
				Parser::vars->at(tmp3) = ((new Set(Helper::isSet(tempStr)))->setIsTempS(true));
				return true;
			}

		}
	}
	catch (...)
	{
		return false;
	}
	return false;
}