#include "../../include/matrix/Matrix.h"
#include <stdexcept>


Matrix::~Matrix() {
	//erase();
}

Matrix& Matrix::operator=(const Matrix& o) {
	if (this != &o) {
		if (this->getN() == o.getN() && this->getM() == o.getM())
			copy(o);
		else {
			erase();
			create(this->getN(), this->getM());
			copy(o);
		}
	}
	return *this;
}

size_t Matrix::numberOfUnits() const {
    if(getArr()== nullptr)
        throw std::invalid_argument("");
	size_t count = 0;
	for (size_t i(0); i < getN(); i++)
		for (size_t j(0); j < getM(); j++)
			if (getArr()[i][j] == 1)
				count++;
	return count;
}

std::ostream& operator<<(std::ostream &os, const Matrix &o) {
	for (size_t i(0); i < o.getN() - 1; i++) {
		for (size_t j(0); j < o.getM(); j++)
			os << o.getArr()[i][j] << ' ';
		os << std::endl;
	}
	for (size_t i(0); i < o.getM(); i++)
		os << o.getArr()[o.getN() - 1][i] << ' ';
	return os;
}

std::istream& operator>>(std::istream &is, Matrix &o) {
    return o.read(is);
}

void Matrix::erase() noexcept{
    if(getArr()!= nullptr) {
        for (size_t i(0); i < getN(); i++)
            delete[] getArr()[i];
        delete[] getArr();
        getArr() = nullptr;
        setN(0);
        setM(0);
    }
}

void Matrix::copy(const Matrix& o) noexcept{
	for (size_t i(0); i < getN(); i++)
		for (size_t j(0); j < getM(); j++)
			getArr()[i][j] = o.getArr()[i][j];
}
