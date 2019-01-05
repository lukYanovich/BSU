#include "resources.h"

int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	const int n = 10;
	const double eps = pow(10, -5);
	try {
		ifstream fin("input.txt");
		matrix<double> A(create(n, fin));
		fin.close();

		ofstream fout("output.csv", ios_base::trunc);
		fout << "матрица А:" << endl;
		print(A, fout);

		fout << "\nматрица собственных значений:" << endl;
		printf(IMV(A, eps), fout);

		pair<double, vector<double>> maxL(ISM(A, eps));
		fout << "\nмаксимальное собственное значение:\n" << maxL.first
			<< "\n\nсобственный вектор для него:" << endl;
		printf(maxL.second, fout);

		fout << "\nA*y:\n";
		printf(prod(A, maxL.second), fout);
		fout << "\nл*y:\n";
		printf(maxL.first*maxL.second, fout);
		fout.close();
	}
	catch (exception& e) { cerr << e.what() << endl; }
	return 0;
}


template<typename T>
int sign(T val) {
	if (val > 0)
		return 1;
	else if (val == 0)
		return 0;
	return -1;
}


pair<size_t, size_t> findMaxNotDiagElement(matrix<double> A) {
	size_t k = 0, l = 0;
	double max = INT_MIN;
	for (size_t i(0); i < A.size1(); i++)
		for (size_t j(i + 1); j < A.size2(); j++)
			if (fabs(A(i, j)) > max) {
				k = i;
				l = j;
				max = fabs(A(i, j));
			}
	return pair<size_t, size_t>(k, l);
}


bool checkMatrix(matrix<double> A, const double eps) {
	for (size_t i(0); i < A.size1(); i++)
		for (size_t j(0); j < A.size2(); j++)
			if (i == j)
				continue;
			else if (fabs(A(i, j)) > eps)
				return false;
	return true;
}


matrix<double> IMV(matrix<double> A, const double eps) {
	while (!checkMatrix(A, eps)) {
		pair<size_t, size_t> temp(findMaxNotDiagElement(A));
		size_t k = temp.first;
		size_t l = temp.second;
		
		double mju = 2 * A(k, l) / (A(k, k) - A(l, l));
		double alpha = sqrt(0.5*(1 + 1 / sqrt(1 + mju*mju)));	//cos
		double betta = sign(mju)*sqrt(0.5*(1 - 1 / sqrt(1 + mju*mju)));		//sin

		matrix<double> B(A.size1(), A.size2());
		for (size_t i(0); i < B.size1(); i++) {
			B(i, k) = A(i, k)*alpha + A(i, l)*betta;;
			B(i, l) = -A(i, k)*betta + A(i, l)*alpha;
			for (size_t j(0); j < B.size2(); j++)
				if (j != k && j != l)
					B(i, j) = A(i, j);
		}

		matrix<double> C(A.size1(), A.size2());
		for (size_t i(0); i < C.size1(); i++) {
			C(k, i) = B(k, i)*alpha + B(l, i)*betta;
			C(l, i) = -B(k, i)*betta + B(l, i)*alpha;
			for (size_t j(0); j < C.size2(); j++)
				if (j != k && j != l)
					C(j, i) = B(j, i);
		}
		A = C;
	}
	return A;
}


pair<double, vector<double>> ISM(matrix<double> A, const double eps) {
	vector<double> y(A.size1(), 1);
	double lambda = 0;
	while (true) {
		vector<double> yNext(prod(A, y));
		double lambdaNext = inner_prod(yNext, y) / inner_prod(y, y);
		if (fabs(lambdaNext - lambda) <= eps)
			break;
		lambda = lambdaNext;
		y = yNext;
		y /= norm_inf(y);
	}
	return pair<double, vector<double>>(lambda, y / norm_inf(y));
}
