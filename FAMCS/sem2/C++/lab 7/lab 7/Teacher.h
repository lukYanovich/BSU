#pragma once
#include "Person.h"

class Teacher : public Person
{
public:
	Teacher();
	Teacher(const string&, const string&, const ushort&, const string&);
	~Teacher();

	virtual ushort getCount() { return countT; }

private:
	string chair;
	static ushort countT;
};