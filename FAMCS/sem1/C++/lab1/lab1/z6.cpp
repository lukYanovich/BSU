#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	double x, E, s, a, b;
	int n;
	x = 2; E = 1; // изначально неверные значени€
	
	while (!((x > (-1)) && (x < 1)))	{
		cout << "¬ведите х" << endl;  
		cin >> x;

		if ((x >= 1) || (x <= -1)) {
			cout << "error" << endl;
			continue;
		}
	}
	while (!((E <= 0.1) && (E > 0)))	{
		cout << "введите точность E" << endl;
		cin >> E;

		if ((E > 0.1) || (E < 0))	{
			cout << "error" << endl;
			continue;
		}
	}

		n = 0; s = 0; a = 2 * x;
			while (abs(a)>E)
			{
				n++; s = s + a; a = (a*x*x*(2 * n - 1)) / (2 * n + 1);
			}
		b = log((1 + x) / (1 - x));
		cout << "функци€ равна = " << s << endl;
		cout << "значение стандартной функции =" << b << endl;
	return 0;
}