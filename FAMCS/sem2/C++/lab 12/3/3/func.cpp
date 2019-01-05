#include "ex.h"

void _show(const _set a){
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
}

void _read(_set& a, const char* _filename){
	ifstream fin(_filename);
	if (!fin)
		throw ex(_filename, fin);
	while (fin.good()){
		int temp;
		if (!(fin >> temp))
			throw ex(fin, _filename);
		a.insert(temp);
	}
	fin.close();
	_show(a);
}

void _search(const _set a, const int n){
	bool flag = false;
	//решето Ёратосфена
	bool* B = new bool[n + 1];
	int i, p;
	for (p = 2; p <= n; p++) B[p] = true;
	p = 2;
	while (p*p <= n)
	{
		i = p*p;
		if (B[p])
			while (i <= n)
			{
				B[i] = false;
				i = i + p;
			}
		p = p + 1;
	}
	vector<int> v;
	for (auto k = a.begin(); k != a.end(); ++k)
		for (p = 2; p <= n; p++)
			if (B[p] == true && p == *k){
				flag = true;
				v.push_back(p);
			}
	delete[] B;
	B = nullptr;
	if (!flag)
		throw ex(n);
	cout << "простые числа: ";
	for (auto k : v)
		cout << k << ' ';
	cout << endl;
}