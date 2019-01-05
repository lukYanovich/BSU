#include "C_N.h"
using namespace Alex;

const C_N C_N::plus(const C_N& a) const
{
	C_N b;
	b.Im = (*this).Im + a.Im;
	b.Re = (*this).Re + a.Re;
	return b;
}

const C_N C_N::minus(const C_N& a) const
{
	C_N b;
	b.Im = (*this).Im - a.Im;
	b.Re = (*this).Re - a.Re;
	return b;
}

const C_N C_N::umn(const C_N& a) const
{
	C_N b;
	b.Re = (*this).Re*a.Re - (*this).Im*a.Im;
	b.Im = (*this).Re*a.Im + (*this).Im*a.Re;
	return b;
}

const C_N C_N::del(const C_N& a) const
{
	if (a.Im == a.Re)
		throw 1;
	C_N b = a;
	double p = a.Re*a.Re - a.Im*a.Im;
	b.Im = a.Im*-1;
	b = (*this).umn(b);
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