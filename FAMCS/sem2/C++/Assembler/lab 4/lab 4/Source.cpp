#include "MyArray.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		int n, *arr = _create(n);
		MyArray a = MyFunction(arr, n);
		cout << "\nповторы: " << a << endl;
		delete[] arr;
	}
	catch (exception& ex) { system("cls"); cout << ex.what() << endl; }
	//cin.get(); cin.get();
	return 0;
}