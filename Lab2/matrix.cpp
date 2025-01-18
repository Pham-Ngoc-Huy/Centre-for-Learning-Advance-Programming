#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include "matrix.h"
#include "vector.h"

using namespace std;

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
int Matrix::getRows() const {
    return rows;  
}
int Matrix::getCols() const {
    return cols; 
}
void Matrix::ones() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            entry[i][j] = 1.0; 
        }
    }
}
void Matrix::eye() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                entry[i][j] = 1.0;  
            } else {
                entry[i][j] = 0.0;  
            }
        }
    }
}

Matrix::Matrix(const int& r, const int& c){
    // initialize rows and cols
    rows = r;
    cols = c;

    allocate();
};
Matrix::Matrix(const int& r, const int& c, const double& val) : Matrix(r,c)
{
    for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++)
            entry[i][j] = val;
}


void Matrix::zeros(){
    for (int i = 0; i< rows; i++)
        for(int j =0; j< cols; j++)
            entry[i][j] = 0;
}
void Matrix::random(){
     for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols; j++)
            entry[i][j] = 1 + rand() %10;
}

Matrix::~Matrix(){
    deallocate();
}

void Matrix::print(string name) const{
    cout<< "Matrix" << name << ": " <<endl;
     for (int i = 0; i < rows ; i++){
        for (int j = 0; j < cols; j++){
            cout << entry[i][j] << ", ";
        }
        cout << endl;
     }
}
// operator
double Matrix::getEntry(const int& rInd, const int& cInd) const{
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && cInd < cols);

    return entry[rInd][cInd];
}
void Matrix::setEntry(const int& rInd, const int& cInd, const double& val){
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && rInd < cols);

    entry[rInd][cInd] = val;
}
double& Matrix::operator() (const int& rInd, const int&cInd) const{
    assert(rInd > -1 && rInd < rows);
    assert(cInd > -1 && cInd < cols);
    return entry[rInd][cInd];
}

Matrix::Matrix(const Matrix& mat){
    rows = mat.rows;
    cols = mat.cols;
    allocate();
    for (int i=0; i<rows; i++)
        for(int j=0; j <cols; j++)
            entry[i][j] = mat.getEntry(i,j);
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
Matrix Matrix::operator-(const Matrix& mat){
    assert(this->rows == mat.rows);
    assert(this->cols == mat.cols);
    int r = this->rows;
    int c = this->cols;

    Matrix C(r,c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j ++)
            C(i,j) = this->entry[i][j] - mat(i,j);
    return C;
}
Matrix& Matrix::operator=(const Matrix& mat) {
    if (rows != mat.rows || cols != mat.cols) {
        cout<<"Matrix assignment error: Dimension mismatch"<<endl;
        return *this;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            entry[i][j] = mat(i,j);
        }
    }

    return *this;
}
Matrix Matrix::operator*(const Matrix& mat){
    assert(this->cols == mat.rows);
    int r = this->rows;
    int c = mat.cols; 
    int n = this->cols; 

    Matrix C(r, c); 

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C(i, j) = 0;
            for (int k = 0; k < n; k++) {
                C(i, j) += this->entry[i][k] * mat.entry[k][j];
            }
        }
    }
    return C;
}

Matrix& Matrix::operator++() { 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->entry[i][j] += 1; 
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& mat) {
    assert(this->rows == mat.rows && this->cols == mat.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->entry[i][j] += mat.entry[i][j];
        }
    }   
    return *this;
}

Matrix& Matrix::operator*=(const double& alp) { 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            entry[i][j] *= alp; 
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& mat) {
    assert(this->cols == mat.rows); 
    Matrix result(this->rows, mat.cols); 

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result(i, j) = 0;  
            for (int k = 0; k < this->cols; k++) {
                result(i, j) += this->entry[i][k] * mat.entry[k][j];  
            }
        }
    }
    *this = result;
    return *this;
}

Matrix Matrix::operator*(const double& alp){
    int r = this->rows;
    int c = this->cols; 
    Matrix C(r, c); 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C(i, j) += this->entry[i][j] * alp;
            }
        }
    return C;
}

Vector Matrix::operator*(const Vector& vec) {
    if (this->cols != vec.getSize()) {  // Ensure dimension compatibility
        cout << "Matrix-vector multiplication is mismatch dimension"<<endl;
        return Vector(this->rows);     
    }
    int r = this->rows;
    int c = this->cols;
    Vector C(r); 

    for (int i = 0; i < r; i++) {
        double sum = 0;
        for (int j = 0; j < c; j++) {
            sum += this->entry[i][j] * vec.getEntry(j);
        }
        C.setEntry(i,sum);
    }
    return C;
}

Matrix Matrix::operator-() const {
    Matrix A(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            A.entry[i][j] = -(this->entry[i][j]);  
        }
    }
    return A;  
}

Matrix transpose(const Matrix& mat) {
    int rows = mat.rows;    
    int cols = mat.cols;    
    Matrix B(cols, rows);  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B(j, i) = mat.entry[i][j];  
        }
    }
    return B; 
}

