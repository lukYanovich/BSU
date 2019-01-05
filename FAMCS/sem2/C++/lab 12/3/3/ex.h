#pragma once
#include "Header.h"

class ex : public exception{
public:
	ex(const char*, const ifstream&);
	ex(const ifstream&, const char*);
	ex(const int);
	virtual const char* what() const _NOEXCEPT{ return msg.c_str(); }
private:
	string msg;
};