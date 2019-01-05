/* использовать ДИНАМИЧЕСКИЙ массив. при заполнении массива предусмотреть два способа: ввод с 
клавиатуры и заполнение случайными числами.
В последнем случае перед заполнением массива ввести границы интервала, которому должны 
принадлежать элементы массива.  
- перестроить целочисленную матрицу, переставляя в ней строки так, чтобы сумма элементов 
в строках полученной матрицы возрастала.
- найти в ней номер первого из столбцов, не содержащих отрицательных элементов. */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	int m = 0, n = 0, k = 0;	// изначально неверные значения
	while (!(n > 0)){
		cout << "введите количество строк в матрице: ";
		cin >> n;
		if (n < 1)
			cout << "error" << endl;
		continue;
	}
	while (!(m > 0)){
		cout << "введите количество столбцов в матрице: ";
		cin >> m;
		if (m < 1)
			cout << "error" << endl;
		continue;
	}
	if ((n == 1) && (m == 1))
		cout << "\nмассив состоит из одного элемента\n";
	else{
		// выделение памяти

		int **mas; // объявление "указатель на указатель на integer
		int i, j, a, b;
		mas = new int *[n]; // память под массив указателей на строки
		for (i = 0; i < n; i++) // цикл для выделения памяти под каждую строку
			mas[i] = new int[m]; // каждому элементу массива указателей на строки присваивается адрес
		// начала участка памяти,выделенного под строку из m целых чисел

		while (!((k >= 1) && (k <= 2))){
			cout << "\nЕсли хотите заполнить массив сами, то введите 1. Если хотите заполнить массив случайными числами - введите 2: ";
			cin >> k;
			if ((k < 1) || (k>2))
				cout << "error" << endl;
			continue;
		}

		if (k == 1){
			cout << "\nвведите элементы массива:\n";
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					cin >> mas[i][j];
		}
		if (k == 2){
			cout << "введите границы промежутка случайных чисел:\n";
			cin >> a;
			cin >> b;
			cout << endl;
			if (a == b){
				for (i = 0; i < n; i++)
					for (j = 0; j < m; j++)
						mas[i][j] = a;
			}
			if (a != b){
				if (a > b){
					int temp = a;
					a = b;
					b = temp;
				}
				srand(time(NULL));
				for (i = 0; i < n; i++)
					for (j = 0; j < m; j++)
						mas[i][j] = a + rand() % (b - a + 1);
			}
			for (i = 0; i < n; i++){
				for (j = 0; j < m; j++){
					cout << "\t" << mas[i][j];
				}
				cout << endl;
			}
		}
		// переходим к решению

		for (i = 0; i < n - 1; i++){
			for (int z = i + 1; z < n; z++){
				int sum = 0, sumNext = 0;
				for (j = 0; j < m; j++){
					sum += mas[i][j];
					sumNext += mas[z][j];
				}
				if (sum > sumNext){
					for (j = 0; j < m; j++){
						int temp = mas[i][j];
						mas[i][j] = mas[z][j];
						mas[z][j] = temp;
					}
				}
			}
		}
		cout << "\nпреобразованная матрица:\n";
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cout << "\t" << mas[i][j];
			}
			cout << endl;
		}

		bool flag = false;
		for (i = 0; i < m; i++){
			flag = false;
			for (j = 0; j < n; j++){
				if (mas[j][i] < 0){
					flag = true;
					break;
				}
			}
			if (!flag){
				cout << "\nстолбец " << (i + 1) << " не содержит отрицательных элементов\n";
				break;
			}
		}
		if (flag){
			cout << "\nматрица не имеет столбцов без отрицательных элементов\n";
		}

		for (int i = 0; i < n; i++)
			delete[] mas[i];
		delete[] mas;
	}
	return 0;
}