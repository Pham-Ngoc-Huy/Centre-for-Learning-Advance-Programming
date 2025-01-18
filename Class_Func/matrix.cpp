// filename: matrix.cpp (source)
// contains the definition of all functions/methods
// of class Matrix 
#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include "matrix.h"

using namespace std;

// constructors
// method is the function belongs to the particular class

void Matrix::allocate(){
    // allocate entry based on the value of rows and cols
    entry = new double*[rows];
    for (int i =0; i < rows; i++){
        entry[i] = new double[cols];
    }
}
void Matrix::deallocate(){
    // set all entrices to be zero
    for (int i =0; i < rows; i++){
        delete[] entry[i];
    }
    delete[] entry;
}
// function is not belongs to the particular class
Matrix::Matrix(const int& r, const int& c){
    // initialize rows and cols
    rows = r;
    cols = c;

    allocate();
    for (int i = 0; i< rows; i++)
        for(int j =0; j< cols; j++)
            entry[i][j] = 0;

};
Matrix::Matrix(const int& r, const int& c, const double& val) : Matrix(r,c)
{
    for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++)
            entry[i][j] = val;
}
Matrix::Matrix(const Matrix& mat){
    rows = mat.rows;
    cols = mat.cols;
    // no entry = mat.entry -> it just copy the address of the entry
    // allocate its own entry
    // shallow copy -> copy address only
    // deep copy -> copy the deepest layer - value
    allocate();
    // deep copy
    for (int i=0; i<rows; i++)
        for(int j=0; j <cols; j++)
            entry[i][j] = mat.getEntry(i,j);
}


// destructor
Matrix::~Matrix(){
    deallocate();
}

// other methods
void Matrix::random(){
     for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++)
            entry[i][j] = 1 + rand() %10;
}

void Matrix::print(string name) const{
    cout<< "Matrix" << name << ": " <<endl;
     for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++){
            cout << entry[i][j] << ", ";
        }
        cout << endl;
}

double Matrix::getEntry(const int& rInd, const int& cInd) const{
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && rInd < cols);

    return entry[rInd][cInd];
}
void Matrix::setEntry(const int& rInd, const int& cInd, const double& val){
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && rInd < cols);

    entry[rInd][cInd] = val;
}
double Matrix::operator() (const int& rInd, const int& cInd) const{
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && rInd < cols);

    return entry[rInd][cInd];
}
double& Matrix::operator() (const int& rInd, const int&cInd){
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && rInd < cols);
    return entry[rInd][cInd];
}

Matrix& Matrix::operator=(const Matrix& mat){
    rows = mat.rows;
    cols = mat.cols;

    allocate();

    for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++)
        entry[i][j] = mat(i,j);
        // this pointer: mean *this caller always point to the caller - cuz it does not have a name :D

    return *this;
}

Matrix Matrix::operator+(const Matrix& mat){
    assert(this->rows == mat.rows);
    assert(this->cols == mat.cols);
    int r = this->rows;
    int c = this->cols;

    Matrix C(r,c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j ++)
            C(i,j) = this->entry[i][j] + mat(i,j);
    return C;
}







