#pragma once
#include <iostream>
#include <fstream>
//#include <cmath>
#include <exception>
#include <iomanip>
using namespace std;

//using std::ofstream;

const double PI = 3.141592653589793238463;

double f(double);
double x(int);
void printSystem(int n, ofstream& out);
double prod_x1_x2(int m, int k, int n);
double prod_f_x(int m, int n);


void newline(ofstream& out) {
	const char* separator = "///////////////////////////////////////////////////////////////////////////";
	out << endl << endl << separator << endl << endl << endl;
}