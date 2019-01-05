#pragma once
#include "C_N.h"

#include <iostream>
using namespace Alex;
using std::cout;
using std::endl;

void Show(C_N a)
{
	int m;
	if (a.GetIm() < 0)	{ m = 1; }
	if (a.GetIm() > 0)	{ m = 2; }
	if (a.GetIm() == 0)	{ m = 3; }
	if (a.GetRe() == 0)	{ m = 4; }
	if (a.GetRe() == 0 && a.GetIm() == 0) { m = 5; }
	switch (m)
	{
	case 1: {cout << a.GetRe() << a.GetIm() << "i" << endl; break; }
	case 2: {cout << a.GetRe() << "+" << a.GetIm() << "i" << endl; break; }
	case 3: {cout << a.GetRe() << endl; break; }
	case 4: {cout << a.GetIm() << "i" << endl; break; }
	case 5: { cout << 0 << endl; break; }
	default: {"error.\n"; break; }
	}
}