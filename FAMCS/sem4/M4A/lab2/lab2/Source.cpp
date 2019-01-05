#include "resorces.h"


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	ofstream fout("output.txt", ios_base::trunc);
	if (!fout.good())
		throw exception("");
	fout << fixed << setprecision(6);

	int n = 10;
	fout << "значения в узлах:\n\n";
	for (int i = 0; i <= n; i++)
		fout << f(x(i)) << endl;

	fout << "\n\nоптимальная сетка:\n\n";
	for (int i = 0; i <= n; i++)
		fout << xOpt(i) << endl;
	fout << "\n\nзначения в ней:\n\n";
	for (int i = 0; i <= n; i++)
		fout << f(xOpt(i)) << endl;

	fout << "\n\nd(i):\n";
	for (int i = 1; i < n; i++)
		fout << 10 * (f(x(i + 1)) - 2 * f(x(i)) + f(x(i - 1))) << endl;

	fout << "\n\nсплайн:\n" << 134.910816 / 6 * 10 << "x^3 + " << (f(x(1)) - 134.910816*0.01 / 6) * 10 << "x\n";

	fout << "\n\nвычисления в точке 0.05:\nf(x)\n" << f(0.05);
	double temp = 0.0;
	double coef1[] = {
		0.0,
		24.780189,
		-294.74021,
		2005.852905,
		-8557.101647,
		23972.779320,
		-44866.923432,
		55614.772735,
		-43841.171462,
		19901.246969,
		-3959.471451
	};
	for (int i = 0; i <= n; i++)
		temp += coef1[i] * pow(0.05, i);
	fout << "\nP(x)\n" << temp;

	temp = 0.0;
	double coef2[] = {
		0.625963,
		7.336653,
		-94.971660,
		737.246650,
		-3524.497912,
		10777.632322,
		-21498.484780,
		27835.667639,
		-22540.172909,
		10365.670408,
		-2065.468467
	};
	for (int i = 0; i <= n; i++)
		temp += coef2[i] * pow(0.05, i);
	fout << "\nP_opt(x)\n" << temp;

	fout << "\nS(x)\n" << 134.910816 / 6 * 10 * pow(0.05, 3) + (f(x(1)) - 134.910816*0.01 / 6) * 10 * 0.05 << endl;
	fout.close();
	return 0;
}


double f(double x) { return pow(sin(PI*x) / (x + 1), 0.1); }

double x(int i) { return 0.1*i; }

double xOpt(int i) { return 0.5*(1 + cos(PI / 11.0 * (i + 0.5))); }
