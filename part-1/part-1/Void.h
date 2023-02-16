#pragma once
#include "Type.h"

class Void : public Type
{
public:
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;
};