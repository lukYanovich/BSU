#include <iostream>
#include <fstream>
#include <math.h>
#include <exception>
#include <iomanip>
using namespace std;

ofstream fout("output.csv");
ifstream fin("input.txt");
const int n = 10; //размерность квадратной матрицы А
const char* separator = ";";

void printMatrix(double**);
void printMatrixA(double**);
void _printMatrix(double**);
void printMatrix(double*);
void _printMatrix(double*);
void readFromFile(double**&, double*&);
void pryamoyHod(double**, double*, int&);
void obratnyiyHod(double**, double*, double*&);
double determinationOfMatrix(double**);
double** inverseMatrix(double**);
void multiplication(double**, double**);
double* multiplication(double**, double*);
double normaOfMatrix(double**);
void cleaningResources(double**&, double**&, double*&, double*&, double*&);


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		if (!fout)
			throw exception("выходной файл не создан.");
		if (!fin)
			throw exception("входной файл не отрыт.");
		double **matrixA, **inverseMatrixA;
		double *x, *f, *x1;
		readFromFile(matrixA, x);
		fin.close();
		f = multiplication(matrixA, x);
		int counterOfChanges = 1;

		fout << "матрица А:" << endl;
		printMatrixA(matrixA); fout << endl;

		fout << "вектор х(тр):" << endl;
		_printMatrix(x); fout << endl << endl;

		fout << "вектор f(тр):" << endl;
		printMatrix(f); fout << endl << endl;

		//ходы Гаусса

		pryamoyHod(matrixA, f, counterOfChanges);
		fout << "матрица А после прямого хода Гаусса:" << endl;
		printMatrix(matrixA); fout << endl << endl;

		obratnyiyHod(matrixA, f, x1);
		fout << "вектор х1(тр):" << endl;
		printMatrix(x1); fout << endl << endl;

		fout << fixed << setprecision(15) << "определитель A:" << endl
			<< (double)counterOfChanges*determinationOfMatrix(matrixA) << endl << endl;

		inverseMatrixA = inverseMatrix(matrixA);
		fout << "обратная матрица:" << endl;
		printMatrix(inverseMatrixA); fout << endl << endl;

		multiplication(matrixA, inverseMatrixA); //принт внутри, хоть и некрасиво

		fout << fixed << setprecision(15) << "норма А:" << endl << normaOfMatrix(matrixA) << endl;
		fout << fixed << setprecision(15) << "\nнорма A^-1:" << endl << normaOfMatrix(inverseMatrixA) << endl << endl;

		fout << fixed << setprecision(15) << "число обусловленности:" << endl
			<< normaOfMatrix(matrixA)*normaOfMatrix(inverseMatrixA) << endl;
		fout.close();

		cleaningResources(matrixA, inverseMatrixA, x, f, x1);
	}
	catch (exception& e) { cerr << e.what() << endl; }
	return 0;
}

void _printMatrix(double** arr) {
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			fout << arr[i][j] << separator;
		fout << endl;
	}
}

void printMatrix(double** arr) {
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			fout << fixed << setprecision(13) << arr[i][j] << separator;
		fout << endl;
	}
}

void printMatrixA(double** arr) {
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			fout << arr[i][j] << separator;
		fout << endl;
	}
}

void printMatrix(double* arr) {
	for (int i(0); i < n; ++i)
		fout << arr[i] << separator;
}

void _printMatrix(double* arr) {
	for (int i(0); i < n; ++i)
		fout << arr[i] << separator;
}

void readFromFile(double** &matrix, double* &x) {
	matrix = new double*[n];
	for (int i(0); i < n; ++i)
		matrix[i] = new double[n];
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			fin >> matrix[i][j];
	x = new double[n];
	for (int i(0); i < n; ++i)
		fin >> x[i];
}

void pryamoyHod(double** matrixA, double* f, int &counterOfChanges) {
	for (int k(0); k < n - 1; ++k) {
		int iMax = k;
		for (int i = k + 1; i < n; ++i)
			if (fabs(matrixA[iMax][k]) < fabs(matrixA[i][k]))
				iMax = i;
		if (iMax != k) {
			swap(matrixA[iMax], matrixA[k]);
			swap(f[iMax], f[k]);
			counterOfChanges *= -1;
		}
		for (int i = k + 1; i < n; ++i) {
			double temp = (double)matrixA[i][k] / matrixA[k][k];
			matrixA[i][k] = 0;
			f[i] = f[i] - temp*f[k];
			if (temp)
				for (int j = k + 1; j < n; ++j)
					matrixA[i][j] -= temp*matrixA[k][j];
		}
	}
}

void obratnyiyHod(double** matrixA, double* f, double* &x) {
	x = new double[n];
	x[n - 1] = (double)f[n - 1] / matrixA[n - 1][n - 1];
	//на 1 меньше коэфф(чем в теории) из-за нумерации массива с 0 элемента
	for (int i = n - 2; i >= 0; --i) {
		double temp = 0;
		for (int j = i + 1; j < n; ++j)
			temp += matrixA[i][j] * x[j];
		x[i] = (double)(f[i] - temp) / matrixA[i][i];
	}
}

double determinationOfMatrix(double** matrixA) {
	double temp = 1.0;
	for (int i(0); i < n; ++i)
		temp *= matrixA[i][i];
	return temp;
}

double** inverseMatrix(double** matrix) {
	double** inverseMatrix = new double*[n];
	for (int i(0); i < n; ++i)
		inverseMatrix[i] = new double[n];
	double* temp1 = new double[n];
	double* temp2 = new double[n];
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			temp2[j] = 0;
		temp2[i] = 1.0;
		obratnyiyHod(matrix, temp2, temp1);
		for (int j(0); j < n; ++j)
			inverseMatrix[j][i] = temp1[j];
	}
	delete[] temp1;
	delete[] temp2;
	temp1 = temp2 = nullptr;
	return inverseMatrix;
}

void multiplication(double** m1, double** m2) {
	double** result = new double*[n];
	for (int i(0); i < n; ++i)
		result[i] = new double[n];
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			result[i][j] = 0;
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			for (int k(0); k < n; ++k)
				result[i][j] += m1[i][k] * m2[k][j];
	fout << "A*A^-1(должна быть единичная):" << endl;
	printMatrix(result); fout << endl << endl;
	for (int i(0); i < n; ++i)
		delete[] result[i];
	delete[] result;
	result = nullptr;
}

double* multiplication(double** A, double* x) {
	double* f = new double[n];
	for (int i(0); i < n; ++i)
		f[i] = 0;
	for (int i(0); i < n; ++i)
		for (int k(0); k < n; ++k)
			f[i] += A[i][k] * x[k];
	return f;
}

double normaOfMatrix(double** matrix) {
	double sum = 0;
	for (int i(0); i < n; ++i) {
		double temp = 0;
		for (int j(0); j < n; ++j)
			temp += fabs(matrix[i][j]);
		if (temp > sum)
			sum = temp;
	}
	return sum;
}

void cleaningResources(double** &a, double** &b, double* &c, double* &d, double* &e) {
	for (int i(0); i < n; ++i) {
		delete[] a[i];
		delete[] b[i];
	}
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] e;
	a = b = nullptr;
	c = d = e = nullptr;
}
