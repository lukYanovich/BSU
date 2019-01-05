#include "matrix.h"
using namespace lukYanovich;
template<class T> ushort matrix<T>::count = 0;
typedef int myType;

int main()
{
	try
	{
		const int n1 = 2, m1 = 3, n2 = 2, m2 = 2, n3 = 2, m3 = 2;
		matrix<myType> a(n1, m1), b(n2, m2), c(n3, m3);
		matrix<myType> y;
		//cout << a.Rand(-2, 2) << endl;
		//return 0;	
		cout << "enter matrix a " << n1 << 'x' << m1 << ':' << endl;
		cin >> a;
		cout << "\nenter matrix b " << n2 << 'x' << m2 << ':' << endl;
		cin >> b;
		cout << "\nenter matrix c " << n3 << 'x' << m3 << ':' << endl;
		cin >> c;
		try
		{
			y = 2 * (a + b)*c - (a - b) * 5;
			cout << "matrix y:\n" << y << endl;
		}
		catch (matrix<myType>::size_error& e) { cout << e.what() << endl; }

		

	}
		/*

		if (a == b)
			cout << "\na=b" << endl;
		else
			cout << "\na!=b" << endl;
		cout << "\na*3:\n" << a * 3 << endl;
		cout << "\n4*a:\n" << 4 * a << endl;
		try
		{
			c = a / 2;
			cout << "\na/2:\n" << c << endl;
		}
		catch (matrix<myType>::xZero& e) { cout << "\nerror: " << e.what() << endl; }

		try
		{
			c = a + b;
			cout << "\na+b:\n" << c << endl;
		}
		catch (matrix<myType>::size_error& e) { cout << "\naddition error: " << e.what() << endl; }

		try
		{
			c = a - b;
			cout << "\na-b:\n" << c << endl;
		}
		catch (matrix<myType>::size_error& e) { cout << "\ndifference error: " << e.what() << endl; }

		try
		{
			c = a * b;
			cout << "\na*b:\n" << c << endl;
		}
		catch (matrix<myType>::size_error& e) { cout << "\nmultiplication error: " << e.what() << endl; }
		cout << "\nthe number of objects of class matrix is: " << matrix<myType>::getCount() << endl;
	}*/
	catch (...) { cout << "error!\n"; }
	
	return 0;
}