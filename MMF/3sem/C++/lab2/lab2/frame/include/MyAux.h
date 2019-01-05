#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <exception>
#include <boost\algorithm\string.hpp>
#include <regex>
using namespace std;


void checkOfEmpty(string);
void repairArr(vector<string>&);
int toNumber(string);
double toDouble(string);
