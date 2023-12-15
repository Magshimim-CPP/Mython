#pragma once

#include "Sequence.h"

class String : public Sequence
{
private:
	std::string value;
	virtual void printLen() override;
public:
	String(std::string val)
	{
		value = val.substr(1, val.size()-2);
	}
	virtual bool isPrintable() override;
	virtual std::string toString() override;
	virtual std::string getType() override;
	virtual int sizeOf() override;
};