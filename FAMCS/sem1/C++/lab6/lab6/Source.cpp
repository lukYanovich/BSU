#include "functions.hpp"

void Swap(int *Mas, short i);

void ShakerSort(int *Mas, int Start, short N);

int main()
{
	setlocale(LC_ALL, ".1251");

	std::ofstream fout("conclusion.txt");
	if (!fout){
		std::cout << "output file not open.\n";
		return 1;
	}
	short k = 10;
	int a, b;

	while (!(k >= 1 && k <= 3)){
		std::cout << "Если хотите заполнить массив вручную - введите 1.";
		std::cout << "\nЕсли хотите заполнить массив случайными числами - введите 2.";
		std::cout << "\nЕсли хотите взять исходные данные из файла - введите 3.";
		std::cout << "\nВаш выбор: ";
		std::cin >> k;
		if ((k < 1) || (k>3))
			std::cout << "error\n" << std::endl;
		continue;
	}

	if (k == 1){
		short n = 0;
		while (n < 2){
			std::cout << "Введите количество элементов массива(более одного): ";
			std::cin >> n;
			if (n < 2)
				std::cout << "error\n" << std::endl;
			continue;
		}

		int * pMas = new int[n];
		std::cout << "\nвведите элементы массива:\n ";
		for (short i = 0; i < n; i++)
			std::cin >> pMas[i];

		std::cout << "преобразования:\n";
		ShakerSort(pMas, 1, n);
		fout << "преобразованный массив:\n";
		for (short i = 0; i < n; i++)
			fout << " " << pMas[i];

		fout.close();
		delete[] pMas;
		pMas = 0;

		return 0;
	}

	if (k == 2){
		short n = 0;
		while (n < 2){
			std::cout << "Введите количество элементов массива(более одного): ";
			std::cin >> n;
			if (n < 2)
				std::cout << "error\n" << std::endl;
			continue;
		}

		std::cout << "введите границы промежутка случайных чисел:\n";
		std::cin >> a >> b;

		int * pMas = new int[n];
		if (a == b)
			for (short i = 0; i < n; i++)
				pMas[i] = a;
		if (a != b){
			if (a > b){
				int temp = a;
				a = b;
				b = temp;
			}
			srand(time(NULL));
			for (short i = 0; i < n; i++)
				pMas[i] = a + rand() % (b - a + 1);
		}	// закрываем рандомный ввод

		std::cout << "исходный массив:\n";
		for (short i = 0; i < n; i++)
			std::cout << " " << pMas[i];

		std::cout << "\nпреобразования:" << std::endl;
		ShakerSort(pMas, 1, n);
		fout << "преобразованный массив:\n";
		for (short i = 0; i < n; i++)
			fout << " " << pMas[i];

		fout.close();
		delete[] pMas;
		pMas = 0;

		return 0;
	}

	if (k == 3){
		std::ifstream fin("input.txt");
		if (!fin){
			std::cout << "\aВходной файл не открылся.\n";
			return 1;
		}

		short n = 0;
		int *pMas = new int[500];

		while (fin){
			fin >> pMas[n];
			n++;
			if (!fin){
				n--;
				break;
			}
		}
		if (!n){
			std::cout << "\aФайл пуст либо перед первым элементом не только разделители\n";
			return 1;
		}

		std::cout << std::endl;
		for (short i = 0; i < n; i++){
			std::cout << " " << pMas[i];
		}

		std::cout << "\nпреобразования:" << std::endl;
		ShakerSort(pMas, 1, n);
		fout << "преобразованный массив:\n";
		for (short i = 0; i < n; i++)
			fout << " " << pMas[i];

		fout.close();
		fin.close();
		delete[] pMas;
		pMas = 0;

		return 0;
	}
	return 0;
}