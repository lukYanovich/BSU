#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <fstream>
using namespace std;
typedef map<string, int> word;
typedef pair<string, int> par;

void _read(word&, const char*);

bool _camp(const string&, const string&);