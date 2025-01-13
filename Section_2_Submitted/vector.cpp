#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

using namespace std;

double* allocate(int& sizeV) {
    return new double[sizeV];
}

void deallocate(double* v) {
    delete[] v;
}

void zeros(double* w, int &sizeW) {
    for (int i = 0; i < sizeW; i++) {
        w[i] = 0.0;
    }
}

void random(double* v, int& sizeV) {
    for (int i = 0; i < sizeV; i++) {
        v[i] = (rand() % 100) / 10.0;
    }
}

void add(double* v1, int& sizeV1, double* v2, int& sizeV2, double* w, int& sizeW) {
    if (sizeV1 != sizeV2 || sizeV1 != sizeW) {
        cout << "[ERROR] Vector sizes must match for Addition." << endl;
        return;
    }
    for (int i = 0; i < sizeV1; i++) {
        w[i] = v1[i] + v2[i];
    }
}

void mult(double** E, int &rowsE, int &colsE, double* w, int &sizeW, double* t, int& sizeT) {
    if (colsE != sizeW) {
        cout << "[ERROR] Matrix and vector sizes must match for Multiplication." << endl;
        return;
    }
    for (int i = 0; i < rowsE; i++) {
        t[i] = 0; // assign full zero first - for sure only
        for (int j = 0; j < colsE; j++) {
            t[i] += E[i][j] * w[j];
        }
    }
}

void print(double* v, int& sizeV, const string& name) {
    cout << name << " = [";
    for (int i = 0; i < sizeV; i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}
