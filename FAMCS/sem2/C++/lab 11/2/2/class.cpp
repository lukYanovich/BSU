#pragma once
#include "Header.h"

Student::Student(const string& _fio, const int& _course, const int& _group){
	if (_course > 10)
		throw ex(_course);
	if (_group > 1000)
		throw ex(_group);
	fio = _fio;
	course = _course;
	group = _group;
}

ostream& operator<<(ostream& os, const Student& a){
	os << a.fio << ' ' << a.course << ' ' << a.group << '\n';
	return os;
}