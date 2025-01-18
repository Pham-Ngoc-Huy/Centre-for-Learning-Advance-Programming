#include <iostream>
#include <cstdlib>
#include "matrix.h"
#include <string>

using namespace std;

double** allocate(int& numRows, int& numCols) {
    double** v = new double*[numRows];
    for (int i = 0; i < numRows; i++) {
        v[i] = new double[numCols];
    }
    return v;
} //truely return a pointer - not just and reference

void deallocate(double** v, int& numRows) {
    for (int i = 0; i < numRows; i++) {
        delete[] v[i];
    }
    delete[] v;
}

void zeros(double** v, int& numRows, int& numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            v[i][j] = 0.0;
        }
    }
}

void random(double** v, int& numRows, int& numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            v[i][j] = (rand() % 100) / 10.0; 
        }
    }
}

void add(double** A, int& numRowsA, int& numColsA, double** B, int& numRowsB, int& numColsB, double** C, int& numRowsC, int& numColsC) {
    if (numRowsA != numRowsB || numColsA != numColsB) {
        cout << "[ERROR] Matrix dimensions must match for Addition." << endl;
        return;
    }
    for (int i = 0; i < numRowsA; i++) {
        for (int j = 0; j < numColsA; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mult(double** A, int& numRowsA, int& numColsA, double** B, int& numRowsB, int& numColsB, double** C, int& numRowsC, int& numColsC) {
    if (numColsA != numRowsB) {
        cout << "[ERROR] Matrix dimensions must match for Multiplication." << endl;
        return;
    }
    for (int i = 0; i < numRowsA; i++) {
        for (int j = 0; j < numColsB; j++) {
            C[i][j] = 0; // assign full zero first - for sure only
            for (int k = 0; k < numColsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(double** v, int& numRows, int& numCols, const string& name) {
    cout << name << " = [" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}
