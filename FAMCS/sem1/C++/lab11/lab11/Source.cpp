#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int c = 25;	//длинна ФИО
const int m = 40;	//количество записей в файлах

struct Student
{
	long num;		//номер зачётки
	char name[25];	//фамилия, имя, отчество студента
	int group;		//номер группы
};


int headMenu(void);

int menu_1(void);

int menu_2(void);

int menu_3(void);

bool testName(char* nameChar);

void creationFile(string& filename);

bool testOfFilename(string& filename);

bool testOfClearFile(string& filename);

bool cmpStruct(Student arr1, Student arr2);

bool openAndLaunderFile(string& filename);

void showFile(string& filename, int number);

void showFile(string& filename);

void sortA(string& filename);

void sortB(string& filename);

void readingFilename(string& filename);

void readingFilename(string& filename, int number);

void unionFiles(string& filename_1, string& filename_2);

bool intersectionFiles(string& filename_1, string& filename_2);

bool differenceFiles(string& filename_1, string& filename_2);

void printInOutfile(string& filename);


int main()
{
	SetConsoleOutputCP(1251);	//с помощью Windows.h можно писать в консоль на русском
	SetConsoleCP(1251);

	switch (headMenu())
	{
	case 0:
	{
		cout << endl;
		return 1;
		break;
	}


	case 1:		//создание файлов
	{
		while (true)
		{
			switch (menu_1())
			{
			case 0:
			{
				cout << endl;
				return 1;
				break;
			}


			case 1:
			{
				string filename;
				readingFilename(filename);
				creationFile(filename);
				continue;
			}


			default:
				cout << endl << "error.\n";
			}
			break;
		}
	}


	case 2:		//работа с файлами
	{
		string filename_1, filename_2;
		readingFilename(filename_1, 1);
		readingFilename(filename_2, 2);
		string output = "output.las";

		switch (menu_2())
		{
		case 1:		//сортировка А
		{
			bool flag_1 = true, flag_2 = true;

			showFile(filename_1, 1);
			if (openAndLaunderFile(filename_1) == true)
			{
				cout << "\nчистка и сортировка..." << endl;
				sortA(filename_1);
				showFile(filename_1);
			}
			else
			{
				flag_1 = false;
				cout << "\nработа с файлом 1 не выполнена\n";
			}

			showFile(filename_2, 2);
			if (openAndLaunderFile(filename_2) == true)
			{
				cout << "\nчистка и сортировка..." << endl;
				sortA(filename_2);
				showFile(filename_2);
			}
			else
			{
				flag_2 = false;
				cout << "\nработа с файлом 2 не выполнена\n";
			}

			if (!flag_1 && !flag_2)
			{
				cout << "\nerror." << endl;
				return 1;
				break;
			}
			if (!flag_1 && flag_2)
			{
				printInOutfile(filename_2);
				showFile(output);
				return 1;
				break;
			}
			if (flag_1 && !flag_2)
			{
				printInOutfile(filename_1);
				showFile(output);
				return 1;
				break;
			}
			else if (flag_1 && flag_2)
			{
				switch (menu_3())		//операция над файлами
				{
				case 1:
				{
					unionFiles(filename_1, filename_2);
					openAndLaunderFile(output);
					cout << "\nданные успешно записаны в файл output.las" << endl;
					showFile(output);
					return 1;
					break;
				}


				case 2:
				{
					if (intersectionFiles(filename_1, filename_2))
						showFile(output);
					return 1;
					break;
				}


				case 3:
				{
					if (differenceFiles(filename_1, filename_2))
						showFile(output);
					return 1;
					break;
				}


				default:
					cout << "\nerror." << endl;
				}
				break;
			}
		}


		case 2:		//сортировка Б
		{
			bool flag_1 = true, flag_2 = true;

			showFile(filename_1, 1);
			if (openAndLaunderFile(filename_1) == true)
			{
				cout << "\nчистка и сортировка..." << endl;
				sortB(filename_1);
				showFile(filename_1);
			}
			else
			{
				flag_1 = false;
				cout << "\nработа с файлом 1 не выполнена\n";
			}

			showFile(filename_2, 2);
			if (openAndLaunderFile(filename_2) == true)
			{
				cout << "\nчистка и сортировка..." << endl;
				sortB(filename_2);
				showFile(filename_2);
			}
			else
			{
				flag_2 = false;
				cout << "\nработа с файлом 2 не выполнена\n";
			}

			if (!flag_1 && !flag_2)
			{
				cout << "\nerror." << endl;
				return 1;
				break;
			}
			if (!flag_1 && flag_2)
			{
				printInOutfile(filename_2);
				showFile(output);
				return 1;
				break;
			}
			if (flag_1 && !flag_2)
			{
				printInOutfile(filename_1);
				showFile(output);
				return 1;
				break;
			}
			else if (flag_1 && flag_2)
			{
				switch (menu_3())		//операция над файлами
				{
				case 1:
				{
					unionFiles(filename_1, filename_2);
					openAndLaunderFile(output);
					cout << "\nданные успешно записаны в файл output.las" << endl;
					showFile(output);
					return 1;
					break;
				}


				case 2:
				{
					if (intersectionFiles(filename_1, filename_2))
						showFile(output);
					return 1;
					break;
				}


				case 3:
				{
					if (differenceFiles(filename_1, filename_2))
						showFile(output);
					return 1;
					break;
				}


				default:
					cout << "\nerror." << endl;
				}
			}
			break;
		}


		default:
			cout << "\nerror." << endl;
		}
		break;
	}


	default:
	{
		cout << endl << "error.\n";
		return 1;
	}
	}

	return 0;
}


