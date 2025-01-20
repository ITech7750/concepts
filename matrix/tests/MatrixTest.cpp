#include "MatrixTest.h"
#include "../Matrix.hpp"
#include <iostream>
#include <cassert>

void testMatrixAddition() {
    Matrix<int> m1(2, 2);
    m1.elems[0][0] = 1; m1.elems[0][1] = 2;
    m1.elems[1][0] = 3; m1.elems[1][1] = 4;

    Matrix<int> m2(2, 2);
    m2.elems[0][0] = 5; m2.elems[0][1] = 6;
    m2.elems[1][0] = 7; m2.elems[1][1] = 8;

    Matrix<int> result = m1 + m2;

    assert(result.elems[0][0] == 6);
    assert(result.elems[0][1] == 8);
    assert(result.elems[1][0] == 10);
    assert(result.elems[1][1] == 12);

    std::cout << "Matrix Add" << std::endl;
}

void testMatrixMultiplication() {
    Matrix<int> m1(2, 2);
    m1.elems[0][0] = 1; m1.elems[0][1] = 2;
    m1.elems[1][0] = 3; m1.elems[1][1] = 4;

    Matrix<int> m2(2, 2);
    m2.elems[0][0] = 5; m2.elems[0][1] = 6;
    m2.elems[1][0] = 7; m2.elems[1][1] = 8;

    Matrix<int> result = m1 * m2;

    assert(result.elems[0][0] == 19);
    assert(result.elems[0][1] == 22);
    assert(result.elems[1][0] == 43);
    assert(result.elems[1][1] == 50);

    std::cout << "Matrix Mult" << std::endl;
}

void testMatrixNegation() {
    Matrix<int> m1(2, 2);
    m1.elems[0][0] = 1; m1.elems[0][1] = 2;
    m1.elems[1][0] = 3; m1.elems[1][1] = 4;

    Matrix<int> result = -m1;

    assert(result.elems[0][0] == -1);
    assert(result.elems[0][1] == -2);
    assert(result.elems[1][0] == -3);
    assert(result.elems[1][1] == -4);

    std::cout << "Matrix Neog" << std::endl;
}

void testZeroMatrix() {
    Matrix<int> m = Matrix<int>::zero(2, 2);

    assert(m.elems[0][0] == 0);
    assert(m.elems[0][1] == 0);
    assert(m.elems[1][0] == 0);
    assert(m.elems[1][1] == 0);

    std::cout << "Matrix Zero" << std::endl;
}

void runAllMatrTest() {
    testMatrixAddition();
    testMatrixMultiplication();
    testMatrixNegation();
    testZeroMatrix();
    std::cout << "All mstrix test passed" << std::endl;
}
