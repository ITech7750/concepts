#include "concept/Сoncepts.hpp"
#include "polynom/Polynomial.hpp"
#include "matrix/Matrix.hpp"
#include "matrix/tests/MatrixTest.h"
#include "polynom/tests/PolynomTest.h"
#include <functional>


int main() {
    //runAllPolynomTests();
    //runAllMatrTest();
    using Poly = Polynomial<int>;
    using Mat = Matrix<int>;

    static_assert(Ring<Poly, std::plus<>, std::multiplies<>, std::negate<>, Polynomial<int>>);
    static_assert(!Ring<Mat, std::plus<>, std::multiplies<>, std::negate<>, Matrix<int>>);

    return 0;
}



/*
template <typename T>
class Add {
public:
    T operator()(const T& a, const T& b) const {
        return a + b;
    }
};

template <typename T>
class Mul {
public:
    T operator()(const T& a, const T& b) const {
        return a * b;
    }
};

template <typename T>
class Negate {
public:
    T operator()(const T& a) const {
        return -a;
    }
};

template <typename T>
class Add<Polynomial<T>> {
public:
    Polynomial<T> operator()(const Polynomial<T>& a, const Polynomial<T>& b) const {
        return a + b;
    }
};

template <typename T>
class Mul<Polynomial<T>> {
public:
    Polynomial<T> operator()(const Polynomial<T>& a, const Polynomial<T>& b) const {
        return a * b;
    }
};

template <typename T>
class Negate<Polynomial<T>> {
public:
    Polynomial<T> operator()(const Polynomial<T>& p) const {
        return -p;
    }
};

template <typename T>
class Add<Matrix<T>> {
public:
    Matrix<T> operator()(const Matrix<T>& a, const Matrix<T>& b) const {
        return a + b;
    }
};

template <typename T>
class Mul<Matrix<T>> {
public:
    Matrix<T> operator()(const Matrix<T>& a, const Matrix<T>& b) const {
        return a * b;
    }
};

template <typename T>
class Negate<Matrix<T>> {
public:
    Matrix<T> operator()(const Matrix<T>& m) const {
        return -m;
    }
};

int main() {
    using Poly = Polynomial<int>;
    using Mat = Matrix<int>;

    static_assert(Ring<Poly, Add<int>, Mul<int>, Negate<int>, Polynomial<int>>);
    static_assert(!Ring<Mat, Add<int>, Mul<int>, Negate<int>, Matrix<int>>);


    static_assert(Ring<Poly, std::plus<>, std::multiplies<>, std::negate<>, Polynomial<int>>);
    static_assert(!Ring<Mat, std::plus<>, std::multiplies<>, std::negate<>, Matrix<int>>);
    return 0;
}
*/