int headMenu(void)
{
	int k = 10;
	while (k < 0 || k > 2)
	{
		cout << "если хотите создать файл - нажмите 1.\n"
			 << "если хотите работать с имеющимися файлами - нажмите 2.\n"
			 << "если хотите завершить работу - нажмите 0.\n";
		cin >> k;
		cin.ignore();
		if (k < 0 || k > 2)
		{
			cout << "пожалуйста, читайте внимательнее.\n\n." << endl;
			continue;
		}
		else
			break;
	}
	return k;
}


int menu_1(void)
{
	int k = 10;
	while ((k < 0) || (k > 1))
	{
		cout << "\nесли хотите записать данные в файл - нажмите 1.\n"
			 << "если хотите прекратить - нажмите 0.\n";
		cin >> k;
		cin.ignore();
		if ((k < 0) || (k > 1))
		{
			cout << "пожалуйста, читайте внимательнее.\n\n";
			continue;
		}
		else break;
	}
	return k;
}


int menu_2(void)
{
	int k = 10;
	while ((k < 1) || (k > 2))
	{
		cout << "\nесли хотите отсортировать файлы по номерам зачёток - нажмите 1.\n"
			 << "если хотите отсортировать по группам, а внутри групп по фамилиям - нажмите 2.\n";
		cin >> k;
		cin.ignore();
		if ((k < 1) || (k > 2))
		{
			cout << "пожалуйста, читайте внимательнее.\n\n";
			continue;
		}
		else break;
	}
	return k;
}


int menu_3(void)
{
	int k = 10;
	while ((k < 1) || (k > 3))
	{
		cout << "\nесли хотите выполнить операцию объедениния над файлами - нажмите 1.\n"
			 << "если хотите выполнить операцию пересечения над файлами - нажмите 2.\n"
			 << "если хотите выполнить операцию разности над файлами - нажмите 3.\n";
		cin >> k;
		cin.ignore();
		if ((k < 1) || (k > 3))
		{
			cout << "пожалуйста, читайте внимательнее.\n\n";
			continue;
		}
		else break;
	}
	return k;
}


bool testName(char* nameChar)
{
	bool flag = false;
	string name = nameChar;
	if (name.length() < 1)
		return false;
	for (int i = 0; i < name.length(); ++i)
	{
		if (((name[i]<'A') && (name[i] != ' ')) || ((name[i]>'z') && (name[i] != ' ')))
			return false;
		if (name[i] != ' ')
			flag = true;
	}
	if (flag)
		return true;
	else
		return false;
}


