#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
typedef unsigned short ushort;

namespace lukYanovich
{
	class fraction
	{
	public:
		fraction() { numerator = 0; denominator = 1; count++; }
		fraction(int a, int b) { numerator = a; denominator = b; count++; }
		fraction(const fraction& a) { numerator = a.numerator; denominator = a.denominator; count++; }
		~fraction() { count--; }

		fraction& operator=(const fraction&);
		fraction& operator=(const int&);

		fraction operator+(const int&) const;
		fraction operator+(const fraction&) const;
		friend fraction operator+(const int&, const fraction&);

		fraction operator-(const int&);
		fraction operator-(const fraction&);
		friend fraction operator-(const int&, const fraction&);
		fraction operator-();

		fraction operator*(const int&);
		fraction operator*(const fraction &);
		friend fraction operator*(const int&, const fraction&);

		fraction operator/(const int&);
		fraction operator/(const fraction&);
		friend fraction operator/(const int&, const fraction&);

		fraction operator++();
		fraction operator++(int);

		fraction operator--();
		fraction operator--(int);

		fraction& operator+=(const fraction&);
		fraction& operator+=(const int&);

		fraction& operator-=(const int&);
		fraction& operator-=(const fraction&);

		fraction& operator*=(const int&);
		fraction& operator*=(const fraction&);

		fraction& operator/=(const int&);
		fraction& operator/=(const fraction&);

		bool operator>(const fraction&);
		bool operator>=(const fraction&);
		bool operator==(const fraction&);
		bool operator!=(const fraction&);
		bool operator<(const fraction&);
		bool operator<=(const fraction&);

		fraction operator!() const;	//получение обратной дроби
		double todouble() const;
		float tofloat() const;
		friend ostream& operator<< (ostream&, fraction&);
		friend istream& operator>>(istream&, fraction&);

		void setNum(const int a) { numerator = a; }
		void setDen(const int a) { denominator = a; }
		void Check();
		void setNumber(const int a) { number = a; }
		int getNumber() const { return number; }

		static ushort getCount() { return count; }
	private:
		int numerator;
		int denominator;
		static ushort count;
		int number;
		void Canonical();
	};

	class fractionException
	{
	public:
		fractionException(const string& msg) { str = msg; }
		string getMsg() const { return str; }
	private:
		string str;
	};
}