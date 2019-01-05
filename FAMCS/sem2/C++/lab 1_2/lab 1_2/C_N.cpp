#include "C_N.h"

C_N& C_N::operator=(const C_N& right)
{
	if (this == &right)
		return *this;
	Im = right.Im;
	Re = right.Re;
}

bool C_N::operator==(const C_N& a) const
{
	if (sizeof((*this)) != sizeof(a))
		return false;
	if ((*this).Im == a.Im && (*this).Re == a.Re)
		return true;
	return false;
}

bool C_N::operator!=(const C_N& a) const
{
	if (sizeof((*this)) != sizeof(a))
		return true;
	if ((*this).Im == a.Im && (*this).Re == a.Re)
		return false;
	return true;
}

const C_N C_N::operator+(const C_N& a) const
{
	C_N b;
	b.Im = (*this).Im + a.Im;
	b.Re = (*this).Re + a.Re;
	return b;
}

const C_N C_N::operator-(const C_N& a) const
{
	C_N b;
	b.Im = (*this).Im - a.Im;
	b.Re = (*this).Re - a.Re;
	return b;
}

const C_N C_N::operator*(const C_N& a) const
{
	C_N b;
	b.Re = (*this).Re*a.Re - (*this).Im*a.Im;
	b.Im = (*this).Re*a.Im + (*this).Im*a.Re;
	return b;
}

const C_N C_N::operator/(const C_N& a) const
{
	if (a.Im == a.Re)
		throw 1;
	C_N b = a;
	double p = a.Re*a.Re - a.Im*a.Im;
	b.Im = a.Im*-1;
	b = (*this)*b;
	b.Re = b.Re / p;
	b.Im = b.Im / p;
	return b;
}

const C_N C_N::srav(const C_N& a) const
{
	double p1 = (*this).Re*(*this).Re + (*this).Re*(*this).Re;
	double p2 = a.Re*a.Re + a.Im*a.Im;
	return (p1 >= p2) ? (*this) : a;
}