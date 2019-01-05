#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstring>
using namespace std;

template<class T> void _create(T** &arr, const unsigned n, const unsigned m){
	arr = new myType*[n];
	for (unsigned i(0); i < n; ++i)
		arr[i] = new myType[m];
	srand((unsigned)time(NULL));
	myType a = -100, b = 100;
	for (unsigned i(0); i < n; ++i)
		for (unsigned j(0); j < m; ++j)
			arr[i][j] = a + rand() % (b - a + 1);
}

template<> void _create<char*>(char*** &arr, const unsigned n, const unsigned m){
	arr = new char**[n];
	for (unsigned i(0); i < n; ++i)
		arr[i] = new char*[m];
	srand((unsigned)time(NULL));
	unsigned a = 5, b = 8, _a = 65, _b = 90;
	for (unsigned i(0); i < n; ++i)
		for (unsigned j(0); j < m; ++j){
			unsigned size = a + rand() % (b - a + 1);
			arr[i][j] = new char[++size];
			for (unsigned k(0); k < size - 1; ++k)
				arr[i][j][k] = static_cast<char>(_a + rand() % (_b - _a + 1));
			arr[i][j][size - 1] = '\0';
		}
}

template<class T> void _createByHands(T** &arr, const unsigned n, const unsigned m){
	arr = new myType*[n];
	for (unsigned i(0); i < n; ++i)
		arr[i] = new myType[m];
	for (unsigned i(0); i < n; ++i)
		for (unsigned j(0); j < m; ++j)
			cin >> arr[i][j];
}

template<> void _createByHands<char*>(char*** &arr, const unsigned n, const unsigned m){
	arr = new char**[n];
	for (unsigned i(0); i < n; ++i)
		arr[i] = new char*[m];
	cout << "enter matrix " << n << 'x' << m << ':' << endl;
	for (unsigned i(0); i < n; ++i)
		for (unsigned j(0); j < m; ++j){
			arr[i][j] = new char[81];
			cin.get(arr[i][j], 80, '\n');
			cin.ignore();
		}
}

template<class T> void _delete(T** &arr, const unsigned n, const unsigned m){
	for (unsigned i(0); i < n; ++i)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

template<> void _delete<char*>(char*** &arr, const unsigned n, const unsigned m){
	for (unsigned i(0); i < n; ++i)
		for (unsigned j(0); j < m; ++j)
			delete[] arr[i][j];
	delete[] arr;
	arr = nullptr;
}

template<class T> void _show(T** arr, const unsigned n, const unsigned m){
	cout << "matrix " << n << 'x' << m << " :\n";
	for (unsigned i(0); i < n; ++i){
		for (unsigned j(0); j < m; ++j)
			cout << arr[i][j] << '\t';
		cout << endl;
	}
}

template<> void _show<char*>(char*** arr, const unsigned n, const unsigned m){
	cout << "matrix " << n << 'x' << m << " :\n";
	for (unsigned i(0); i < n; ++i){
		for (unsigned j(0); j < m; ++j)
			cout << arr[i][j] << " || ";
		cout << endl;
	}
}

template<class T> unsigned _search(T** arr, const unsigned n, const unsigned m){
	if (arr == nullptr)
		throw exception("matrix don't creation.");
	unsigned count = 0, max_count = 0, column = 0;
	for (unsigned i(0); i < m; ++i)
		for (unsigned j(0); j < n - 1; ++j)
			if (arr[j][i] == arr[j + 1][i]){
				count++;
				if (count >= max_count){
					column = i;
					max_count = count;
				}
			}
			else
				count = 0;
	return column + 1;
}

template<> unsigned _search<char*>(char*** arr, const unsigned n, const unsigned m){
	if (arr == nullptr)
		throw exception("matrix don't creation.");
	unsigned count = 0, max_count = 0, column = 0;
	for (unsigned i(0); i < m; ++i)
		for (unsigned j(0); j < n - 1; ++j)
			if (!strcmp(arr[j][i], arr[j + 1][i])){
				count++;
				if (count >= max_count){
					column = i;
					max_count = count;
				}
			}
			else
				count = 0;
	return column + 1;
}