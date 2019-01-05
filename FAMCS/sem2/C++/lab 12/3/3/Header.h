#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <sstream>
#include <vector>
using namespace std;
typedef set<int> _set;

void _read(_set&, const char*);

void _search(const _set, const int);