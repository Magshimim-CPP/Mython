#pragma once
#include "Sequence.h"

using std::string;

class String : public Sequence
{
public:
	String(string str);
	string getString() const;
	void setString(string str);
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;

private:
	 string _string;
};