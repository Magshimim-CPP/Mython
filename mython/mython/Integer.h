#pragma once

#include "Type.h"

class Integer : public Type
{
private:
	int value;
	virtual void printLen() override;
public:
	Integer(int val)
	{
		value = val;
	}
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};