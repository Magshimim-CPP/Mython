#pragma once

#include <iostream>
#include <string>

class Type
{
private:
	bool _isTemp = false;
	int _refCount = 1;
public:
	bool getIsTemp()
	{
		return _isTemp;
	}
	int getRefs()
	{
		return _refCount;
	}
	void setIsTemp(bool val)
	{
		_isTemp = val;
	}
	void addRef()
	{
		_refCount++;
	}
	void removeRef()
	{
		_refCount--;
	}
	Type* setIsTempS(bool val)
	{
		_isTemp = val;
		return this;
	}
	virtual int sizeOf() = 0;
	virtual bool isPrintable() = 0;
	virtual std::string getType() = 0;
	virtual void printLen() = 0;
	virtual std::string toString() = 0;
};
