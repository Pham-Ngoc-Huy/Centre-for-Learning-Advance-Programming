#ifndef _FUNCTION_MATRIX_
#define _FUNCTION_MATRIX_

void add(const double**& A, const int& numRowsA, const int& numColsA, const double**& B, const int& numRowsB, const int& numColsB, double**& C, int& numRowsC, int& numColsC);
void mult(const double**& E, const int& numRowsE, const int& numColsE, const double*& w,  const int& sizeW, double*& t, int& sizeT);
double** allocate(const int& numCols, const int& numRows);
void deallocate(double** v, const int& numRows);
void print(const double** v, const int& numRows, const int& numCols, const string& name);
void random(int** matrix, int rows, int cols);
#endif
