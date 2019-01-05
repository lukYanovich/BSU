#include "Teacher.h"
ushort Teacher::countT = 0;

Teacher::Teacher()
{
	countT++;
	ID = ++max_count;
}

Teacher::Teacher(const string& Surname, const string& Name, const ushort& Age, const string& Chair)
{
	if (Age > 120 || Age < 1)
		throw wrong_age("Teacher");
	surname = Surname;
	name = Name;
	age = Age;
	chair = Chair;
	countT++;
	ID = ++max_count;
}

Teacher::~Teacher()
{
	countT--;
}