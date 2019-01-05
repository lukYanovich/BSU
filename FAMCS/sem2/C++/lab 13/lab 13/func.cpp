#include "ex.h"
const char* _fileout = "output.txt";
const char* separator = "///////////////////////////////////////////////////////////////";

void _read(_map& a, const char* _filename){
	ifstream fin(_filename);
	if (!fin)
		throw ex(_filename, fin);
	bool flag = false;
	while (fin.good()){
		string temp1, temp2;
		fin >> temp1 >> temp2;
		par buff;
		bool _flag = false;
		if (_check(temp1[0])){
			_flag = true;
			int _temp;
			fin >> _temp;
			buff.second.name = temp1 + " " + temp2;
			buff.first = buff.second.number = _temp;
			while (true){
				temp1.clear();
				fin >> temp1;
				if (temp1 == ";")
					break;
				flag = true;
				fin >> _temp;
				course tmp(temp1, _temp);
				buff.second.markList.push_back(tmp);
			}
		}
		if (_flag)
			a.insert(buff);
	}
	fin.close();
	if (!flag)
		throw ex(fin, _filename);
}

int toint(const string& a){
	const char* temp = a.c_str();
	return strtol(temp, 0, 0);
}

bool _check(const char a){
	if ((a >= 'A' && a <= 'Z') || (a >= 'А' && a <= 'Я'))
		return true;
	return false;
}

void f2(_map& a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	fout << "2. сортировка по номеру зачётки:" << endl;
	for (auto i : a){
		fout << "\nимя: " << i.second.name << "; номер зачётки: " << i.second.number << endl;
		for (auto j : i.second.markList)
			fout << "предмет: " << j.subject << ", отметка: " << j.mark << endl;
	}
	fout << endl << separator;
	fout.close();
}

void f3(const _map a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	fout << "\n\n3. средний балл каждого студента:\n" << endl;
	for (auto i : a){
		ushort k = 0;
		int sum = 0;
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j, ++k)
			sum += j->mark;
		fout << i.second.name << " средний балл: " << (double)sum / k << endl;
	}
	fout << endl << separator;
	fout.close();
}

void f4(_map& a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	fout << "\n\n4. список студентов по алфавиту(по среднему баллу):\n" << endl;
	vector<studData> v;
	for (auto i : a)
		v.push_back(i.second);
	sort(v.begin(), v.end(), [](studData _a, studData _b){
		if (_a.name < _b.name)
			return true;
		if (_a.name == _b.name){
			int k1 = 0, k2 = 0, sum1 = 0, sum2 = 0;
			for (auto i = _a.markList.begin(); i != _a.markList.end(); ++i, ++k1)
				sum1 += i->mark;
			for (auto i = _b.markList.begin(); i != _b.markList.end(); ++i, ++k2)
				sum2 += i->mark;
			if ((double)sum1 / k1 > (double)sum2 / k2)
				return true;
			}
		return false;
		}
	);
	ushort num = 1;
	for (auto i : v){
		ushort k = 0;
		int sum = 0;
		for (auto j = i.markList.begin(); j != i.markList.end(); ++j, ++k)
			sum += j->mark;
		fout << num++ << ": " << i.name << "; номер зачётки: " << i.number << " средний балл: " << (double)sum / k << endl;
	}
	fout << endl << separator;
	fout.close();
}

void f5(_map& a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	double _a = 5, _b = 8;	//границы среднего балла
	bool flag = false;
	fout << "\n\n5. список студентов со средним баллом от\"" << _a << "\" до \"" << _b << "\":\n" << endl;
	for (auto i : a){
		ushort k = 0;
		int sum = 0;
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j, ++k)
			sum += j->mark;
		if ((double)sum / k >= _a && (double)sum / k <= _b){
			flag = true;
			fout << i.second.name << "; средний балл: " << (double)sum / k << endl;
		}
	}
	if (!flag)
		fout << "таких студентов нет" << endl;
	fout << endl << separator;
	fout.close();
}

void f6(const _map a, const char* _subject){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	bool flag = false;
	fout << "\n\n6. список студентов, которые сдавали \"" << _subject << "\":\n" << endl;
	for (auto i : a)
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j)
			if (j->subject == _subject){
				flag = true;
				fout << i.second.name << "; номер зачётки: " << i.second.number << endl;
			}
	if (!flag)
		fout << "таких студентов нет" << endl;
	fout << endl << separator;
	fout.close();
}

void f7(const _map a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	vector<pair<string, int>> v;	//массив предметов и повторений
	fout << "\n\n7. сколько студентов сдавало каждый предмет:\n" << endl;
	for (auto i : a)
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j){
			bool flag = false;
			for (auto k : v)
				if (k.first == j->subject)
					flag = true;
			if (!flag){
				pair<string, int> temp(j->subject, 0);
				v.push_back(temp);
			}
		}
	for (auto i : a)
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j)
			for (auto& k : v)
				if (k.first == j->subject){
					k.second++;
					break;
				}
	for (auto i : v)
		fout << '\"' << i.first << "\" - " << i.second << endl;
	fout << endl << separator;
	fout.close();
}

void f8(_map& a){
	ofstream fout(_fileout, ios_base::app);
	if (!fout)
		throw ex(_fileout, fout);
	vector<pair<pair<string, int>, int>> v;	//массив предметов, повторений и сумма баллов
	fout << "\n\n8. предмет и средний балл по нему:\n" << endl;
	for (auto i : a)
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j){
			bool flag = false;
			for (auto k : v)
				if (k.first.first == j->subject)
					flag = true;
			if (!flag){
				pair<string, int> buff(j->subject, 0);
				pair<pair<string, int>, int> temp(buff, 0);
				v.push_back(temp);
			}
		}
	for (auto i : a)
		for (auto j = i.second.markList.begin(); j != i.second.markList.end(); ++j)
			for (auto& k : v)
				if (k.first.first == j->subject){
					k.first.second++;
					k.second += j->mark;
				}
	sort(v.begin(), v.end(), [](pair<pair<string, int>, int> _a, pair<pair<string, int>, int> _b){
		if ((double)_a.second / _a.first.second < (double)_b.second / _b.first.second)
			return true;
		return false;
		}
	);
	for (auto i : v)
		fout << '\"' << i.first.first << "\" - " << (double)i.second/i.first.second << endl;
	fout << endl << separator;
	fout.close();
}