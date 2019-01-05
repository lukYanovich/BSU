#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <iomanip>
#include <boost\numeric\ublas\vector.hpp>
#include <boost\numeric\ublas\matrix.hpp>


using namespace boost::numeric::ublas;
using std::ofstream;
using std::ifstream;
using std::pair;
using std::exception;
using std::cerr;
using std::endl;
using std::ios_base;


const char separator[] = "\t\t\t";


void print(matrix<double>, ofstream&);
void print(vector<double>, ofstream&);
void printf(vector<double>, ofstream&);

pair<matrix<double>, vector<double>> create(const int, ifstream&);
size_t relaxation_method(matrix<double>, vector<double>, const double, const double);