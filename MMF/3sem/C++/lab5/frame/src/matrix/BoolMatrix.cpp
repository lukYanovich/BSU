#include "../../include/matrix/BoolMatrix.h"


BoolMatrix::BoolMatrix(const size_t n, const size_t m) {
	create(n, m);
}

BoolMatrix::BoolMatrix() {}

BoolMatrix::BoolMatrix(const size_t n) {
	BoolMatrix(n, n);
}

BoolMatrix::~BoolMatrix() {
	erase();
}

void BoolMatrix::check(const BoolMatrix &o, const std::string &nameOfMethod) const {
    if (n != o.n || m != o.m) {
        std::string message = "sizes of matrix's don't match in method \'";
        message += nameOfMethod;
        message += "()\'";
        throw std::invalid_argument(message);
    }
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix &o) const {
	check(o, "operator&");
	BoolMatrix temp(n, m);
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			temp.arr[i][j] = arr[i][j] && o.arr[i][j];
	return temp;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix &o) const {
	check(o, "operator|");
	BoolMatrix temp(n, m);
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			temp.arr[i][j] = arr[i][j] || o.arr[i][j];
	return temp;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix &o) const {
	check(o, "operator^");
	BoolMatrix temp(n, m);
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			temp.arr[i][j] = arr[i][j] ^ o.arr[i][j];
	return temp;
}

BoolMatrix BoolMatrix::operator*(const BoolMatrix &o) const {
	if (m != o.n)
		throw std::invalid_argument("multiplication is impossible");
	BoolMatrix temp(n, o.m);
	for (size_t i(0); i < n; ++i)
		for (size_t j(0); j < o.m; ++j)
			for (size_t k(0); k < m; ++k)
				temp.arr[i][j] |= arr[i][k] && o.arr[k][j];
	return temp;
}

std::istream& BoolMatrix::read(std::istream &is) {
	std::vector<std::vector<std::string>> arrOfLines = MyAux::read(is);
	create(arrOfLines.size(), arrOfLines[0].size());
	for (size_t i(0); i < n; i++)
		for (size_t j(0); j < m; j++)
			arr[i][j] = MyAux::toBool(arrOfLines[i][j]);
	return is;
}