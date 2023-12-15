#pragma once

#include "Type.h"

class Boolean : public Type
{
	bool value;
	virtual void printLen() override;
public:
	Boolean(bool val)
	{
		value = val;
	}
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};