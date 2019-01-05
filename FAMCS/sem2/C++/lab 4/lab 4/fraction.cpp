#include "fraction.h"
using namespace lukYanovich;
ushort fraction::count = 0;

void fraction::Check()
{
	if (!denominator)
		throw fractionException("denominator fraction is zero.");
}

void fraction::Canonical()
{
	if (numerator == 0)
	{
		denominator = 1;
		return;
	}
	if (denominator == numerator)
	{
		denominator = numerator = 1;
		return;
	}
	else if (numerator*-1 == denominator)
	{
		numerator = -1;
		denominator = 1;
		return;
	}
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	ushort i = 2;
	ushort r = (ushort)sqrt(abs(numerator)) + 1;
	while (true)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
			continue;
		}
		if (i == r)
			break;
		i++;
	}
}

fraction& fraction::operator=(const fraction& a)
{
	if (this == &a)
		return *this;
	numerator = a.numerator;
	denominator = a.denominator;
	return *this;
}

fraction& fraction::operator=(const int& a)
{
	numerator = a;
	denominator = 1;
	return *this;
}

fraction fraction::operator!() const
{
	if (numerator == 0)
		throw fractionException("divizion by zero.");
	int temp = numerator;
	fraction tmp = *this;
	tmp.numerator = denominator;
	tmp.denominator = temp;
	return tmp;
}

double fraction::todouble() const
{
	double temp = (double)numerator / denominator;
	return temp;
}

float fraction::tofloat() const
{
	float temp = (float)numerator / denominator;
	return temp;
}

fraction fraction::operator+(const int& a) const
{
	if (a == 0)
		return *this;
	fraction temp = *this;
	temp.numerator += denominator*a;
	return temp;
}

fraction fraction::operator+(const fraction& a) const
{
	if (a.numerator == 0)
		return *this;
	fraction temp = *this;
	if (denominator == a.denominator)
	{
		temp.numerator += a.numerator;
		return temp;
	}
	if (a.denominator == 1)
	{
		temp.numerator += denominator*a.numerator;
		return temp;
	}
	temp.numerator = numerator*a.denominator + a.numerator*denominator;
	temp.denominator *= a.denominator;
	return temp;
}

fraction lukYanovich::operator+(const int& r, const fraction& a)
{
	fraction temp = a;
	if (r == 0)
		return temp;
	if (a.numerator == 0)
		return temp;
	temp.numerator += a.denominator*r;
	return temp;
}

fraction fraction::operator-(const int& a)
{
	if (a == 0)
		return *this;
	fraction temp = *this;
	temp.numerator -= denominator*a;
	return temp;
}

fraction fraction::operator-(const fraction& a)
{
	if (a.numerator == 0)
		return *this;
	fraction temp = *this;
	if (denominator == a.denominator)
	{
		temp.numerator -= a.numerator;
		return temp;
	}
	if (a.denominator == 1)
	{
		temp.numerator -= denominator*a.numerator;
		return temp;
	}
	temp.numerator = numerator*a.denominator - a.numerator*denominator;
	temp.denominator *= a.denominator;
	return temp;
}

fraction fraction::operator-()
{
	fraction temp = *this;
	temp.numerator *= -1;
	return temp;
}

fraction lukYanovich::operator-(const int& r, const fraction& a)
{
	fraction temp = a;
	if (r == 0)
		return -temp;
	temp.numerator = a.denominator*r - a.numerator;
	return temp;
}

fraction fraction::operator*(const int& a)
{
	fraction temp = *this;
	temp.numerator *= a;
	return temp;
}

fraction fraction::operator*(const fraction& a)
{
	fraction temp = *this;
	temp.numerator *= a.numerator;
	temp.denominator *= a.denominator;
	return temp;
}

fraction lukYanovich::operator*(const int& r, const fraction& a)
{
	fraction temp = a;
	temp.numerator *= r;
	return temp;
}

fraction fraction::operator/(const int& a)
{
	if (a == 0)
		throw fractionException("division by zero.");
	fraction temp = *this;
	temp.denominator *= a;
	return temp;
}

fraction fraction::operator/(const fraction& a)
{
	if (a.numerator == 0)
		throw fractionException("division by zero.");
	fraction temp = *this;
	temp.denominator *= a.numerator;
	temp.numerator *= a.denominator;
	return temp;
}

fraction lukYanovich::operator/(const int& r, const fraction& a)
{
	if (a.numerator == 0)
		throw fractionException("division by zero");
	fraction temp = !a;
	temp.numerator *= r;
	return temp;
}

fraction fraction::operator++()
{
	numerator += denominator;
	return *this;
}

fraction fraction::operator++(int)
{
	fraction temp = *this;
	numerator += denominator;
	return temp;
}

fraction fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

fraction fraction::operator--(int)
{
	fraction temp = *this;
	numerator -= denominator;
	return temp;
}

fraction& fraction::operator+=(const fraction& a)
{
	*this = *this + a;
	return *this;
}

fraction& fraction::operator+=(const int& a)
{
	*this = *this + a;
	return *this;
}

fraction& fraction::operator-=(const fraction& a)
{
	*this = *this - a;
	return *this;
}

fraction& fraction::operator-=(const int& a)
{
	*this = *this - a;
	return *this;
}

fraction& fraction::operator*=(const fraction& a)
{
	*this = *this * a;
	return *this;
}

fraction& fraction::operator*=(const int& a)
{
	*this = *this * a;
	return *this;
}

fraction& fraction::operator/=(const fraction& a)
{
	*this = *this / a;
	return *this;
}

fraction& fraction::operator/=(const int& a)
{
	*this = *this / a;
	return *this;
}

bool fraction::operator>(const fraction& a) { return ((*this - a).numerator > 0); }

bool fraction::operator>=(const fraction& a) { return ((*this - a).numerator >= 0); }

bool fraction::operator<(const fraction& a) { return ((*this - a).numerator < 0); }

bool fraction::operator<=(const fraction& a) { return ((*this - a).numerator <= 0); }

bool fraction::operator==(const fraction& a) { return (!(*this - a).numerator); }

bool fraction::operator!=(const fraction& a) { return !(!(*this - a).numerator); }


ostream& lukYanovich::operator<< (ostream& os, fraction& a)
{
	if (a.numerator == 0)
	{
		os << a.numerator;
		return os;
	}
	a.Canonical();	//вот именно поэтому дробь в аргументе не const
	if (a.denominator == 1)
	{
		os << a.numerator;
		return os;
	}
	if (a.numerator == a.denominator || a.numerator*-1 == a.denominator)
		os << a.numerator;
	else
		os << a.numerator << '/' << a.denominator;
	return os;
}

istream& lukYanovich::operator>>(istream& is, fraction& a)
{
	char k;
	while (true)
	{
		is >> a.numerator >> k >> a.denominator;
		if (a.denominator && k == '/')
			break;
		is.clear();
	}
	a.Canonical();
	return is;
}