#include <iostream>
#include "vector.h"
#include "matrix.h"

using namespace std;

int main() {
    // Matrix dimensions and pointers
    int numRowsA, numColsA;
    int numRowsB, numColsB;
    int numRowsC, numColsC;
    int numRowsD, numColsD;
    int numRowsE, numColsE;
    double **A, **B, **C, **D, **E;

    // Input dimensions for matrices A and B
    cout << "Input numRowsA and numColsA: " << endl;
    cin >> numRowsA >> numColsA;

    cout << "Input numRowsB and numColsB: " << endl;
    cin >> numRowsB >> numColsB;

    // Compute dimensions for C, D, and E
    numRowsC = numRowsA;
    numColsC = numColsA;
    numRowsD = numColsA;
    numColsD = numColsA; // Example assumption
    numRowsE = numRowsA;
    numColsE = numColsD;

    // Allocate memory for matrices
    A = allocate(numRowsA, numColsA);
    B = allocate(numRowsB, numColsB);
    C = allocate(numRowsC, numColsC);
    D = allocate(numRowsD, numColsD);
    E = allocate(numRowsE, numColsE);

    // Initialize matrices
    random(A, numRowsA, numColsA);
    random(B, numRowsB, numColsB);
    random(D, numRowsD, numColsD);

    // Set matrices C and E to zero
    zeros(C, numRowsC, numColsC);
    zeros(E, numRowsE, numColsE);

    // Perform matrix operations
    // C = A + B
    add(A, numRowsA, numColsA, B, numRowsB, numColsB, C, numRowsC, numColsC);

    // E = A * D
    mult(A, numRowsA, numColsA, D, numRowsD, numColsD, E, numRowsE, numColsE);

    // Vector dimensions and pointers
    int sizeV1, sizeV2, sizeW, sizeT;
    double *v1, *v2, *w, *t;

    // Compute vector sizes (example assumptions)
    sizeV1 = numColsA;
    sizeV2 = numColsA;
    sizeW = sizeV1;
    sizeT = numRowsE;

    // Allocate memory for vectors
    v1 = allocate(sizeV1);
    v2 = allocate(sizeV2);
    w = allocate(sizeW);
    t = allocate(sizeT);

    // Initialize vectors
    random(v1, sizeV1);
    random(v2, sizeV2);

    // Set vectors w and t to zero
    zeros(w, sizeW);
    zeros(t, sizeT);

    // Perform vector operations
    // w = v1 + v2
    add(v1, sizeV1, v2, sizeV2, w, sizeW);

    // t = E * w
    mult(E, numRowsE, numColsE, w, sizeW, t, sizeT);

    // Print results
    print(v1, sizeV1, "v1");
    print(v2, sizeV2, "v2");
    print(w, sizeW, "w = v1 + v2");
    print(A, numRowsA, numColsA, "A");
    print(B, numRowsB, numColsB, "B");
    print(C, numRowsC, numColsC, "C = A + B");
    print(D, numRowsD, numColsD, "D");
    print(E, numRowsE, numColsE, "E = A * D");
    print(t, sizeT, "t = E * w");

    // Deallocate memory
    deallocate(v1);
    deallocate(v2);
    deallocate(w);
    deallocate(t);
    deallocate(A, numRowsA);
    deallocate(B, numRowsB);
    deallocate(C, numRowsC);
    deallocate(D, numRowsD);
    deallocate(E, numRowsE);

    return 0;
}