#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Student{
public:
	Student(const string&, const int&, const int&);
	friend ostream& operator<<(ostream&, const Student&);
	const string& getFIO() const { return fio; }
	const int getCourse() const { return course; }
	const int getGroup() const{ return group; }
private:
	string fio;
	int course;
	int group;
};


class ex : public exception{
public:
	ex(){ msg = "error"; }
	ex(const ofstream&){ msg = "выходной файл не открыт"; }
	ex(const ifstream&) { msg = "входной файл не открыт"; }
	ex(const bool& flag){ msg = "входной файл пуст"; }
	virtual const char* what() const { return msg.c_str(); }

	ex(const int& a){
		stringstream ss;
		ss << a;
		msg = "число \"";
		string temp;
		ss >> temp;
		msg += temp;
		msg += "\" не подходит для задачи.";
	}
private:
	string msg;
};