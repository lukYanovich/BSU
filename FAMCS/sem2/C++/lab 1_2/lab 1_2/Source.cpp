#include "func.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	C_N a(4, 4);
	C_N b(1, 2);
	//C_N c(1, 2);
	//C_N d;
	try
	{
		Show(a); Show(b);
		cout << "операции:\n\n";
		cout << "сложение: "; Show(a + b);
		cout << "вычитание: "; Show(a - b);
		cout << "умножение: "; Show(a*b);
		cout << "деление: "; Show(a / b);
		cout << "максимальное по модулю: "; Show(a.srav(b));
		/*
		cout << "введите число: ";
		cin >> a; 
		cout << a << endl;
		*/
		
	}
	catch (int p)
	{
		switch (p)
		{
		case 1: {cout << "деление на ноль." << endl; cout << "максимальное по модулю:"; Show(a.srav(b)); break; }
		default: {cout << "error.\n"; break; }
		}
	}
	return 0;
}