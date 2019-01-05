#include "Student.h"
ushort Student::countS = 0;

Student::Student()
{
	countS++;
	ID = ++max_count;
}

Student::Student(const string& Surname, const string& Name, const ushort& Age, const string& Faculty, const int& Group, const int& Course)
{
	if (Age > 120 || Age < 1)
		throw wrong_age("Student");
	if (course > 7)
		throw wrong_course();
	surname = Surname;
	name = Name;
	age = Age;
	faculty = Faculty;
	group = Group;
	course = Course;
	countS++;
	ID = ++max_count;
}

Student::~Student()
{
	countS--;
}