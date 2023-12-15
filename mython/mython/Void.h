#pragma once

#include "Type.h"

class Void : public Type
{
private:
	virtual void printLen() override;
public:
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};