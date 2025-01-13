#ifndef _MATRIX_H_
#define _MATRIX_H_

double** allocate(int& numRows, int& numCols);
void deallocate(double** v, int& numRows);
void zeros(double** v, int& numRows, int& numCols);
void random(double** v, int& numRows, int& numCols);
void add(double** A, int& numRowsA, int& numColsA, double** B, int& numRowsB, int& numColsB, double** C, int& numRowsC, int& numColsC);
void mult(double** A, int& numRowsA, int& numColsA, double** B, int& numRowsB, int& numColsB, double** C, int& numRowsC, int& numColsC);
void print(double** v, int& numRows, int& numCols, const std::string& name);
#endif 
