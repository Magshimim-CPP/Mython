#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int integer);
	int getInt() const;
	void setInt(int in);
	virtual bool isPrintable() const override;
	virtual std::string toString() const;
private:
	int _integer;
};