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
void printf(matrix<double>, ofstream&);
void printf(matrix<double>, ofstream&, const size_t);
void print(vector<double>, ofstream&);
void printf(vector<double>, ofstream&);
matrix<double> create(const int, ifstream&);

matrix<double> IMV(matrix<double>, const double);
pair<size_t, size_t> findMaxNotDiagElement(matrix<double>);
int getIndexMaxOfVector(vector<double>);
bool checkMatrix(matrix<double>, const double);
pair<double, vector<double>> ISM(matrix<double>, const double);