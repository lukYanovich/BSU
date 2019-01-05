#pragma once
#include "NumericMatrix.h"


class BoolMatrix : public NumericMatrix {
public:
    BoolMatrix(const size_t n, const size_t m);

    BoolMatrix(const size_t n);

    BoolMatrix();

    virtual ~BoolMatrix();

    BoolMatrix operator&(const BoolMatrix &o) const;

    BoolMatrix operator|(const BoolMatrix &o) const;

    BoolMatrix operator^(const BoolMatrix &o) const;

    BoolMatrix operator*(const BoolMatrix &o) const;


protected:
    std::istream &read(std::istream &is);

private:
    void check(const BoolMatrix &o, const std::string &nameOfMethod) const;
};
