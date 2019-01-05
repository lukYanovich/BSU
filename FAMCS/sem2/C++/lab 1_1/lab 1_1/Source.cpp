#include "func.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	C_N a(5, 2);
	C_N b(1, 2);
	try
	{
		Show(a); Show(b);
		cout << "операции:\n\n";
		cout << "сложение: "; Show(a.plus(b));
		cout << "вычитание: "; Show(a.minus(b));
		cout << "умножение: "; Show(a.umn(b));
		cout << "деление: "; Show(a.del(b));
		cout << "максимальное по модулю: "; Show(a.srav(b));
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