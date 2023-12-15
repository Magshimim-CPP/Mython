#include "List.h"
#include <list>
bool List::isPrintable()
{
	return true;
}

std::string List::toString()
{
    std::string str = "";
    str += "[ ";
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
    str += " ]";
    return str;
}

std::string List::getType()
{
    return "list";
}

void List::printLen()
{
    std::cout << value->size() << std::endl;
}

int List::sizeOf()
{
    return sizeof(std::list<Type*>);
}