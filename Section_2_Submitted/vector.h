#include <string>
#ifndef _VECTOR_H_
#define _VECTOR_H_
using namespace std;

double* allocate(int& sizeV);
void deallocate(double* v);
void zeros(double* w, int &sizeW);
void random(double* v, int& sizeV);
void add(double* v1, int& sizeV1, double* v2, int& sizeV2, double* w, int& sizeW);
void mult(double** E, int &rowsE, int &colsE, double* w, int &sizeW, double* t, int& sizeT);
void print(double* v, int& sizeV, const string& name);

#endif
