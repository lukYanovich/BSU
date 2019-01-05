#include "Tree.h"

void Print(const int& a)
{
	ofstream fout("output.txt", ios_base::app);
	if (!fout)
		throw 2;
	fout << a << endl;
	fout.close();
}

bool CheckNumber(string& a)
{
	for (int i(0); i < a.length(); ++i)
		if (!(a[i] >= '0' && a[i] <= '9'))
			return false;
	return true;
}


void menu(Tree& a)
{
	ofstream fout("output.txt", ios_base::app);
	if (!fout)
		throw 2;
	fout << "List of elements:" << endl;
	fout.close();
	a.ForEach(Print);
}

Tree& menu(Tree& a, char& u, int& number)
{
	switch (u)
	{
	case 'I':
	{
		ofstream fout("output.txt", ios_base::app);
		if (!fout)
			throw 2;
		if (a.Insert(number))
			fout << number << ": inserted\n";
		else
			fout << number << ": not inserted\n";
		fout.close();
		return a;
	}
	case 'D':
	{
		ofstream fout("output.txt", ios_base::app);
		if (!fout)
			throw 2;
		if (a.Delete(number))
			fout << number << ": deleted\n";
		else
			fout << number << ": not deleted\n";
		fout.close();
		return a;
	}
	case 'F':
	{
		ofstream fout("output.txt", ios_base::app);
		if (!fout)
			throw 2;
		int count;
		if (a.Find(number, count))
			fout << number << ": found after " << count << " comparison(s)\n";
		else
			fout << number << ": not found after " << count << " comparison(s)\n";
		fout.close();
		return a;
	}
	}
	return a;
}