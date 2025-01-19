#ifndef _HEADER_MATRIX_
#define _HEADER_MATRIX_
#include <iostream>
#include <cassert>
#include <string>
#include "vector.h"

using namespace std;
class Matrix{

private:
    // //member data:
    // int rows;
    // int cols;
    // double** entry;
    void allocate();
    void deallocate();
protected:
    int rows;
    int cols;
    double** entry;
public:
    //constructor and  destructor
    Matrix(const int& r, const int& c);
    Matrix(const int& r, const int& c, const double& val);
    Matrix(const Matrix& mat);
    virtual ~Matrix();

    // member methods:
    int getRows() const;
    int getCols() const;
    double getEntry(const int& rInd, const int& cInd) const;
    void setEntry(const int& rInd, const int& cInd, const double& val);
    virtual void zeros();
    virtual void ones();
    void eye();
    virtual void random();
    void print(string name) const;

    // entry access:
    double& operator() (const int& rInd, const int&cInd) const;

    // member operations:
    //A = B
    Matrix& operator=(const Matrix& mat);
    //A = -B
    Matrix operator-() const;
    // ++A
    Matrix& operator++();
    // A += B
    Matrix& operator+=(const Matrix& mat);
    // A *= alp
    Matrix& operator*=(const double& alp);
    // A *= B
    Matrix& operator*=(const Matrix& mat);
    //C = A+B
    Matrix operator+(const Matrix& mat);
    //C = A-B
    Matrix operator-(const Matrix& mat);
    //B = A * alp
    Matrix operator*(const double& alp);
    //C = A*B
    Matrix operator*(const Matrix& mat);
    // matrix * vector
    Vector operator*(const Vector& vec);
    //
    bool isSquare() const;
};
// B= transpose(A)
Matrix transpose(const Matrix& mat);



#endif