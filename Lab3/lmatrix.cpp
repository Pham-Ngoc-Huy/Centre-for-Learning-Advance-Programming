#include <iostream>
#include "lmatrix.h"
#include <cstdio>
using namespace std;

MatrixDoubleLowTri::MatrixDoubleLowTri(const int& s) : SquareMatrix(s){
    zeros();
}
MatrixDoubleLowTri::MatrixDoubleLowTri(const int& s, const double& val) : SquareMatrix(s,val){
    zeros();
    setvalfornonzero(val);
}
MatrixDoubleLowTri::MatrixDoubleLowTri(const SquareMatrix& mat): SquareMatrix(mat){
    SquareMatrix B(mat);
    assert(mat.islowTri());

}
MatrixDoubleLowTri::~MatrixDoubleLowTri(){
}

void MatrixDoubleLowTri::setvalfornonzero(const double& val){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < (i+1); j++){
            entry[i][j] = val;
        }
    }
}

void MatrixDoubleLowTri::setEntry(const int& r, const int& c, const double& val){
    if (c <= r){
        entry[r][c] = val;
    }
    else
        cout<<"LowTri Matrix cannot set value in this entry"<<endl;

}
void MatrixDoubleLowTri::ones(){
    zeros();
    setvalfornonzero(1);
}

void MatrixDoubleLowTri::random(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < (i+1); j++){
            entry[i][j] = rand() % 10;
        }
    }
}

MatrixDoubleLowTri& MatrixDoubleLowTri::operator=(const Matrix &mat){
	MatrixDoubleLowTri B(mat);
	Matrix::operator=(mat);
    return *this;

}

MatrixDoubleLowTri& MatrixDoubleLowTri::operator+=(const Matrix &mat){
	MatrixDoubleLowTri B(mat);
	Matrix::operator+=(mat);
    return *this;

}

MatrixDoubleLowTri& MatrixDoubleLowTri::operator*=(const Matrix &mat){
	MatrixDoubleLowTri B(mat);
	Matrix::operator*=(mat);
    return *this;

}
