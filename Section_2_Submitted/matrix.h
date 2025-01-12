#ifndef _FUNCTION_MATRIX_
#define _FUNCTION_MATRIX_

#include <string> 
using std::string;
void add(double**& A, const int& numRowsA, const int& numColsA, double**& B, const int& numRowsB, const int& numColsB, double**& C, int& numRowsC, int& numColsC);
void mult(double**& A, const int& numRowsA, const int& numColsA, double**& B, const int& numRowsB, const int& numColsB, double**& D, int& numRowsD, int& numColsD);
double** allocate(const int& numCols, const int& numRows);
void deallocate(double** v, const int& numRows);
void print(double** v, const int& numRows, const int& numCols, string name);
void random(double** v, int& numRows, int& numCols);
void zeros(double**& C, int numRowsC, int numColsC);
#endif
