#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

// same size before adding
void add(double*& v1, const int& sizeV1, double*& v2, const int& sizeV2, double*& w, int& sizeW)
{
    if (sizeV1 == sizeV2)
    {
        cout<<"The Correct Size of Vector for calculating"<<endl;
        cout<<"Start to calculating..."<<endl;
        sizeW = sizeV1;
        for(int i = 0; i < sizeW; ++i){
            w[i] = v1[i] + v2[i];
        }
    }
    else {
        cout<<"The Size of 2 vector are different... Redefine"<<endl;
    }

}
// same size before multiply
void mult(double**& E, const int& numRowsE, const int& numColsE, double*& w,  const int& sizeW, double*& t, int& sizeT)
{
    if (numColsE == sizeW){
        cout<<"The Correct Size of Matrix compared with Vector"<<endl;
        t = new double[sizeT];
        sizeT = numRowsE;
        cout<<"Start to Multiplying..."<<endl;
        for(int i = 0; i < numRowsE; ++i){
            for(int j = 0; j < numColsE; ++j){
                t[i] += E[i][j] * w[j];
            }
        }
    }
    else{
        cout<<"The Size compared is incorrected"<<endl;
    }
}

double* allocate(const int& numCols)
{
    double* v;
    v = new double[numCols];
    return v;
}

void random(double* v, int& numRows) {
    v = new double[numRows];
    for (int i = 0; i < numRows; ++i) {
        v[i] = rand() % 50; 
    }
}

void deallocate(double* v)
{
delete [] v;
}

void print(double* v, const int& size , string name)
{
    cout << "Vector␣" << name << ":␣" << endl;
    for (int j = 0; j < size; ++j)
        cout << v[j] << ",␣";
        cout << endl;
}

void zeros(double*& w, int sizeW) {
    // Allocate memory for the array
    w = new double[sizeW];
    // Initialize all elements to zero
    std::memset(w, 0, sizeW * sizeof(double));
}