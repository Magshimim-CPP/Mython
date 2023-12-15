#include "Helper.h"


bool Helper::isInteger(const std::string& s)
{
	int start = (s[0] == '-') ? 1 : 0;
	for (int i = start; i < s.size(); i++)
	{
		if (!isDigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

bool Helper::isBoolean(const std::string& s)
{
	return (s == "True" || s == "False");
}


bool Helper::isString(const std::string& s)
{
	size_t end = s.size() - 1;

	if (s[0] == '\"' && end == s.find('\"', 1))
	{
		return true;
	}
	if (s[0] == '\'' && end == s.find('\'', 1))
	{
		return true;
	}

	return false;

}

bool Helper::isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

void Helper::trim(std::string &str)
{
	rtrim(str);
	ltrim(str);

}

void Helper::rtrim(std::string &str)
{
	size_t endpos = str.find_last_not_of(" \t");
	if (std::string::npos != endpos)
	{
		str = str.substr(0, endpos + 1);
	}
}

void Helper::ltrim(std::string &str)
{
	size_t startpos = str.find_first_not_of(" \t");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

void Helper::removeLeadingZeros(std::string &str)
{
	size_t startpos = str.find_first_not_of("0");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}




bool Helper::isLowerLetter(const char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Helper::isUpperLetter(const char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Helper::isLetter(const char c)
{
	return (isLowerLetter(c) || isUpperLetter(c));
}

bool Helper::isUnderscore(const char c)
{
	return ('_' == c);
}

bool Helper::stringToBoolean(std::string& str)
{
	if (str == "True" || str == "true")
	{
		return true;
	}
	if (str == "False" || str == "false")
	{
		return false;
	}
}

bool Helper::stringContains(std::string& str, char ch)
{
	for (char var: str)
	{
		if (var == ch)
		{
			return true;
		}
	}
	return false;
}

bool Helper::mapContains(std::unordered_map<std::string, Type*>& map, std::string str)
{
	for (std::pair<std::string, Type*> var : map)
	{
		if (var.first == str)
		{
			return true;
		}
	}
	return false;
}

bool Helper::vectorContains(std::vector<Type*>* v, Type* val)
{
	for (auto var : *v)
	{
		if (var->toString() == val->toString() && var->getType() == val->getType())
		{
			return true;
		}
	}
	return false;
}
std::string Helper::getVarNmae(std::string& str)
{
	int index = str.find('=');
	std::string newStr = str.substr(0, index);
	trim(newStr);
	return newStr;
}

std::string Helper::getAssignmentVal(std::string& str)
{
	int index = str.find('=');
	std::string newStr = str.substr(index+1, str.size()-1-index);
	trim(newStr);
	return newStr;
}

void Helper::removeDuplicates(std::vector<Type*>* v)
{
	std::vector<Type*>* temp = new std::vector<Type*>(*v);
	v->clear();
	for (auto val : *temp)
	{
		if (!vectorContains(v, val))
		{
			v->push_back(val);
		}
	}
	delete temp;
}

std::vector<Type*>* Helper::isList(const std::string& s)
{
	int begin = 1;
	int end = 0;
	bool waiting = true;
	bool stringStarted = false;
	std::vector<std::string> vec = std::vector<std::string>();
	std::vector<Type*>* res = new std::vector<Type*>();
	if (s[0] == '[' && s[s.size() - 1] == ']')
	{
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == ']')
			{
				if (waiting == false)
				{
					end = i;
					vec.push_back(s.substr(begin, end - begin));
				}
				waiting = true;
			}
			else
			{
				if (waiting)
				{
					begin = i;
					waiting = false;
				}
			}
		}
		for (auto var : vec)
		{
			if (Parser::getType(var))
			{
				res->push_back(Parser::getType(var));
			}
			else if (Parser::getVariableValue(var))
			{
				res->push_back(Parser::getVariableValue(var));
			}
			else
			{
				return nullptr;
			}
		}
		return res;
	}
	return nullptr;
}

std::vector<Type*>* Helper::isSet(const std::string& s)
{
	int begin = 1;
	int end = 0;
	bool waiting = true;
	bool stringStarted = false;
	std::vector<std::string> vec = std::vector<std::string>();
	std::vector<Type*>* res = new std::vector<Type*>();
	if (s[0] == '{' && s[s.size() - 1] == '}')
	{
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '}')
			{
				if (waiting == false)
				{
					end = i;
					vec.push_back(s.substr(begin, end - begin));
				}
				waiting = true;
			}
			else
			{
				if (waiting)
				{
					begin = i;
					waiting = false;
				}
			}
		}
		for (auto var : vec)
		{
			if (Parser::getType(var))
			{
				res->push_back(Parser::getType(var));
			}
			else if (Parser::getVariableValue(var))
			{
				res->push_back(Parser::getVariableValue(var));
			}
			else
			{
				return nullptr;
			}
		}
		return res;
	}
	return nullptr;
}