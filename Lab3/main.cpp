#include <iostream>
#include "matrix.h"
#include "vector.h"
#include "smatrix.h"
#include "lmatrix.h"
#include "umatrix.h"
using namespace std;

int main(){
    SquareMatrix A(5);
    A.random();
    SquareMatrix B(5);
    B.random();
    SquareMatrix C(5);
    C.random();
    cout<< "Square Matrix A: " <<endl;
    A.print("A");
    cout<< "Square Matrix B: " <<endl;
    B.print("B");
    cout<< "Square Matrix C: " <<endl;
    C.print("C");

    SquareMatrix D(5, 0.0);
    D = ++(-A + B*C);
    cout << "D = ++ (- A + B*C): " <<endl;
    D.print("D");

    double detD = D.det();
    cout << "det(D) = " <<detD <<endl;

    Vector b(5);
    b.random();
    cout<<"Vector b: "<<endl;
    b.print();

    Vector x = D.inverse() *b;
    cout << "Solution x = D inverse *b: " << endl;
    x.print();
    cout << "Error || D*x - b ||_2 = "<< (D * x - b).norm (2) << endl;

    //===== lowtri matrices ======
    MatrixDoubleLowTri L1(5);
    L1.random();
    L1.print("L1");

    // copy constructors
    // MatrixDoubleLowTri L2(S1); // error outcome wrong dimension
    // MatrixDoubleLowTri L2(B); // error outcome - no lowtri
    MatrixDoubleLowTri L2(L1);

    L2.print("L2");

    // operators: the outcome of these operators must be an lowtri matrix
    // otherwise return run-time error
    MatrixDoubleLowTri L3(5);
    L3.zeros();
    L3.random();
    L3 = L1 + L2;
    // L3 = L1 + S1; // should return errors
    L3.print("L3");
}