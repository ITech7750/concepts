cmake_minimum_required(VERSION 3.30)
project(Concept)

set(CMAKE_CXX_STANDARD 20)

add_executable(Concept main.cpp
        concept/Сoncepts.hpp
        matrix/tests/MatrixTest.cpp
        polynom/tests/PolynomTest.cpp
)

