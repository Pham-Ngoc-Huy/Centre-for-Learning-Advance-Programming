#include <iostream>
#include "matrix.h"
// #include "vector.h"

using namespace std;

int main()
{
    const int p_INF = 100000;
    int c = 3.5;
    /*
    * 1. create vectors and matrices
    */
    Matrix A(5,4), B(5,4), C(5,4), D(4,5), E(5,5);
    A.random();
    B.random();
    C.zeros();
    D.random();
    E.zeros();
    A.print("A");
    B.print("B");
    C.print("C");
    D.print("D");
    E.print("E");

    E.zeros();
    C = A + B;
    C.print(" A+B");
    E = C + B;  //void operator= is still issues -> this must return error for right solution 
    E.print("E");
    E = A * D;
    E.print(" A*D");
}