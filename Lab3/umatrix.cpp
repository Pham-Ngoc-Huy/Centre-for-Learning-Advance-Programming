#include <iostream>
#include "umatrix.h"
#include <cstdio>
using namespace std;

MatrixDoubleUpTri::MatrixDoubleUpTri(const int& s) : SquareMatrix(s){
    zeros();
}
MatrixDoubleUpTri::MatrixDoubleUpTri(const int& s, const double& val) : SquareMatrix(s,val){
    zeros();
    setvalfornonzero(val);
}
MatrixDoubleUpTri::MatrixDoubleUpTri(const SquareMatrix& mat): SquareMatrix(mat){
    SquareMatrix B(mat);
    assert(mat.isupTri());

}
MatrixDoubleUpTri::~MatrixDoubleUpTri(){
}

void MatrixDoubleUpTri::setvalfornonzero(const double& val){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            entry[i][j] = val;
        }
    }
}

void MatrixDoubleUpTri::setEntry(const int& r, const int& c, const double& val){
    if (c >= r){
        entry[r][c] = val;
    }
    else
        cout<<"LowTri Matrix cannot set value in this entry"<<endl;
    

}
void MatrixDoubleUpTri::ones(){
    zeros();
    setvalfornonzero(1);
}

void MatrixDoubleUpTri::random(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j)
                mat[i][j] =0;
            else
                mat[i][j] = 1 + rand() % 10;
        }
    }
}

MatrixDoubleUpTri& MatrixDoubleUpTri::operator=(const Matrix &mat){
	MatrixDoubleUpTri B(mat);
	Matrix::operator=(mat);
    return *this;

}

MatrixDoubleUpTri& MatrixDoubleUpTri::operator+=(const Matrix &mat){
	MatrixDoubleUpTri B(mat);
	Matrix::operator+=(mat);
    return *this;

}

MatrixDoubleUpTri& MatrixDoubleUpTri::operator*=(const Matrix &mat){
	MatrixDoubleUpTri B(mat);
	Matrix::operator*=(mat);
    return *this;

}
