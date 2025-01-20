#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP


#include "../array/DynamicArray.h"
template <typename T>
class Polynomial {
public:
    DynamicArray<T>coeff;
    Polynomial() = default;
    explicit Polynomial(const DynamicArray<T>& coeffs) : coeff(coeffs) {}

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = std::max (coeff.size(),other.coeff.size());
        DynamicArray<T> res(maxSize);
        for (size_t i= 0; i< maxSize; ++i) {
            res[i] = T(0);
        }
        for (size_t i = 0; i <coeff.size(); ++i)
            res[i] += coeff[i];
        for (size_t i= 0; i < other.coeff.size(); ++i)
          res[i] += other.coeff[i];
        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& other) const {
        size_t resultSize = coeff.size() + other.coeff.size() - 1;
        DynamicArray<T> result(resultSize, T(0));
        for (size_t i = 0; i < coeff.size(); ++i)
            for (size_t j = 0; j < other.coeff.size(); ++j)
                result[i + j] += coeff[i] * other.coeff[j];
        return Polynomial(result);
    }

    Polynomial operator-() const {
        DynamicArray<T> negCoeffs(coeff.size());
        for (size_t i = 0; i < coeff.size(); ++i)
            negCoeffs[i] = -coeff[i];
        return Polynomial(negCoeffs);
    }

    bool operator==(const Polynomial& other) const {
        return coeff== other.coeff;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coeff.size() == 0) {
            os << "0";
            return os;
        }
        for (size_t i = 0; i < p.coeff.size(); ++i) {
            os << p.coeff[i] << "x^" << i;
            if (i + 1 < p.coeff.size())
                os << " + ";
        }
        return os;
    }

    static Polynomial zero(size_t size = 1) {
        return Polynomial(DynamicArray<T>(size, T(0)));
    }

    static Polynomial one(size_t size = 1) {
        DynamicArray<T> coeffs(size, T(0));
        coeffs[0] = T(1);
        return Polynomial(coeffs);
    }
};





/*

#include <functional>
#include <vector>
#include <iostream>
template <typename T>
class Polynomial {
public:
    std::vector<T> coeff;
    Polynomial() = default;

    explicit Polynomial(std::vector<T> coeffs) : coeff(std::move(coeffs)) {}

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = std::max(coeff.size(), other.coeff.size());
        std::vector<T> result(maxSize, T(0));
        for (size_t i = 0; i < coeff.size(); ++i)
            result[i] += coeff[i];
        for (size_t i = 0; i < other.coeff.size(); ++i)
            result[i] += other.coeff[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<T> result(coeff.size() + other.coeff.size() - 1, T(0));
        for (size_t i = 0; i < coeff.size(); ++i)
            for (size_t j = 0; j < other.coeff.size(); ++j)
                result[i + j] += coeff[i] * other.coeff[j];
        return Polynomial(result);
    }

    Polynomial operator-() const {
        std::vector<T> negCoeff(coeff.size());
        for (size_t i = 0; i < coeff.size(); ++i)
            negCoeff[i] = -coeff[i];
        return Polynomial(negCoeff);
    }

    bool operator==(const Polynomial& other) const {
        return coeff == other.coeff;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        for (size_t i = 0; i < p.coeff.size(); ++i) {
            os << p.coeff[i] << "x^" << i;
            if (i + 1 < p.coeff.size())
                os << " + ";
        }
        return os;
    }

    static Polynomial zero() { return Polynomial({0} ); }
    static Polynomial one() {return Polynomial({1}); }
};
*/

#endif // POLYNOMIAL_HPP