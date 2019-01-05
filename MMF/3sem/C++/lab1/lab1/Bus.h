#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <vector>
#include <boost\algorithm\string.hpp>
using namespace std;


class Bus {
private:
	string FIO;
	string numberOfBus;
	string numberOfRoute;
	string brand;
	size_t releaseYear;
	size_t mileage;

	static char* separator;

public:
	void setFIO(string s) { this->FIO = s; }
	void setNumberOfBus(string s) { this->numberOfBus = s; }
	void setNumberOfRoute(string s) { this->numberOfRoute = s; }
	void setBrand(string s) { this->brand = s; }
	void setReleaseYear(size_t a) { this->releaseYear = a; }
	void setMileage(size_t a) { this->mileage = a; }

	string getFIO() const { return this->FIO; }
	string getNumberOfBus() const { return this->numberOfBus; }
	string getNumberOfRoute() const { return this->numberOfRoute; }
	string getBrand() const { return this->brand; }
	size_t getReleaseYear() const { return this->releaseYear; }
	size_t getMileage() const { return this->mileage; }


	Bus();
	ostream& show(ostream&);
	friend ostream& operator<<(ostream&, Bus&);
};


bool isNumber(string);
size_t toNumber(string, int);
void invalidDateInLine(int);
vector<Bus> create(const char*);
void print(ostream&, vector<Bus>&);
