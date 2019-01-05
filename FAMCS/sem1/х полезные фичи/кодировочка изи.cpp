#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);	//с помощью Windows.h можно писать в консоль на русском
	SetConsoleCP(1251);
	string str, com = "хуй", temp;
	getline(cin, str);
	for (size_t i(0); i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			size_t k = i;
			while (str[k] == ' ')
				k++;
			for (size_t j(k); j < str.length(); ++j)
				temp += str[j];
			str.erase(i);
			str = str + com + temp;
			temp.erase();
		}
	}
	cout << str << endl;
	return 0;
}