#include "MyArray.h"

MyArray::MyArray(const int* _arr, const int n) {
	arr = new int[size = n];
	for (ushort i(0); i < size; ++i)
		arr[i] = _arr[i];
}

MyArray& MyArray::operator=(const MyArray& a) {
	if (this == &a)
		return *this;
	Copy(a);
	return *this;
}


void MyArray::Erase(){
	delete[] arr;
	arr = nullptr;
	size = 0;
}


void MyArray::SetSize(const int n) {
	if (n == size)
		return;
	int* newArr = new int[size = n];
	for (ushort i(0); i < size; ++i)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
}


ostream& operator<<(ostream& os, const MyArray a) {
	for (ushort i(0); i < a.size; ++i)
		os << a.arr[i] << ' ';
	return os;
}


void MyArray::Clone(const MyArray& a) {
	int* _arr = new int[size = a.size];
	for (ushort i(0); i < size; ++i)
		_arr[i] = a.arr[i];
	arr = _arr;
}


void MyArray::Copy(const MyArray& a) {
	if (arr == nullptr || !size) {
		Clone(a);
		return;
	}
	if (size == a.size) {
		for (ushort i(0); i < size; ++i)
			arr[i] = a.arr[i];
		return;
	}
	Erase();
	Clone(a);
}


/////////////////////////////////////////////////////////////////////////////////////////////////


int* _create(int& n) {
	vector<int> v;
	cout << "введите массив(ctr+z для прекращения ввода):\n";
	while (true) {
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
	int* arr = new int[n = v.size()];
	ushort j(0);
	for (auto i : v)
		arr[j++] = i;
	return arr;
}


MyArray MyFunction(int* arr, int& n) {
	int newN = sort2(arr, n); 
	MyArray temp(arr, n);
	temp.SetSize(n = newN);
	return temp;
}


int sort_(int* &arr1, int n) {
	int* arr2 = new int[n];
	int* arr3 = new int[n];
	for (ushort i(0); i < n; ++i)
		arr2[i] = 1;
	for (ushort i(0); i < n - 1; ++i) {
		if (arr2[i] == 0)
			continue;
		for (ushort j = i + 1; j < n; ++j)
			if (arr1[i] == arr1[j]) {
				arr2[j] = 0;
				arr2[i]++;
			}
	}
	int count = 0;
	while (true) {
		int maxCount = 0, k = 0;
		for (ushort i(0); i < n; ++i)
			if (arr2[i] > maxCount) {
				maxCount = arr2[i];
				k = i;
			}
		if (maxCount == 0)
			break;
		arr3[count] = arr1[k];
		count++;
		arr2[k] = 0;
	}
	for (ushort i(0); i < count; ++i)
		arr1[i] = arr3[i];
	delete[] arr2;
	delete[] arr3;
	return count;
}