#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	FILE *fin;
	if (!(fin = fopen("input.txt", "r")))
	{
		cout << "input file not open.\n";
		return 1;
	}

	const short c = 1000;
	char *strChar = new char[c];
	string str, word;
	string *arrayOfWords = new string[c];
	string separators = " ";	//выбираем чем разделены слова
	short max = 0, k = 0, n = 0;
	short counterOfEmpty = 0;
	bool flag = false;

	while (!feof(fin))
	{
		counterOfEmpty += 2;;
		if (!fgets(strChar, c - 1, fin))
		{
			counterOfEmpty--;
			continue;
		}
		str = strChar;
		if ((str[str.length() - 1] == '\0') || (str[str.length() - 1] == '\n'))
			str.erase(str.length() - 1);

		k = 0;
		str += separators;
		while ((n = str.find_first_not_of(separators, k)) != -1)
		{															//нашело слово заключено
			flag = true;											//между n(начало) и k(конец)
			k = str.find_first_of(separators, n);					// n < слово < k
			for (short i = n; i < k; i++)
				word += str[i];
			arrayOfWords[max] = word;
			word.clear();
			max++;
		}
		str.clear();
	}
	fclose(fin);	//закрываем файл

	if ((counterOfEmpty == 1) && (!flag))
	{
		cout << "input file is empty.\n";
		delete[] arrayOfWords;
		delete[] strChar;
		return 1;
	}
	if (!flag)		//проверка не только ли из разделителей состоит файл
	{
		cout << "input file does not contain any words.\n";
		delete[] arrayOfWords;
		delete[] strChar;
		return 1;
	}

	short counter = 0, maxCounter = 0;
	string frequentWord;	//frequent - частый, часто встречающийся
	for (short i = 0; i < max; i++)
	{
		counter = 0;
		for (short j = i; j < max; j++)
		{
			if (arrayOfWords[i] == arrayOfWords[j])
				counter++;
		}
		if (maxCounter < counter)
		{
			frequentWord = arrayOfWords[i];
			maxCounter = counter;
		}
	}
	cout << "frequent word in this file:\n" << frequentWord << endl;

	delete[] arrayOfWords;
	delete[] strChar;
	return 0;
}