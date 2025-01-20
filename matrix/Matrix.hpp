#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../array/DynamicArray.h"

template <typename T>
class Matrix {
public:
    DynamicArray<DynamicArray<T>> elems;

    explicit Matrix(size_t rows, size_t cols) : elems(rows) {
        for (size_t i = 0; i < rows; ++i) {
            elems[i] = DynamicArray<T>(cols, T(0));
        }
    }

    Matrix operator+(const Matrix& other) const {
        size_t rows = elems.size();
        size_t cols = elems[0].size();
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.elems[i][j] = elems[i][j] + other.elems[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        size_t rows = elems.size();
        size_t cols = other.elems[0].size();
        size_t inner = elems[0].size();
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.elems[i][j] = T(0);
                for (size_t k = 0; k < inner; ++k) {
                    result.elems[i][j] += elems[i][k] * other.elems[k][j];
                }
            }
        }
        return result;
    }
    Matrix operator-() const {
        size_t rows = elems.size();
        size_t cols = elems[0].size();
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.elems[i][j] = -elems[i][j];
            }
        }
        return result;
    }

    static Matrix zero(size_t rows, size_t cols) {
        return Matrix(rows, cols);
    }

    static Matrix one(size_t size) {
        Matrix m(size, size);
        for (size_t i = 0; i < size; ++i) {
            m.elems[i][i] = T(1);
        }
        return m;
    }
};

/*
#include <concepts>
#include <functional>
#include <vector>
#include <iostream>

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> elems;

    explicit Matrix(std::vector<std::vector<T>> elems) : elems(std::move(elems)) {}

    Matrix operator+(const Matrix& other) const {
        size_t rows = elems.size(),
        cols = elems[0].size();
        std::vector<std::vector<T>> result(rows, std::vector<T>(cols, T(0)));
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result[i][j] = elems[i][j] + other.elems[i][j];
        return Matrix(result);
    }

    Matrix operator*(const Matrix& other) const {
        size_t rows = elems.size(),
        cols = other.elems[0].size(),
        inner = elems[0].size();
        if (inner == other.elems.size()) {
            std::vector<std::vector<T>> result(rows, std::vector<T>(cols, T(0)));
            for (size_t i = 0; i < rows; ++i)
                for (size_t j = 0; j < cols; ++j)
                    for (size_t k = 0; k < inner; ++k)
                        result[i][j] += elems[i][k] * other.elems[k][j];
            return Matrix(result);
        }
    }

    Matrix operator-() const {
        size_t rows = elems.size(),
        cols = elems[0].size();
        std::vector<std::vector<T>> negElems(rows, std::vector<T>(cols, T(0)));
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                negElems[i][j] = -elems[i][j];
        return Matrix(negElems);
    }

    static Matrix zero() { return Matrix({{0, 0}, {0, 0}}); }
    static Matrix one() { return Matrix({{1, 0}, {0, 1}}); }
};

*/
#endif // MATRIX_HPP