# include <iostream>
# include "vector.h"
# include "matrix.h"

using namespace std ;

int main ()
{
	// == matrices
	int numRowsA, numColsA;
	int numRowsB, numColsB;
	int numRowsC, numColsC;
	int numRowsD, numColsD;
	int numRowsE, numColsE;
	double **A, **B, **C, **D, **E;
	
	// from inputs
	cout << "Input numRowsA and numColsA:" << endl;
	cin >> numRowsA >> numColsA;
	cout << "Input numRowsB and numColsB:" << endl;
	cin >> numRowsB >> numColsB;
	cout << "Input numRowsD and numColsD:" << endl;
	cin >> numRowsD >> numColsD;
	
	// compute the size of C = A + B
	numRowsC = numRowsA;
	numColsC = numColsA;
	
	// compute the size of D and E such that E = A * D
	numRowsE = numRowsA;
	numColsE = numColsD;
	
	// allocation
	A = allocate(numRowsA, numColsA);
	B = allocate(numRowsB, numColsB);
	C = allocate(numRowsC, numColsC);
	D = allocate(numRowsD, numColsD);
	E = allocate(numRowsE, numColsE);
	
	// initialization
	random(A, numRowsA, numColsA);
	random(B, numRowsB, numColsB);
	random(D, numRowsD, numColsD);
	
	// set C and E to be zero
	zeros(C, numRowsC, numColsC);
	zeros(E, numRowsE, numColsE);
	
	// linear algebra
	// C = A + B
	add(A, numRowsA, numColsA, B, numRowsB, numColsB, C, numRowsC, numColsC);
	
	// E = A * D
	mult(A, numRowsA, numColsA, D, numRowsD, numColsD, E, numRowsE, numColsE);
	
	// === vectors
	int sizeV1, sizeV2, sizeW, sizeT;
	double *v1, *v2, *w, *t;
	
	// compute size v1 , v2 , and w such that
	// w = v1 + v2 , t = E*w
	cout << "Input sizeV1:" << endl;
	cin >> sizeV1;
	cout << "Input sizeV2:" << endl;
	cin >> sizeV2;
	
	sizeW = sizeV1;
	sizeT = numRowsE;
	
	// allocate v1 , v2 , w, and t
	v1 = allocate(sizeV1);
	v2 = allocate(sizeV2);
	w = allocate(sizeW);
	t = allocate(sizeT);
	
	// initialization
	random(v1, sizeV1);
	random(v2, sizeV2);
	
	// set zero
	zeros(w, sizeW);
	zeros(t, sizeT);
	
	// linear algebra
	// w = v1 + v2
	add(v1, sizeV1, v2, sizeV2, w, sizeW);
	
	// t = E*w
	mult(E, numRowsE, numColsE, w, sizeW, t, sizeT);
	
	// === print results
	print(v1, sizeV1, "v1");
	print(v2, sizeV2, "v2");
	print(w, sizeW, "w = v1 + v2");
	print(A, numRowsA, numColsA, "A");
	print(B, numRowsB, numColsB, "B");
	print(C, numRowsC, numColsC, "C = A + B");
	print(D, numRowsD, numColsD, "D");
	print(E, numRowsE, numColsE, "E = A * D");
	print(t, sizeT, "t = E * w");
	
	// deallocation
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