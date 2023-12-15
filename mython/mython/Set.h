#pragma once

#include "Sequence.h"
#include <vector>
#include "Helper.h"
class Set : public Sequence
{
private:
	std::vector<Type*>* value;
	virtual void printLen() override;
public:
	Set(std::vector<Type*>* vals)
	{
		Helper::removeDuplicates(vals);
		value = vals;
	}
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};