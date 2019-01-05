#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <exception>
#include <iomanip>
#include <boost\numeric\ublas\matrix.hpp>
#include <boost\numeric\ublas\vector.hpp>

std::ofstream fout("output.txt");
std::ifstream fin("input.txt");
const int N = 10; //умное число
const int size = N + 1;
const char* separator = "\t\t";


void readFromFile(boost::numeric::ublas::matrix<double>&, boost::numeric::ublas::vector<double>&);
void printMatrix(boost::numeric::ublas::matrix<double>);
void printVector(boost::numeric::ublas::vector<double>);
void printfVector(boost::numeric::ublas::vector<double>);
boost::numeric::ublas::vector<double> pryamoyAndObratnyiyHod(boost::numeric::ublas::matrix<double>,
	boost::numeric::ublas::vector<double>&);


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		if (!fout)
			throw std::exception("выходной файл не создан.");
		else if (!fin)
			throw std::exception("входной файл не отрыт.");
		boost::numeric::ublas::matrix<double> A(size, size);
		boost::numeric::ublas::vector<double> x(size), f(size);
		readFromFile(A, x);
		fout << "матрица А:\n";
		printMatrix(A);
		fout << "\nвектор х(транспонированный):\n";
		printVector(x);
		fout << "\n\nвектор f(транспонированный):\n";
		printfVector(f = boost::numeric::ublas::prod(A, x));
		fout << "\n\nприближённое значение x1:\n";
		printfVector(pryamoyAndObratnyiyHod(A, f));
	}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	return 0;
}


void readFromFile(boost::numeric::ublas::matrix<double>& A, boost::numeric::ublas::vector<double>& x) {
	for (int i(0); i < size; ++i)
		for (int j(0); j < size; ++j)
			fin >> A(i, j);
	for (int i(0); i < size; ++i)
		fin >> x(i);
	//закроем файл тут, он глобальный для удобства. ну и чтобы закрытие не маячило в main'е
	fin.close();
}


void printMatrix(boost::numeric::ublas::matrix<double> A) {
	for (int i(0); i < size; ++i) {
		for (int j(0); j < size; ++j)
			fout << std::fixed << std::setprecision(3) << A(i, j) << separator;
		fout << std::endl;
	}
}


void printVector(boost::numeric::ublas::vector<double> v) {
	fout.unsetf(std::ios::fixed);
	for (int i(0); i < size; ++i)
		fout << v(i) << separator;
}


void printfVector(boost::numeric::ublas::vector<double> v) {
	for (int i(0); i < size; ++i)
		fout << std::fixed << std::setprecision(16) << v(i) << separator;
}


boost::numeric::ublas::vector<double> pryamoyAndObratnyiyHod(boost::numeric::ublas::matrix<double> A,
	boost::numeric::ublas::vector<double>& f) {
	boost::numeric::ublas::vector<double> a(size), b(size), c(size), alpha(N), betta(N);
	b(0) = -A(0, 1);
	a(N) = -A(N, N - 1);
	c(0) = A(0, 0);
	for (int i(1); i < N; ++i) {
		a(i) = -A(i, i - 1);
		b(i) = -A(i, i + 1);
		c(i) = A(i, i);
	}
	//прямой ход
	alpha(0) = b(0) / c(0);
	betta(0) = f(0) / c(0);
	for (int i(1); i < N; ++i) {
		alpha(i) = b(i) / (c(i) - a(i)*alpha(i - 1));
		betta(i) = (f(i) + a(i)*betta(i - 1)) / (c(i) - a(i)*alpha(i-1));
	}
	//обратный ход
	boost::numeric::ublas::vector<double> x(size);	
	x(N) = (f(N) - a(N)*betta(N - 1)) / (c(N) + alpha(N - 1)*a(N));
	for (int i(N - 1); i >= 0; --i)
		x(i) = alpha(i)*x(i + 1) + betta(i);
	return x;
}


//P(0) = -A(0, 1) / A(0, 0);
//Q(0) = f(0) / A(0, 0);
//for (int i(1); i < N; ++i) {
//	P(i) = -A(i, i + 1) / (A(i, i) + A(i, i - 1)*P(i - 1));
//	Q(i) = (f(i) - A(i, i - 1)*Q(i - 1)) / (A(i, i) + A(i, i - 1)*P(i - 1));
//}


//x(N) = (f(N) - A(N, N - 1)*Q(N - 1)) / (A(N, N) + A(N, N - 1)*P(N - 1));	
//for (int i(N - 1); i >= 0; --i)
//	x(i) = P(i)*x(i + 1) + Q(i);