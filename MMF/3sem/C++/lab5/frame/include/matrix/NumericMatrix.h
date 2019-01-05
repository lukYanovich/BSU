#pragma once
#include "Matrix.h"
#include "../MyAux.h"
#include <algorithm>
#include <string>

class NumericMatrix : public Matrix {
protected:
    size_t n, m;
    int **arr;


public:
    NumericMatrix(const size_t n, const size_t m);

    NumericMatrix(const size_t n);

    NumericMatrix();

    NumericMatrix(int **arr, const size_t n, const size_t m);

    NumericMatrix(int **arr, const size_t n);

    NumericMatrix(const NumericMatrix &o);

    virtual ~NumericMatrix();

    size_t getN() const noexcept;

    size_t getM() const noexcept;

    void setN(size_t n) noexcept;

    void setM(size_t m) noexcept;

    NumericMatrix alphaCanonical() const;


protected:
    void create(const size_t n, const size_t m);

    int **&getArr() noexcept;

    int **getArr() const noexcept;

    std::istream &read(std::istream &is);


private:
    static void mySort(int **arr, const size_t n, const size_t m);

    static size_t searchEqualLines(int **arr, const size_t n, const size_t m) noexcept;

    static void deleteEqualLines(int **arr, size_t &n, const size_t countOfRowsDeleted) noexcept;
};
