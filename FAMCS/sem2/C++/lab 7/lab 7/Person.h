#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
typedef unsigned short ushort;

class Person
{
public:
	Person();
	Person(const string&, const string&, const ushort&);
	~Person();

	const ushort getID() const { return ID; }
	virtual ushort getCount() { return count; }
	string getSurname() const { return surname; }
	virtual int getInfo1() const{ return 0; }
	virtual int getInfo2() const{ return 0; }

protected:
	string surname;	    //фамилия
	string name;		    //имя
	ushort age;
	static ushort max_count;
	ushort ID;

private:
	static ushort count;
};

class wrong_age : public exception
{
public:
	wrong_age(const string& a) 
	{ 
		msg = "wrong age in class \"";
		msg += a;
		msg += "\".";
	}
	virtual const char* what() const { return msg.c_str(); }
private:
	string msg;
};

class wrong_course : public exception
{
public:
	wrong_course()
	{
		msg = "wrong course";
	}
	virtual const char* what() const { return msg.c_str(); }
private:
	string msg;
};