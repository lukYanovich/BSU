#include "fraction.h"
using namespace lukYanovich;
//вариант номер 4: обыкновенные дроби

int main()
{
	/*try
	{
		srand(time(NULL));
		const int n = 7;
		const int beg = -10, end = 10;
		fraction* arr = new fraction[n];
		for (int i(0); i < n; ++i)
		{
			arr[i].setNumber(i);
			if (i < 4)
			{
				arr[i].setNum(beg + rand() % (end - beg + 1));
				arr[i].setDen(beg + rand() % (end - beg + 1));
				arr[i].Check();
				continue;
			}
			if (i == 4)
			{
				arr[i] = 1;
				for (int j(0); j < i; ++j)
					arr[i] *= arr[j];
				continue;
			}
			arr[i] = arr[i - 1].getNumber() + arr[i - 1];
		}
		for (int i(0); i < n; ++i)
			cout << arr[i] << ' ';
		cout << endl;
		fraction sr = ((arr[1] + arr[3] + arr[5]) / 3);
		cout << "the arithmetic mean odd is: " << sr << endl;
	}
	catch (fractionException& e) { cout << "error: " << e.getMsg() << endl; }*/



	fraction a;
	cout << "enter: "; 
	cin >> a;
	cout << a << endl;

		/*
		fraction a(1, 3), b(2, 5);
		cout << "a: " << a << "\t b: " << b << endl;	//здесь неплохо тестировать (ин-)декремент
		if (a < b)	//для теста операторов сравнения
			cout << "true\n";
		else
			cout << "false\n";

		cout << "\na+b: " << a + b << endl;
		cout << "a+2: " << a + 2 << endl;
		cout << "3+a: " << 3 + a << endl;

		cout << "\na-b: " << a - b << endl;
		cout << "a-2: " << a - 2 << endl;
		cout << "5-a: " << a - 5 << endl;
		cout << "-a: " << -a << endl;

		cout << "\na*b: " << a*b << endl;
		cout << "a*10: " << a * 10 << endl;
		cout << "3*a: " << 3 * a << endl;

		try
		{
			cout << "\na/b: " << a / b << endl;
		}
		catch (fractionException& ex) { cout << "\nerror: " << ex.getMsg() << endl; }
		try
		{
			cout << "a/3: " << a / 3 << endl;
		}
		catch (fractionException& ex) { cout << "error: " << ex.getMsg() << endl; }
		try
		{
			cout << "10/a: " << 10 / a << endl;
		}
		catch (fractionException& ex) { cout << "error: " << ex.getMsg() << endl; }


		cout << "\na to real: " << a.todouble() << endl;	//a.tofloat() тоже работает
		try
		{
			cout << "tanned a: " << !a << endl;
		}
		catch (fractionException& ex) { cout << "error: " << ex.getMsg() << endl; }
		cout << "the number of objects of class fraction is: " << fraction::getCount() << endl;
		*/
	//}
	//catch (...) { cout << "error.\n"; }
		
	return 0;
}