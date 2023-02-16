#pragma once
#include <iostream>

class Type
{
public:
	void setTemp(bool temp);
	bool getTemp() const;
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

private:
	bool _isTemp = false;
};
