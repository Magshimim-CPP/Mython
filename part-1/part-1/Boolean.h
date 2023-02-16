#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool setBool);
	bool getBool() const;
	void setBool(bool newBool);
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;

private:
	bool _bool;
};