#pragma once
#include "Person.h"

class Student : public Person
{
public:
	Student();
	Student(const string&, const string&, const ushort&, const string&, const int&, const int&);
	~Student();

	int getGroup() const { return group; }
	int getCourse() const{ return course; }
	virtual int getInfo1() const{ return group; }
	virtual int getInfo2() const{ return course; }

	virtual ushort getCount() { return countS; }

private:
	string faculty;
	int group;
	int course;
	static ushort countS;
};

