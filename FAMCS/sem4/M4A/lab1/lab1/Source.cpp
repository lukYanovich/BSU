#include "resorces.h"


int main(int argc, char argv[])
{
	setlocale(LC_ALL, ".1251");
	const double eps = pow(10, -7);
	try
	{
		ofstream fout("output.txt", ios_base::trunc);
		if (!fout.good())
			throw exception("ןנמבכולא ס פאיכמל.");
		fout << fixed << setprecision(15);
		fout << "ץ = " << dichotomy(0.5, 3, eps) << endl;
		fout << "ץ = " << mpi(0.8, eps) << endl;
		fout << "x = " << newton(0.6, eps) << endl;
		fout.close();
	}
	catch (exception& e) { cerr << e.what() << endl; }
	return 0;
}


double funcF(double x) { return sqrt(x + 1) - 1.0 / x; }
double funcF_derivative(double x) { return 0.5 / sqrt(x + 1) + 1.0 / (x*x); }
double funcFi(double x) { return x - 0.4 * funcF(x); }


double dichotomy(const double a, const double b, const double eps)
{
	double xLeft = a, xRight = b;
	while (true)
	{
		double x = (xLeft + xRight) / 2;
		if (funcF(xLeft)*funcF(x) < 0)
			xRight = x;
		else
			xLeft = x;
		if (fabs(funcF(x)) <= eps)
			return x;
	}
}


double mpi(const double xBeg, const double eps)
{
	double x = funcFi(xBeg);
	while (true)
	{
		double xNext = funcFi(x);
		if (fabs(xNext - x) <= eps)
			return xNext;
		x = xNext;
	}
}


double newton(const double xBeg, const double eps)
{
	double x = xBeg;
	while(true)
	{
		double xNext = x - funcF(x) / funcF_derivative(x);
		if (fabs(xNext - x) <= eps)
			return xNext;
		x = xNext;
	}
}
