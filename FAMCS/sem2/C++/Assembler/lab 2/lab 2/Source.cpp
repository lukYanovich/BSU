#include <iostream>
#include <vector>

using namespace std;
#define forever for(;;)
typedef unsigned short ushort;

void show(const int*, const int);
int** _create(int&);
void _clearMemory(int**&, int*&);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".1251");
	int n;	//размер массива
	try {
		int** arr1 = _create(n); //1 строка : наш массив
								 //2 строка : количество повторений. 0 - если элемент уже подсчитан ранее
		int* arr2 = new int[n];	//массив с результатом
		int count = 0, maxCount, k;

		/*forever {
			maxCount = k = 0;
			for (int i(0); i < n; ++i)
				if (arr1[1][i] >= maxCount)
					maxCount = arr1[1][k = i];
			if (!maxCount)
				break;
			arr2[count++] = arr1[0][k];
			arr1[1][k] = 0;
		}*/

		_asm {
			mov		eax, arr1	
			mov		ebx, arr2	

			_forever :
			mov		ecx, 0
			mov		maxCount, 0
			mov		k, 0
				_for :
					mov		esi, maxCount
					mov		edx, [eax + 4]
					mov		edx, [edx][4 * ecx]
					cmp		edx, esi
					jbe		_false
						mov		maxCount, edx
						mov		k, ecx
					_false:
						inc		ecx
						cmp		ecx, n
						jne		_for

			cmp maxCount, 0
			je	_end
			
			mov		esi, count
			mov		edi, k
			
			mov		edx, [eax]
			mov		edx, [edx][4 * edi]
			mov		[ebx][4 * esi], edx
			inc		esi
			mov		count, esi
			mov		edx, [eax + 4]
			mov		[edx][4 * edi], 0

			jmp		_forever
			_end :
		}
		
		cout << "повторы: ";
		show(arr2, count);
		_clearMemory(arr1, arr2);
	}
	catch (exception& ex) { system("cls"); cout << ex.what() << endl; }
	return 0;
}


int** _create(int& n) {
	vector<int> v;
	cout << "введите массив(ctr+z для прекращения ввода):\n";
	forever {
		int temp;
		cin >> temp;
		if (cin.good())
			v.push_back(temp);
		else {
			cin.clear();
			system("cls");
			cout << "массив: ";
			for (auto i : v)
				cout << i << ' ';
			cout << endl;
			break;
		}
	}
	if (v.empty())
		throw exception("неверные исходные данные.");
	int** arr = new int*[2];
	arr[0] = new int[n = v.size()];
	arr[1] = new int[n];
	ushort j(0);
	for (auto i : v)
		arr[0][j++] = i;

	for (ushort i(0); i < n; ++i)
		arr[1][i] = 1;
	for (ushort i(0); i < n - 1; ++i) {
		if (!arr[1][i])
			continue;
		for (j = i + 1; j < n; ++j)
			if (arr[0][i] == arr[0][j]) {
				arr[1][j] = 0;
				arr[1][i]++;
			}
	}
	return arr;
}


void show(const int* arr,const int n) {
	for (ushort i(0); i < n; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}


void _clearMemory(int**& arr1, int*& arr2) {
	delete[] arr1[0];
	delete[] arr1[1];
	delete[] arr2;
	arr1 = nullptr;
	arr2 = nullptr;
}