#include "Set.h"
#include <set>
bool Set::isPrintable()
{
    return true;
}

std::string Set::toString()
{
    std::string str = "";
    str += "{ ";
    for (int i = 0; i < (*value).size(); i++)
    {
        if (i == (*value).size() - 1)
        {
            str += (*value)[i]->toString();
        }
        else
        {
            str += (*value)[i]->toString() + " , ";
        }
    }
    str += " }";
    return str;
}

std::string Set::getType()
{
    return "set";
}

void Set::printLen()
{
    std::cout << value->size() << std::endl;
}

int Set::sizeOf()
{
    return sizeof(std::set<Type*>);
}