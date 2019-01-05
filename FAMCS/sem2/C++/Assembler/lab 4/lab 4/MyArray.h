#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned short ushort;

extern "C" int __cdecl sort1(int*, int);
extern "C" int __stdcall sort2(int*, int);
extern "C" int __fastcall sort3(int*, int);

class MyArray{
public:
	MyArray() { arr = nullptr; size = 0; }
	MyArray(const int*, const int);
	MyArray(const MyArray& a) { Clone(a); }
	~MyArray() { Erase(); }

	MyArray& operator=(const MyArray&);
	friend ostream& operator<<(ostream&, const MyArray);

	void SetSize(const int);
	int GetSize() const { return size; }
	int* GetArr() const { return arr; }
private:
	int* arr;
	int size;

	void Erase();
	void Copy(const MyArray&);
	void Clone(const MyArray&);
};


int* _create(int&);
MyArray MyFunction(int*, int&);

int sort_(int*&, int);