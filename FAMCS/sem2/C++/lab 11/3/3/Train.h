#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstring>
using namespace std;
typedef unsigned short ushort;

class Train
{
public:
	Train(const int, const string&, const string&, const string&, int);
	Train(const Train&);
	friend ostream& operator<<(ostream&, const Train&);
	const string getTimeOut() const{ return TimeOut; }
	const string getCity() const { return city; }
	const string getType() const{ return type; }
	const int getTimeWay() const{ return TimeWay; }
private:
	int number;
	string city;
	string type;
	string TimeOut;
	int TimeWay;
};


enum TrainType{ pass, fast };

class ex : public exception{
public:
	ex(TrainType);
	ex(const string&);	
	ex(const int);
	ex(const ifstream&);
	ex(const ofstream&);
	ex(const bool&);
	virtual const char* what() const { return msg.c_str(); }
private:
	string msg;
};

const int getHours(const string&);
const int getMinutes(const string&);
bool sravT(const Train&, const Train&);

void f1(const vector<Train>&); 
void f2(const vector<Train>&);
void f3(const vector<Train>&);
void f4(const vector<Train>&);