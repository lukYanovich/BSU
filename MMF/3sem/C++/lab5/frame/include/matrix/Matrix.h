#pragma once
#include <cstddef>
#include <iostream>


class Matrix {
public:
    virtual ~Matrix();

    Matrix &operator=(const Matrix &o);

    virtual size_t getN() const noexcept {}

    virtual size_t getM() const noexcept {}

    virtual void setN(size_t n) noexcept{}

    virtual void setM(size_t m) noexcept{}

    size_t numberOfUnits() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &o);

    friend std::istream &operator>>(std::istream &is, Matrix &o);


protected:
    void erase() noexcept;

    void copy(const Matrix &o) noexcept;

    virtual void create(const size_t n, const size_t m) {}

    virtual std::istream &read(std::istream &is)=0;

    virtual int **&getArr() noexcept {}

    virtual int **getArr() const noexcept {}
};
