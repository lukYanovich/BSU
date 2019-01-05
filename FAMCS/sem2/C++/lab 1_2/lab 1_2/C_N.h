#pragma once
#include <iostream>
using namespace std;

class C_N
{
private:
	double Re;
	double Im;
public:
	C_N(){}
	~C_N(){}
	C_N(double a, double b) { Re = a;  Im = b; }

	double GetIm() const { return Im; }
	double GetRe() const { return Re; }
	void SetIm(double a) { Im = a; }
	void SetRe(double a) { Re = a; }

	const C_N operator+(const C_N& a) const;
	const C_N operator-(const C_N& a) const;
	const C_N operator*(const C_N& a) const;
	const C_N operator/(const C_N& a) const;
	const C_N srav(const C_N& a) const;

	C_N& operator=(const C_N& right);
	bool operator==(const C_N& right) const;
	bool C_N::operator!=(const C_N& a) const;
	
	friend ostream& operator<< (ostream& os, C_N& a)
	{
		os << a.Re << '+' << a.Im << 'i';
		return os;
	}

	friend istream& operator>> (istream& is, C_N& a)
	{
		char s, k;
		is >> a.Re >> s >> a.Im >> k;
		return is;
	}
};