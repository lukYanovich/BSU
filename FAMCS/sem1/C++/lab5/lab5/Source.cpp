/*  Вычислить значение определенного интеграла с аналитически заданной подынтегральной функцией с заданной точностью eps:
- по формуле правых прямоугольников;
- по формуле трапеций
	Для вычисления первого приближения можно взять n=4. 
	Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе приближение. Когда модуль разности
двух соседних приближений будет меньше заданной точности - прекратить вычисление приближений.
	Разработать функции, реализующие методы вычислений интеграла, входными параметрами которых должны быть функция для вычисления 
значения подынтегрального выражения, пределы интегрирования и точность вычислений. Головная программа должна вывести результат 
вычислений для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута заданная точность.*/

#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long int ulong;
typedef const double constD;

double integralRightRectangle(double(*f)(double), double a, double b, double eps, ulong* pN);

double integralTrapeze(double(*f)(double), double a, double b, double eps, ulong& rN);

double f1(double x);
double f2(double x);
double f3(double x);

int main()
{
	setlocale(LC_ALL, ".1251");
	ulong n;
	ulong* pN = new ulong;
	ulong& rN = n;

	constD integral1 = 54.551508;
	constD integral2 = 0.12101312;
	constD integral3 = 0.35325339;

	double eps = 2.0;	// изначально неверное значение

	constD a1 = 2.0;
	constD b1 = 7.0;

	constD a2 = 0.2;
	constD b2 = 0.3;

	constD a3 = -13.0;
	constD b3 = -2.0;

	while ((eps >= 1.0) || (eps <= 0.0)){
		cout << "введите точность исчислений: ";
		cin >> eps;
		if ((eps >= 1.0) || (eps <= 0.0))
			cout << "error" << endl;
		continue;
	}

	cout << "\n\nзначение первого интеграла при вычислении по формуле правых прямоугольников:\n" << integralRightRectangle(f1, a1, b1, eps, pN);
	cout << "\nколичество разбиений функции - " << *pN << endl;
	cout << "\nзначение первого интеграла при вычислении по формуле трапеций:\n" << integralTrapeze(f1, a1, b1, eps, rN);
	cout << "\nколичество разбиений функции - " << rN << endl;
	cout << "\nзначеине первого интерграла по условию:\n" << integral1;

	cout << "\n\n\nзначение второго интеграла при вычислении по формуле правых прямоугольников:\n" << integralRightRectangle(f2, a2, b2, eps, pN);
	cout << "\nколичество разбиений функции - " << *pN << endl;
	cout << "\nзначение второго интеграла при вычислении по формуле трапеций:\n" << integralTrapeze(f2, a2, b2, eps, rN);
	cout << "\nколичество разбиений функции - " << rN << endl;
	cout << "\nзначеине второго интерграла по условию:\n" << integral2;

	cout << "\n\n\nзначение третьего интеграла при вычислении по формуле правых прямоугольников:\n" << integralRightRectangle(f3, a3, b3, eps, pN);
	cout << "\nколичество разбиений функции - " << *pN << endl;
	cout << "\nзначение третьего интеграла при вычислении по формуле трапеций:\n" << integralTrapeze(f3, a3, b3, eps, rN);
	cout << "\nколичество разбиений функции - " << rN << endl;
	cout << "\nзначеине третьего интерграла по условию:\n" << integral3 << endl;

	delete pN;
	return 0;
}

double integralRightRectangle(double(*f)(double), double a, double b, double eps, ulong* pN){
	short int q = 1;
	if (a == b) return 0.0;
	if (a > b){
		q = -1;
		double temp = a;
		a = b;
		b = temp;
	}
	ulong n = 4;
	double s1 = f(b)*(b - a);
	double s2 = 0.0;
	do{
		s2 = s1;
		double k = 0.0;
		n *= 2;
		double h = (b - a) / n;
		for (int i = 1; i < n; i++)
			k = k + f(a + i*h);
		s1 = (f(b) + k)*h;
	} while (fabs(s1 - s2) > eps);
	*pN = n;
	return s1*q;
}

double integralTrapeze(double(*f)(double), double a, double b, double eps, ulong& rN){
	short int q = 1;
	if (a == b) return 0.0;
	if (a > b){
		q = -1;
		double temp = a;
		a = b;
		b = temp;
	}
	ulong n = 4;
	double s1 = (f(a) + f(b))*0.5*(b - a);
	double s2 = 0.0;
	do{
		s2 = s1;
		double k = 0.0;
		n *= 2;
		double h = (b - a) / n;
		for (int i = 1; i < n; i++)
			k = k + f(a + i*h);
		s1 = ((f(a) + f(b)) *0.5 + k)*h;
	} while (fabs(s1 - s2) > eps);
	rN = n;
	return s1*q;
}

double f1(double x){
	return x*sqrt(1.0 + x);
}

double f2(double x){
	return asin(sqrt(x)) / sqrt(x*(1.0 - x));
}

double f3(double x){
	return pow(2.0, x) / (1.0 + pow(4.0, x));
}