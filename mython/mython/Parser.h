#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string& str);
    static Type* getVariableValue(std::string str);
    static void clearMemory();
    static Type* checkVariableExists(std::string str);
    static Type& checkVariableExistsRef(std::string str);
    static std::unordered_map<std::string, Type*>* vars;
private:
    
    static bool isLegalVarName(std::string str);
    static bool makeAssignment(std::string str);
};