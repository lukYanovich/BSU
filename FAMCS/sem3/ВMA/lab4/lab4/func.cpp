#include "resources.h"

void print(matrix<double> A, ofstream& fout) {
	if (!fout.good())
		throw exception("выходной файл не открыт");
	for (size_t i(0); i < A.size1(); i++) {
		for (size_t j(0); j < A.size2(); j++)
			fout << A(i, j) << separator;
		fout << endl;
	}
}


void printf(matrix<double> A, ofstream& fout) {
	fout << std::fixed << std::setprecision(13);
	print(A, fout);
	fout.unsetf(std::ios::fixed);
}


void printf(matrix<double> A, ofstream& fout, const size_t _long) {
	fout << std::fixed << std::setprecision(_long);
	print(A, fout);
	fout.unsetf(std::ios::fixed);
}


void print(vector<double> v, ofstream& fout) {
	if (!fout.good())
		throw exception("выходной файл не открыт");
	for (size_t i(0); i < v.size(); i++)
		fout << v(i) << endl;
}


void printf(vector<double> v, ofstream& fout) {
	fout << std::fixed << std::setprecision(13);
	print(v, fout);
	fout.unsetf(std::ios::fixed);
}


matrix<double> create(const int n, ifstream& fin) {
	if (!fin.good())
		throw exception("входной файл не открыт");
	matrix<double> A(n, n);
	for (size_t i(0); i < A.size1(); i++)
		for (size_t j(0); j < A.size2(); j++)
			fin >> A(i, j);
	return A;
}
