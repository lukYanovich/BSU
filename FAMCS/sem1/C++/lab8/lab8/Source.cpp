#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, separators, newStr;
	cout << "enter line:\n";
	getline(cin, str);
	cout << endl;
	if (str.empty()){
		cout << "line is empty.\n";
		return 1;
	}
	cout << "enter separators:\n";
	getline(cin, separators);
	cout << endl;
	if (separators.empty()){
		cout << "line of separators is empty.\n";
		return 1;
	}

	str += separators;
	newStr.clear();
	int n = 0, k = 0, lenght = 0;
	int flag = 0;
	if (n = str.find_first_not_of(separators, k) == -1)
		flag = 2;
	while ((n = str.find_first_not_of(separators, k)) != -1){ //первый символ, не входящий в separators, начиная с k
		int count = 0;
		k = str.find_first_of(separators, n);				  //первый символ, входящий в separators, начиная с n
		for (int i = n, j = k - 1; i < j; j--, i++){		  //наше слово лежит между n(начало) и k(конец): n<слово<k
			if (str[i] == str[j]){
				count++;
			}
		}
		if (count == (k - n) / 2 && (k - n) > lenght){
			lenght = k - n;
			newStr.clear();
		}
		if (count == (k - n) / 2 && (k - n) == lenght){
			for (int i = n; i < k; i++){
				newStr += str[i];
			}
			newStr += ",";
			flag = 1;
		}
	}
	if (flag == 1)
		cout << newStr.erase(newStr.length() - 1, 1) << "." << endl;
	else if (flag == 0)
		cout << "this line does not contain any palindroms.\n";
	else if (flag == 2)
		cout << "this line does not contain any words.\n";
	return 0;
}