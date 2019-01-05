#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
typedef unsigned short ushort;

class QDequeException : public exception{
public:
	QDequeException(unsigned a){
		msg = "there is no element at index \"";
		stringstream ss;
		string temp;
		ss << a;
		ss >> temp;
		msg += temp;
		msg += "\"";
	}

	virtual const char* what() const throw() { return msg.c_str(); }
	QDequeException() { msg = "TDeque is empty."; }
private:
	string msg;
};