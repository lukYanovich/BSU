#include "String.h"

int main()
{
//	try
//	{
		try
		{
			String a = "12345", b;
			b = a;
			/*cout << b << endl;
			if (a == b)
				cout << "true" << endl;
			else
				cout << "false" << endl;

			cout << "2 elem: " << a[2] << endl;
			cout << a + b << endl;
			cout << "length: " << a.length() << endl;*/

			a[0] = 'p';
			a = a + b;
			cout << a << endl;
			b = a;
			cout << b << endl;


		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}
//	}
//	catch (...)
//	{
//		cout << "error." << endl;
//	}
	return 0;
}