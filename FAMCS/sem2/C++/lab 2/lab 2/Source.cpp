#include "List.h"
#include "func.h"
using namespace Alex;

int main()
{
	try
	{
		switch (menu_1())
		{
		case 1:
		{
			List a;
			int r;
			while (true)
			{
				r = menu_2();
				if (r < 0 || r > 9)
					continue;
				else if (!r)
					break;
				a = menu_3(a, r);
			}
			system("cls");
			throw 1;
		}
		default: { throw 1; break; }
		}
	}
	catch (int exp_12)
	{
		if (exp_12 == 1)
			cout << "farewell.\n";
		else
			cout << "error.\n";
	}

	
	return 0;
}