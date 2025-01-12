#ifndef _FUNCTION_VECTOR_
#define _FUNCTION_VECTOR_

#include <string> 
using std::string;
void add(double*& v1, const int& sizeV1, double*& v2, const int& sizeV2, double*& w, int& sizeW);
void mult(double**& E, const int& numRowsE, const int& numColsE, double*& w,  const int& sizeW, double*& t, int& sizeT);
double* allocate(const int& numCols);
void random(double* v, int& numRows); 
void deallocate(double* v);
void print(double* v, const int& size , string name);
void zeros(double*& w, int sizeW);
#endif
