#pragma once

void Print(double& a) { cout << a << ' '; }

double& umn2(double& a) { a *= 2; return a; }

int menu_1(void)
{
	cout << "Create a list? \nyes - 1, no(exit) - 0.\n";
	int a = 10;
	while (a < 0 || a > 1)
	{
		cin >> a;
		if (a == 0 || a == 1)
			break;
	}
	return a;
}

int menu_2()
{
	int a;
	cout << "\nAdd element of list in head on the list- 1\n"
		<< "Add element of list in end on the list - 2\n"
		<< "Delete element of list from head on the list - 3\n"
		<< "Delete element of list from end on the list - 4\n"
		<< "Delete element of list by value - 5\n"
		<< "Find element of list by value - 6\n"
		<< "Show list with change value of elements - 7\n"
		<< "Show list(elements won't change) - 8\n"
		<< "Insert - 9\n"
		<< "exit - 0\n"
		<< "Your choice: ";	cin >> a;
	return a;
}

using namespace Alex;
List& menu_3(List& a, const int r)
{
	double m = 0;
	switch (r)
	{
	case 1:
	{
		cout << "value: "; cin >> m;
		a.InsertInBeg(m);
		break;
	}
	case 2:
	{
		cout << "value: "; cin >> m;
		a.InsertInEnd(m);
		break;
	}
	case 3:	{ a.DeleteBeg(); break;	}
	case 4:	{ a.DeleteEnd(); break;	}
	case 5:
	{
		cout << "value: "; cin >> m;
		if (a.Delete(m))
			cout << "delete.\n";
		else
			cout << "not delete.\n";
		break;
	}
	case 6:
	{
		cout << "value: "; cin >> m;
		int count;
		if (count = a.Find(m))
			cout << "fount after " << count << " comparison(s)\n";
		else
			cout << "not found.\n";
		break;
	}
	case 7:	{ a.ForEach(umn2); a.ForEach(Print);  break; }
	case 8:	{ a.ForEach(Print);	break; }
	case 9:
	{
		cout << "value: "; cin >> m;
		a.Insert(m);
		a.ForEach(Print);
		break;
	}
	default:{ break; };
	}
	return a;
}