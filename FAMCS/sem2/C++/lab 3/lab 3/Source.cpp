#include "func.h"
using namespace Alex;

int main()
{

	

	
	
	try
	{
		ofstream fout("output.txt", ios_base::trunc);
		if (!fout)
			throw 2;
		fout.close();
		ifstream fin("input.txt");
		if (!fin)
			throw 1;
		Tree a;
		string str, number, separators = " ";
		bool flag = false;
		while (fin.good())
		{
			getline(fin, str);
			if (str.find_first_not_of(separators, 0) == -1)
			{
				ofstream fout("output.txt", ios_base::app);
				if (!fout)
					throw 2;
				fout << "this isn't true command\n";
				fout.close();
				str.erase();
				continue;
			}
			if (!(str[0] == 'I' || str[0] == 'D' || str[0] == 'F' || str[0]=='L'))
			{
				ofstream fout("output.txt", ios_base::app);
				if (!fout)
					throw 2;
				fout << "this isn't true command\n";
				fout.close();
				str.erase();
				continue;
			}
			if (str == "L")
			{
				flag = true;
				menu(a);
				str.erase();
				continue;
			}
			if (str.length() < 3 || !(str[1] == ' ' && (str[2] >= '0' && str[2] <= '9')))
			{
				ofstream fout("output.txt", ios_base::app);
				if (!fout)
					throw 2;
				fout << "this isn't true command\n";
				fout.close();
				str.erase();
				continue;
			}
			for (int i(2); i < str.length(); ++i)
				number += str[i];
			long int m;
			int q;
			if (CheckNumber(number))
			{
				const char* r = number.c_str();
				m = strtol(r, 0, 0);
				q = m;
			}
			else
			{
				ofstream fout("output.txt", ios_base::app);
				if (!fout)
					throw 2;
				fout << "this isn't true command\n";
				fout.close();
				str.erase();
				number.erase();
				continue;
			}
			flag = true;
			a = menu(a, str[0], q);
			str.erase();
			number.erase();
		}
		if (!flag)
			throw 3;
		else
			cout << "farewell.\n";

		Tree b;
		b= a;
		b.PrintTree();
	}
	catch (int exp_12)
	{
		switch (exp_12)
		{
		case 1: { cout << "input file not open." << endl; break; }
		case 2: { cout << "output file not open." << endl; break; }
		case 3: { cout << "input file isn't good!\n"; break;	}
		default: { cout << "error." << endl; break; }
		}
	}


	
	return 0;
}