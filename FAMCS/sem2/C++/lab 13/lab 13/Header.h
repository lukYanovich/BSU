#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct course{
	string subject;	  //предмет
	int mark;		  //отметка
	course(const string& a, const int b) : subject(a), mark(b){}
};

struct studData{
	string name;				//фамилия, инициалы
	int number;					//номер зачётки
	vector<course> markList;	//результаты сессии
};

typedef map<int, studData> _map;
typedef pair<int, studData> par;
typedef unsigned short ushort;

void _read(_map&, const char*);

int toint(const string&);

bool _check(const char);

void _show(const _map);

void f2(_map&);
void f3(const _map);
void f4(_map&);
void f5(_map&);
void f6(const _map, const char*);
void f7(const _map);
void f8(_map&);