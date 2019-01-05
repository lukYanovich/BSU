#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <assert.h>
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <fstream>
using namespace std;

class author
{
public:
	author(const string&, const string&, const string&);
	friend ostream& operator<<(ostream&, const author&);
	bool operator==(const author&);
	const string getSurname() const{ return surname; }
	const string getName() const{ return name; }
	const string getMiddleName() const { return middleName; }
private:
	string surname;
	string name;
	string middleName;

	author(){ assert(false); }
};


class ex : public exception{
public:
	ex(const string&, const int&);
	ex(const string&, const ifstream&);
	ex(const ifstream&, const string&);
	ex(const string&);
	ex(const string&, const ofstream&);
	virtual const char* what() const _NOEXCEPT { return msg.c_str(); }
private:
	string msg;
};