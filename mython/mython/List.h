#pragma once

#include "Sequence.h"
#include <vector>

class List : public Sequence
{
private:
	std::vector<Type*>* value;
	virtual void printLen() override;
public:
	List(std::vector<Type*>* vals)
	{
		value = vals;
	}
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};