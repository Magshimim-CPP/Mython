#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <iostream>


class Functions
{
public:
    static bool isFunc(std::string& str);
private:
    static void type(std::string& str);
    static void len(std::string& str);
    static void sizeOf(std::string& str);
    static bool push(std::string& str);
    static bool combine(std::string& str);
};