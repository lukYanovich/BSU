#include "ex.h"

void _read(word& a, const char* _filename){
	ifstream fin(_filename);
	if (!fin)
		throw ex(_filename, fin);
	while (fin.good()){
		string temp;
		if (!(fin >> temp))
			throw ex(fin, _filename);
		bool flag = false;
		for (auto& i : a)
			if (_camp(i.first, temp)){
				i.second++;
				flag = true;
			}
		if (!flag)
			a.insert(par(temp, 1));
		temp.clear();
	}
	fin.close();
}

bool _camp(const string& a, const string& b){
	const unsigned short dif = 32;	//разница кодов большой и маленькой букв в ANCI
	bool flag = true;
	for (unsigned short i(0); i != a.length() || i != b.length(); ++i)
		if (a[i] != b[i] && a[i] != b[i] + dif && a[i] + dif != b[i]){
			flag = false;
			break;
		}
	if (flag)
		return true;
	return false;
}