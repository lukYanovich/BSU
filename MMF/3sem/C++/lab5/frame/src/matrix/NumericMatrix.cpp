#include "../../include/matrix/NumericMatrix.h"


NumericMatrix::NumericMatrix(const size_t n,const size_t m) {
    create(n, m);
}

NumericMatrix::NumericMatrix(const size_t n) {
    NumericMatrix(n, n);
}

NumericMatrix::NumericMatrix() {
	arr = nullptr;
	n = m = 0;
}

NumericMatrix::NumericMatrix(int** arr, const size_t n, const size_t m) {
	create(n, m);
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			this->arr[i][j] = arr[i][j];
}

NumericMatrix::NumericMatrix(int** arr, const size_t n) {
	NumericMatrix(arr, n, n);
}

NumericMatrix::NumericMatrix(const NumericMatrix& o) {
	create(n, m);
	copy(o);
}

NumericMatrix::~NumericMatrix() {
	erase();
}

int**& NumericMatrix::getArr() noexcept {
    return arr;
}

int** NumericMatrix::getArr() const noexcept {
    return arr;
}

size_t NumericMatrix::getN() const noexcept {
    return n;
}

size_t NumericMatrix::getM() const  noexcept {
    return m;
}

void NumericMatrix::setN(size_t n) noexcept {
    this->n = n;
}

void NumericMatrix::setM(size_t m) noexcept {
    this->m = m;
}

NumericMatrix NumericMatrix::alphaCanonical() const {
    NumericMatrix temp(n, m);
    temp.copy(*this);
    mySort(temp.arr, temp.n, temp.m);
    deleteEqualLines(temp.arr, temp.n, searchEqualLines(temp.arr, temp.n, temp.m));
    return temp;
}

void NumericMatrix::create(const size_t n, const size_t m) {
    this->n = n;
    this->m = m;
    arr = new int *[n];
    for (size_t i(0); i < n; i++)
        arr[i] = new int[m];
    for (size_t i(0); i < n; i++)
        for (size_t j(0); j < m; j++)
            arr[i][j] = 0;
}

std::istream& NumericMatrix::read(std::istream& is) {
	std::vector<std::vector<std::string>> arrOfLines = MyAux::read(is);
	create(arrOfLines.size(), arrOfLines[0].size());
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			arr[i][j] = MyAux::toInteger(arrOfLines[i][j]);
	return is;
}


//utility

void NumericMatrix::mySort(int** arr, const size_t n, const size_t m) {
    if (!n || !m)
        throw std::invalid_argument("don't sort");
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (size_t i(0); i < n; i++)
        for (size_t j(0); j < m; j++)
            matrix[i][j] = arr[i][j];
    std::sort(matrix.begin(), matrix.end());
    for (size_t i(0); i < n; i++)
        for (size_t j(0); j < m; j++)
            arr[i][j] = matrix[i][j];
}

size_t NumericMatrix::searchEqualLines(int **arr, const size_t n, const size_t m) noexcept {
    size_t countOfRowsDeleted = 0;
    for (size_t i(0); i < n - countOfRowsDeleted - 1; i++)
        for (size_t j(0); arr[i][j] == arr[i + 1][j]; j++)
            if (j == m - 1) {
                for (size_t k(i + 1); k < n - countOfRowsDeleted - 1; k++)
                    std::swap(arr[k], arr[k + 1]);
                countOfRowsDeleted++;
                break;
            }
    return countOfRowsDeleted;
}

void NumericMatrix::deleteEqualLines(int **arr, size_t &n, const size_t countOfRowsDeleted) noexcept {
    for (size_t i(n - countOfRowsDeleted); i < n; i++)
        delete[] arr[i];
    n -= countOfRowsDeleted;
}