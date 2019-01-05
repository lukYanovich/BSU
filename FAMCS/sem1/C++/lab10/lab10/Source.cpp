#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	if (!fin)
	{
		cout << "input file not open.\n";
		return 1;
	}

	const int c = 1000;
	string str, word;
	string *arrayOfStrings = new string[c];
	string separators = " ";	//задаём чем разделены слова
	int max = 0, n = 0, k = 0;
	int counterOfWords = 0, maxCounter = 0, counterOfStrings = 0, counterOfEmpty = 0;
	bool flag = false;

	while (fin.good())
	{
		getline(fin, str);
		counterOfEmpty += 2;
		if (str[0] == '\0')
		{
			counterOfEmpty--;
			continue;
		}

		k = 0;
		if ((n = str.find_first_not_of(separators, k)) == -1)
			continue;
		str += separators;
		counterOfWords = 0;
		while ((n = str.find_first_not_of(separators, k)) != -1)
		{
			flag = true;
			k = str.find_first_of(separators, n);
			counterOfWords++;
		}

		if (maxCounter < counterOfWords)
		{
			max = 0;
			counterOfStrings = 0;
			str.erase(str.length() - separators.length());
			arrayOfStrings[max] = str;
			maxCounter = counterOfWords;
		}
		else if ((maxCounter == counterOfWords) && (counterOfStrings < 9))
		{
			max++;
			counterOfStrings++;
			str.erase(str.length() - separators.length());
			arrayOfStrings[max] = str;
		}
	}
	fin.close();	//закрыли файл
	if ((counterOfEmpty == 1) && (!flag))
	{
		cout << "input file is empty.\n";
		delete[] arrayOfStrings;
		return 1;
	}	
	if (!flag)
	{
		cout << "input file does not contain any words.\n";
		delete[] arrayOfStrings;
		return 1;
	}

	cout << "line with the largest number of words(or first 10 lines, if there are several ):\n";
	for (int i = 0; i <= max; i++)
		cout << arrayOfStrings[i] << "\n";
	cout << endl;

	delete[] arrayOfStrings;
	return 0;
}