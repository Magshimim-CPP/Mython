#pragma once
#include <string>
#include <unordered_map>
#include "Type.h"
#include "Parser.h"
// this is service class with static functions
class Helper
{
public:
	// check if the parameter is valid Integer value
	static bool isInteger(const std::string& s);

	// check if the parameter is valid Boolean value
	static bool isBoolean(const std::string& s);

	static std::vector<Type*>* isList(const std::string& s);

	// check if the parameter is valid String value
	static bool isString(const std::string& s);

	// check if the parameter is digit
	static bool isDigit(const char c);

	// check if the parameter is lower letter
	static bool isLowerLetter(const char c);	
	
	// check if the parameter is upper letter
	static bool isUpperLetter(const char c);

	// check if the parameter is  letter
	static bool isLetter(const char c);

	// check if the parameter is underscore ('_')
	static bool isUnderscore(const char c);

	// remove whitespace from the begining and the end of the string
	static void trim(std::string &str);

	// remove whitespace from the end of the string
	static void rtrim(std::string &str);  

	// remove whitespace from the beginning of the string
	static void ltrim(std::string &str); 

	// remove leading zeros from the beginning of the string
	static void removeLeadingZeros(std::string &str); 

	static bool stringToBoolean(std::string& str);

	static bool stringContains(std::string& str, char ch);

	static bool vectorContains(std::vector<Type*>* v, Type* val);

	static bool mapContains(std::unordered_map<std::string, Type*>& map, std::string str);

	static std::string getVarNmae(std::string& str);

	static std::string getAssignmentVal(std::string& str);

	static void removeDuplicates(std::vector<Type*>* v);

	static std::vector<Type*>* isSet(const std::string& s);
};