void creationFile(string& filename)
{
	ofstream fout(filename, ios_base::binary);
	if (!fout)
	{
		cout << "\nфайл не создан.\n";
		return;
	}
	Student *arr = new Student[m];
	int max = -1;
	cout << "введите данные о студентах. если хотите прекратить ввод - введите номер зачётки равный 0:\n";
	while (true)
	{
		max++;
		cout << "\nномер зачётки: ";
		cin >> arr[max].num;
		cin.ignore();
		if (arr[max].num == 0)
			break;
		cout << "ФИО студента: ";
		cin.getline(arr[max].name, c);
		cout << "номер группы: ";
		cin >> arr[max].group;
		cin.ignore();
	}
	if (!max)
	{
		delete[] arr;
		fout.close();
		return;
	}
	for (int i = 0; i < max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();
	cout << "\nинформация записана в файл успешно." << endl;

	delete[] arr;
	return;
}


bool testOfFilename(string& filename)
{
	for (int i = 0; i < filename.length(); ++i)
	{
		if (!(((filename[i] >= '0') && (filename[i] <= '9')) || ((filename[i] >= 'A') && (filename[i] <= 'z'))))
			return false;
	}
	return true;
}


bool testOfClearFile(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin)
		return false;
	fin.seekg(0, fin.beg);
	int n = fin.tellg();
	fin.seekg(0, fin.end);
	int k = fin.tellg();
	fin.close();
	if (n == k)
		return false;
	else
		return true;
}


bool cmpStruct(Student arr1, Student arr2)
{
	if (arr1.num == arr2.num && arr1.group == arr2.group && strcmp(arr1.name, arr2.name) == NULL)
		return true;
	else
		return false;
}


bool openAndLaunderFile(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if ((!fin) || (testOfClearFile(filename) == false))
		return false;

	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = (length / sizeof(Student));
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	for (int i = 0; i < max - 1; ++i)
	{
		for (int j = i + 1; j < max; ++j)
		{
			if ((arr[i].num == arr[j].num && arr[i].group == arr[j].group && strcmp(arr[i].name, arr[j].name) == NULL) ||
				(testName(arr[i].name) == false || testName(arr[j].name) == false || arr[i].num < 1 || arr[j].num < 1 ||
				arr[i].group < 1 || arr[j].group < 1))
			{
				if (j == max)
					max--;
				else if (j == max - 1)
				{
					arr[j] = arr[j + 1];
					max--;
				}
				else
				{
					for (int z = j; z < max - 1; ++z)
						arr[z] = arr[z + 1];
					max--;
				}
			}
			else if (arr[i].num == arr[j].num)
			{
				if (j == max)
				{
					max--;
					for (int z = i; z < max - 1; ++z)
						arr[z] = arr[z + 1];
					max--;
				}
				else if (j == max - 1)
				{
					arr[j] = arr[j + 1];
					max--;
					for (int z = i; z < max - 1; ++z)
						arr[z] = arr[z + 1];
					max--;
				}
				else
				{
					for (int z = j; z < max - 1; ++z)
						arr[z] = arr[z + 1];
					max--;
					for (int z = i; z < max - 1; ++z)
						arr[z] = arr[z + 1];
					max--;
				}
			}
		}
	}
	ofstream fout(filename, ios_base::binary | ios_base::trunc);
	if (!fout)
	{
		delete[] arr;
		return false;
	}
	for (int i = 0; i < max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();

	delete[] arr;
	return true;
}


void showFile(string& filename, int number)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin)
	{
		cout << "\nфайл " << number << " не открыт.\n";
		return;
	}

	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = length / sizeof(Student);
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	cout << "\nсодержимое файла " << number << ":";
	for (int i = 0; i < max; ++i)
	{
		cout << endl << arr[i].num << " | " << arr[i].name << " | " << arr[i].group << endl;
	}

	delete[] arr;
	return;
}


void showFile(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin)
	{
		cout << "\nфайл не открыт.\n";
		return;
	}

	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = length / sizeof(Student);
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	cout << "\nсодержимое файла:";
	for (int i = 0; i < max; ++i)
	{
		cout << endl << arr[i].num << " | " << arr[i].name << " | " << arr[i].group << endl;
	}

	delete[] arr;
	return;
}


