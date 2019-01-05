#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::setprecision;
using std::ofstream;
using std::ios_base;
using std::exception;

double dichotomy(const double, const double, const double);
double mpi(const double, const double);
double newton(const double, const double);

double funcF(double);
double funcF_derivative(double);
double funcFi(double);
