#include "../Polynomial.hpp"
#include <iostream>
#include <cassert>

void testPolynomialAddition() {
    Polynomial<int> p1({1, 2, 3});
    Polynomial<int> p2({4, 5, 6});
    Polynomial<int> result = p1 + p2;
    assert(result.coeff[0]== 5);
    assert(result.coeff[1] ==7);
    assert(result.coeff[2] == 9);

    std::cout << "Polynomial Add" << std::endl;
}

void testPolynomialMultiplication() {
    Polynomial<int> p1({1, 2});
    Polynomial<int> p2({3, 4});

    Polynomial<int> result = p1*p2;

    assert(result.coeff[0]==3);
    assert(result.coeff[1]==10);
    assert(result.coeff[2]==8);

    std::cout << "Polynomial Mult" << std::endl;
}

void testPolynomialNegation() {
    Polynomial<int> p1({1, 2, 3});

    Polynomial<int> result = -p1;

    assert(result.coeff[0] == -1);
    assert(result.coeff[1] == -2);
    assert(result.coeff[2] == -3);

    std::cout << "Polynomial Neog!" << std::endl;
}

void testZeroPolynomial() {
    Polynomial<int> p = Polynomial<int>::zero(3);

    assert(p.coeff[0] == 0);
    assert(p.coeff[1] == 0);
    assert(p.coeff[2] == 0);

    std::cout << "Polynomial zero" << std::endl;
}



void runAllPolynomTests() {
    testPolynomialAddition();
    testPolynomialMultiplication();
    testPolynomialNegation();
    testZeroPolynomial();
    std::cout << "All tetst in Polinom passed" << std::endl;
}