void sortA(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin){
		cout << "\nфайл не открыт.\n";
		return;
	}
	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = (length / sizeof(Student));
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	for (int i = 0; i < max - 1; ++i)
	{
		for (int j = i + 1; j < max; ++j)
			if (arr[i].num > arr[j].num)
			{
				Student temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}

	ofstream fout(filename, ios_base::binary | ios_base::trunc);
	if (!fout)
	{
		cout << "\nошибка сортировки." << endl;
		delete[] arr;
		return;
	}
	for (int i = 0; i < max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();

	delete[] arr;
	return;
}


void sortB(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin)
	{
		cout << "\nфайл не открыт." << endl;
		return;
	}
	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = (length / sizeof(Student));
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	for (int i = 0; i < max - 1; ++i)
	{
		for (int j = i + 1; j < max; ++j)
			if ((arr[i].group > arr[j].group) || (strcmp(arr[i].name, arr[j].name)>0 && arr[i].group == arr[j].group))
			{
				Student temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}

	ofstream fout(filename, ios_base::binary | ios_base::trunc);
	if (!fout)
	{
		cout << "\nошибка сортировки." << endl;
		delete[] arr;
		return;
	}
	for (int i = 0; i < max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();

	delete[] arr;
	return;
}


void readingFilename(string& filename)
{
	while (true)
	{
		cout << "\nвведите название файла: ";
		getline(cin, filename);
		if (testOfFilename(filename))
			break;
		else
		{
			cout << "\nзапрещённые символы";
			continue;
		}
	}
	filename += ".las";
	return;
}


void readingFilename(string& filename, int number)
{
	while (true)
	{
		cout << "\nвведите название файла " << number << ": ";
		getline(cin, filename);
		if (testOfFilename(filename) == true)
			break;
		else
		{
			cout << "\nзапрещённые символы";
			continue;
		}
	}
	filename += ".las";
	return;
}


void unionFiles(string& filename_1, string& filename_2)
{
	ifstream fin_1(filename_1, ios_base::binary);
	if (!fin_1)
		return;
	ifstream fin_2(filename_2, ios_base::binary);
	if (!fin_2)
		return;

	Student *arr_1 = new Student[m];
	fin_1.seekg(0, fin_1.end);
	long length_1 = fin_1.tellg();
	long max_1 = (length_1 / sizeof(Student));
	fin_1.seekg(0, fin_1.beg);
	for (int i = 0; i < max_1; ++i)
	{
		fin_1.seekg(i*sizeof(Student), fin_1.beg);
		fin_1.read(reinterpret_cast<char*>(&arr_1[i]), sizeof(Student));
	}
	fin_1.close();

	Student *arr_2 = new Student[m];
	fin_2.seekg(0, fin_2.end);
	long length_2 = fin_2.tellg();
	long max_2 = (length_2 / sizeof(Student));
	fin_2.seekg(0, fin_2.beg);
	for (int i = 0; i < max_2; ++i)
	{
		fin_2.seekg(i*sizeof(Student), fin_1.beg);
		fin_2.read(reinterpret_cast<char*>(&arr_2[i]), sizeof(Student));
	}
	fin_2.close();

	for (int i = 0; i < max_1; ++i)
	{
		for (int j = 0; j < max_2; ++j)
		{
			if (cmpStruct(arr_1[i], arr_2[j]) == true)
			{
				for (int z = j; z < max_2; z++)
					arr_2[z] = arr_2[z + 1];
				max_2--;
			}
			else
				continue;
		}
	}

	Student *arr = new Student[max_1 + max_2];
	int max = -1;
	for (int i = 0; i < max_1; ++i)
	{
		max++;
		arr[max] = arr_1[i];
	}
	delete[] arr_1;
	for (int i = 0; i < max_2; ++i)
	{
		max++;
		arr[max] = arr_2[i];
	}
	delete[] arr_2;
	if (max == -1)
	{
		cout << "\nerror." << endl;
		return;
	}

	ofstream fout("output.las", ios_base::binary);
	if (!fout)
		return;
	for (int i = 0; i <= max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();
	
	delete[] arr;
	return;
}


bool intersectionFiles(string& filename_1, string& filename_2)
{
	ifstream fin_1(filename_1, ios_base::binary);
	if (!fin_1)
		return false;
	ifstream fin_2(filename_2, ios_base::binary);
	if (!fin_2)
		return false;

	Student *arr_1 = new Student[m];
	fin_1.seekg(0, fin_1.end);
	long length_1 = fin_1.tellg();
	long max_1 = (length_1 / sizeof(Student));
	fin_1.seekg(0, fin_1.beg);
	for (int i = 0; i < max_1; ++i)
	{
		fin_1.seekg(i*sizeof(Student), fin_1.beg);
		fin_1.read(reinterpret_cast<char*>(&arr_1[i]), sizeof(Student));
	}
	fin_1.close();

	Student *arr_2 = new Student[m];
	fin_2.seekg(0, fin_2.end);
	long length_2 = fin_2.tellg();
	long max_2 = (length_2 / sizeof(Student));
	fin_2.seekg(0, fin_2.beg);
	for (int i = 0; i < max_2; ++i)
	{
		fin_2.seekg(i*sizeof(Student), fin_1.beg);
		fin_2.read(reinterpret_cast<char*>(&arr_2[i]), sizeof(Student));
	}
	fin_2.close();

	int max = -1;
	Student *arr = new Student[max_1 + max_2];
	for (int i = 0; i < max_1; ++i)
	{
		for (int j = 0; j < max_2; ++j)
		{
			if (cmpStruct(arr_1[i], arr_2[j]) == true)
			{
				max++;
				arr[max] = arr_1[i];
			}
			else
				continue;
		}
	}
	delete[] arr_1;
	delete[] arr_2;
	if (max == -1)
	{
		cout << "\nнет пересечений" << endl;
		return false;
	}

	ofstream fout("output.las", ios_base::binary);
	if (!fout)
		return false;
	for (int i = 0; i <= max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();
	cout << "\nданные успешно записаны в файл output.las" << endl;

	delete[] arr;
	return true;
}


bool differenceFiles(string& filename_1, string& filename_2)
{
	ifstream fin_1(filename_1, ios_base::binary);
	if (!fin_1)
		return false;
	ifstream fin_2(filename_2, ios_base::binary);
	if (!fin_2)
		return false;

	Student *arr_1 = new Student[m];
	fin_1.seekg(0, fin_1.end);
	long length_1 = fin_1.tellg();
	long max_1 = (length_1 / sizeof(Student));
	fin_1.seekg(0, fin_1.beg);
	for (int i = 0; i < max_1; ++i)
	{
		fin_1.seekg(i*sizeof(Student), fin_1.beg);
		fin_1.read(reinterpret_cast<char*>(&arr_1[i]), sizeof(Student));
	}
	fin_1.close();

	Student *arr_2 = new Student[m];
	fin_2.seekg(0, fin_2.end);
	long length_2 = fin_2.tellg();
	long max_2 = (length_2 / sizeof(Student));
	fin_2.seekg(0, fin_2.beg);
	for (int i = 0; i < max_2; ++i)
	{
		fin_2.seekg(i*sizeof(Student), fin_1.beg);
		fin_2.read(reinterpret_cast<char*>(&arr_2[i]), sizeof(Student));
	}
	fin_2.close();

	bool flag = false;
	int max = -1;
	Student *arr = new Student[max_1 + max_2];
	for (int i = 0; i < max_1; ++i)
	{
		flag = true;
		for (int j = 0; j < max_2; ++j)
		{
			if (cmpStruct(arr_1[i], arr_2[j]) == true)
				flag = false;
		}
		if (flag == true)
		{
			max++;
			arr[max] = arr_1[i];
		}
	}
	delete[] arr_1;
	delete[] arr_2;
	if (max == -1)
	{
		cout << "\nнет подходящиx записей." << endl;
		return false;
	}

	ofstream fout("output.las", ios_base::binary);
	if (!fout)
		return false;
	for (int i = 0; i <= max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();
	cout << "\nданные успешно записаны в файл output.las" << endl;

	delete[] arr;
	return true;
}


void printInOutfile(string& filename)
{
	ifstream fin(filename, ios_base::binary);
	if (!fin)
		return;

	Student *arr = new Student[m];
	fin.seekg(0, fin.end);
	long length = fin.tellg();
	long max = (length / sizeof(Student));
	fin.seekg(0, fin.beg);
	for (int i = 0; i < max; ++i)
	{
		fin.seekg(i*sizeof(Student), fin.beg);
		fin.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fin.close();

	ofstream fout("output.las", ios_base::binary | ios_base::trunc);
	if (!fout)
	{
		delete[] arr;
		return;
	}
	for (int i = 0; i < max; ++i)
	{
		fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
	}
	fout.close();
	cout << "\nинформация записана в выходной файл output.las\n";

	delete[] arr;
	return;
}