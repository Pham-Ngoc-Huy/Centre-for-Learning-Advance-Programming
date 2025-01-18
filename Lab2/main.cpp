#include <iostream>
#include "matrix.h"
#include "vector.h"

using namespace std;

int main()
{
    const int p_INF = 100000;
    int c = 3.5;
    /*
    * 1. create vectors and matrices
    */
    Matrix A(5,4), B(5,4), C(5,4), D(4,5), E(5,5);
    Vector v(5), w(5), t(5);
    int alpha = 3.5;
    int beta = 0;

    /*
    * 2. initialize vectors and matrices
    */
    v.random();
    w.random();
    t.zeros();
    A.random();
    B.random();
    C.zeros();
    D.random();
    E.zeros();
    
    /* 
    * 3. print out the initialized vectors and matrices
    */
    v.print();
    w.print();
    t.print();
    A.print("A");
    B.print("B");
    C.print("C");
    D.print("D");
    E.print("E");

    /*
    * 4. compute vector norms
    */
    v.norm(2);
    v.norm(p_INF);

    /*
    * 5. operations
    */
    // ==== for vectors ====
    // ==== adding 2 vectors
    t = v + w;
    t.print();

    // ==== scalar-vector multiplication
    t = v*alpha;
    t.print();
    
    // ==== increament
    ++t;
    t.print();

    // === dot product of 2 vecotrs of the same size
    beta = dot(w,w);
    cout << "beta = " << beta << endl;
    // === for matrices =====
    // === adding 2 matrices
    E.zeros();
    C = A + B;
    C.print(" A+B");
    E = C + B;  //void operator= is still issues -> this must return error for right solution 

    // === matriz-matriz multiplication
    E = A * D;
    E.print(" A*D");
    // === matrix-scalar multiplication
    E = E*alpha;
    E.print("E");
    // ==== increament

    ++E;
    // ==== matriz-vector multiplication
    t = E * v;
    t.print();

    return 0;
}