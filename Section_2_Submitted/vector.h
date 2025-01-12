#ifndef _FUNCTION_VECTOR_
#define _FUNCTION_VECTOR_

void add(const double*& v1, const int& sizeV1, const double*& v2, const int& sizeV2, double*& w, int& sizeW);
void mult(const double**& E, const int& numRowsE, const int& numColsE, const double*& w,  const int& sizeW, double*& t, int& sizeT);
double* allocate(const int& numCols);
void deallocate(double* v);
void print(const double* v, const int& size , string name);

#endif
