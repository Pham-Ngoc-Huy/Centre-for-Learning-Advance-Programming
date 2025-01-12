#include <iostream>
#include <cstdlib>
#include "matrix.h"
#include <cstring>
#include <string>
using namespace std;

// same size before adding
void add(double**& A, const int& numRowsA, const int& numColsA, double**& B, const int& numRowsB, const int& numColsB, double**& C, int& numRowsC, int& numColsC)
{
    if (numRowsA == numRowsB && numColsA == numColsB)
    {
        cout<<"The Correct Size of Vector for calculating"<<endl;
        cout<<"Start to calculating..."<<endl;
        numColsC = numColsA;
        numRowsC = numRowsA;

        C = new double*[numRowsC];
        for (int i =0; i< numRowsC; ++i){
            C[i] = new double[numColsC]();
        }
        for(int i = 0; i < numColsC; ++i){
            for(int j = 0; j < numRowsC; ++j){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    else {
        cout<<"The Size of 2 vector are different... Redefine"<<endl;
    }

}
// same size before multiply
void mult(double**& A, const int& numRowsA, const int& numColsA,  double**& B, const int& numRowsB, const int& numColsB, double**& D, int& numRowsD, int& numColsD)
{
    if (numColsA == numRowsB) {
        cout << "The Correct Size of Matrix." << endl;

        numRowsD = numRowsA;
        numColsD = numColsB;

        D = new double*[numRowsD];
        for (int i = 0; i < numRowsD; ++i) {
            D[i] = new double[numColsD]();
        }

        cout << "Starting multiplication..." << endl;

        for (int i = 0; i < numRowsA; ++i) {
            for (int j = 0; j < numColsB; ++j) {
                for (int k = 0; k < numColsA; ++k) {
                    D[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    } else {
        cout << "The Wrong Size of Matrix." << endl;
    }
}

double** allocate(const int& numCols, const int& numRows)
{
    double** v;
    v = new double*[numRows];
    for (int i = 0; i < numCols; ++i) {
        v[i] = new double[numCols]();
    }
    return v;
}

void random(double** v, int& numRows, int& numCols) {
    v = new double*[numRows];
    for (int i = 0; i < numCols; ++i) {
        v[i] = new double[numCols]();
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            v[i][j] = rand() % 50; 
        }
    }
}

void deallocate(double** v, const int& numRows) {
    for (int i = 0; i < numRows; ++i) {
        delete[] v[i];
    }
    delete[] v; 
}

void print(double** v, const int& numRows, const int& numCols, string name) 
{
    cout << "Matrix " << name << ":" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void zeros(double**& C, int numRowsC, int numColsC) {
    // Allocate memory for the array
    C = new double*[numRowsC];
    for (int i = 0; i < numRowsC; ++i) {
        C[i] = new double[numColsC];
        // Initialize each row to zeros
        std::memset(C[i], 0, numColsC * sizeof(double));
    }
}