#include "Person.h"
ushort Person::count = 0;
ushort Person::max_count = 0;

Person::Person()
{
	count++;
	ID = ++max_count;
}

Person::Person(const string& Surname, const string& Name, const ushort& Age)
{
	if (Age > 120 || Age < 1)
		throw wrong_age("Person");
	surname = Surname;
	name = Name;
	age = Age;
	count++;
	ID = ++max_count;
}

Person::~Person()
{
	count--;
}