#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
typedef unsigned short ushort;
char* read(int&, const int);
void _clearMemory(char*&, char*&, char*&);
void _clearMemory(char*&, char*&);
void _showNewLine(char*&);

int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	int n1, n2;
	char* str1 = read(n1, 1);
	char* str2 = read(n2, 2);
	try {
		if (n2 > n1 || !n2)
			throw exception("неверные данные.");
		int n = -1, _flag, temp;
		int n3 = n1 - n2;
		char* str3 = new char[n3 + 1];

		/*for (ushort i(0); i < n1; ++i) {
			bool flag = true;
			for (ushort j(0); j < n2; ++j)
				if (str1[i + j] != str2[j]) {
					flag = false;
					break;
				}
			if (flag) {
				n = i;
				break;
			}
		}*/

		/*for (ushort i(0); i < n; ++i)
		str3[i] = str1[i];
		for (ushort i(n); i < n3; ++i)
		str3[i] = str1[i + n2];
		str3[n3] = '\0';*/

		_asm {
			mov		esi, str1
			mov		edi, str2
			xor		ecx, ecx	//i			

			_for1:
				mov		_flag, 1
				xor		edx, edx	//j
				_for2:
					mov		temp, edx
					add		edx, ecx
					mov		al, [esi][edx]
					mov		edx, temp
					mov		bl, [edi][edx]

					cmp		al, bl
					je		_false
					mov		_flag, 0
					jmp		m

					_false:
					inc		edx
					cmp		edx, n2
					jne		_for2

		m:
			cmp		_flag, 1
			jne		false_
			mov		n, ecx
			jmp		_m

			false_:
			inc		ecx
			cmp		ecx, n1
			jne		_for1
		_m:
			cmp		n, -1
			je		_error
		


			mov		edi, str3
			xor		ecx, ecx
			cmp		n, 0
			je		_endM1

			_m1:
				mov		al, [esi][ecx]
				mov		[edi][ecx], al
				inc		ecx
				cmp		ecx, n
				jl		_m1

			_endM1:
			mov		eax, n2

			_m2:
				mov		edx, ecx
				add		edx, eax
				mov		bl, [esi][edx]
				mov		[edi][ecx], bl
				inc		ecx
				cmp		ecx, n3
				jl		_m2
			
			mov		ecx, n3
			mov		[edi][ecx], '\0'

			_error:
		}

		if (n == -1) {
			cout << "attention: строка \"2\" не входит в строку \"1\"" << endl;
			_clearMemory(str1, str2, str3);
			return 1;
		}
		_showNewLine(str3);
	}
	catch (exception& ex) { system("cls"); cout << ex.what() << endl; }
	_clearMemory(str1, str2);
	return 0;
}


char* read(int& length, const int numberLine) {
	cout << "введите строку \"" << numberLine << "\":\n";
	string str;
	cin >> str;
	char* temp = new char[(length = str.length()) + 1];
	for (int i(0); i < length; ++i)
		temp[i] = str[i];
	temp[length] = '\0';
	return temp;
}


void _clearMemory(char*& str1, char*& str2, char*& str3) {
	delete[] str1;
	delete[] str2;
	delete[] str3;
	str1 = str2 = str3 = nullptr;
}


void _clearMemory(char*& str1, char*& str2) {
	delete[] str1;
	delete[] str2;
	str1 = str2 = nullptr;
}


void _showNewLine(char* &str) {
	cout << "строка \"1\" без первого вхождения строки \"2\":" << endl;
	if (str[0] == '\0')
		cout << "строка пуста." << endl;
	else
		cout << str << endl;
	delete[] str;
	str = nullptr;
}