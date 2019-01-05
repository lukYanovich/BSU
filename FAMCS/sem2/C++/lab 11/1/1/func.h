#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iterator>
typedef unsigned short ushort;
using namespace std;

void _enter(vector<int> &v){
	cout << "введите значения элементов(ctrl+Z для прекращения):\n";
	while (true){
		int a;
		cin >> a;
		if (cin.good())
			v.push_back(a);
		else
			break;
	}
}

void _show(const vector<int>& v){
	for (int i : v)
		cout << i << ' ';
	cout << endl;
}


int f1(const vector<int>& v){
	int temp = 0;
	cout << "сумма чисел: ";
	for (ushort i(0); i < v.size(); ++i)
		temp += v[i];
	cout << temp << endl;
	return temp;
}

void f2(const vector<int>& v){ 
	cout << "количество элементов: " << v.size() << endl; 
}

void f3(const vector<int>& v){
	ushort count = 0;
	int temp = 5;	//число, с которым сравниваем элементы вектора
	for (int i : v)
		if (i == temp)
			count++;
	cout << "количество чисел \"" << temp << "\" в векторе: " << count << endl;
}

void f4(const vector<int>& v){
	ushort count = 0;
	int temp = 10;	//число, с которым идёт сравнение
	for (int i : v)
		if (i > temp)
			count++;
	cout << "количество чисел, больших \"" << temp << "\": " << count << endl;
}

void f5(const vector<int>& u, const int a){
	vector<int> v;
	v.assign(u.begin(), u.end());
		for (int& i : v)
		if (!i)
			i = a / v.size();
	cout << "после замены \"0\" на среднее арифметическое:" << endl;
	_show(v);
}

void f6(const vector<int>& u){
	vector<int> v;
	v.assign(u.begin(), u.end());
	int sum = 0;
	ushort a = 2, b = 4;		//диапазаон, из которого нужно брать числа из вектора
	cout << "после прибавления суммы из диапазона от \"" << a << "\" до \"" << b << "\":" << endl;
	if (a > u.size() || b > u.size())
		throw exception("выход за границы вектора.");
	for (auto i = v.begin() + a - 1; i < v.begin() + b - 1; ++i)
		sum += *i;
	for (int& i : v)
		i += sum;
	_show(v);
}

void f7(const vector<int>& u){
	vector<int> v;
	v.assign(u.begin(), u.end());
	int max = INT_MIN, min = INT_MAX;
	for (int i : v){
		if (i > max)
			max = i;
		if (i < min)
			min = i;
	}
	int diff = max - min;
	for (int& i : v){
		if (i % 2 == 0){
			if (i < 0){
				if (diff > 0)
					i = diff*-1;
				else
					i = diff;
			}
			else{
				if (diff > 0)
					i = diff;
				else
					i = diff*-1;
			}
		}
	}
	cout << "после замены чётных на разность max и min: " << endl;
	_show(v);
}

void f8(const vector<int>& v){
	vector<int> t;
	t.assign(v.begin(), v.end());
	for (ushort i(0); i < t.size() - 1; ++i)
		for (ushort j(i + 1); j < t.size(); ++j)
			if (abs(t[i]) == abs(t[j])){
				t.erase(t.begin() + j);
				j--;
			}
	cout << "после удаления одинаковых по молулю: " << endl;
	_show(t);
}