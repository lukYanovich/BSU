#include "resources.h"

void print(matrix<double> A, ofstream& fout) {
	if (!fout)
		throw exception("выходной файл не открыт");
	for (size_t i(0); i < A.size1(); i++) {
		for (size_t j(0); j < A.size2(); j++)
			fout << A(i, j) << separator;
		fout << endl;
	}
}


void print(vector<double> v, ofstream& fout) {
	if (!fout)
		throw exception("выходной файл не открыт");
	for (size_t i(0); i < v.size(); i++)
		fout << v(i) << endl;
}


void printf(vector<double> v, ofstream& fout) {
	if (!fout)
		throw exception("выходной файл не открыт");
	for (size_t i(0); i < v.size(); i++)
		fout << std::fixed << std::setprecision(13) << v(i) << endl;
	fout.unsetf(std::ios::fixed);
}


pair<matrix<double>, vector<double>> create(const int n, ifstream& fin) {
	if (!fin)
		throw exception("входной файл не открыт");
	matrix<double> A(n, n);
	for (size_t i(0); i < A.size1(); i++)
		for (size_t j(0); j < A.size2(); j++)
			fin >> A(i, j);
	vector<double> v(n);
	for (size_t i(0); i < v.size(); i++)
		fin >> v(i);
	return pair<matrix<double>, vector<double>>(A, v);
}
