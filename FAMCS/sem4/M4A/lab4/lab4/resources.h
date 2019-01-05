#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>

using namespace std;

double f(double);
double f_t(double);
double h(int N);
double x(int i, int N);
double runge(const double eps, double(*method)(const int), int m, ofstream&);
double leftRectagle(int N);
double trapeze(int N);
double simpson(int N);


double f_exacly() { 
	double PI = 3.14159265358979323846;
	return PI*PI / 12; }