// filename: matrix.h (header)
// class MATRIX declaration (declare the structure of the class)
// answer 2 questions:
// 1. How to define this class ?
#ifndef _HEADER_MATRIX_
#define _HEADER_MATRIX_

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Matrix{
// 1. How to define class ?
private:
    int rows;
    int cols;
    double** entry;
    void allocate();
    void deallocate();

// 2. What can a matrix do ?
public:
    // constructors
    Matrix(const int& r, const int& c);
    Matrix(const int& r, const int& c, const double& val);
    Matrix(const Matrix& mat);

    // destructors: called automatically when out of scopes
    ~Matrix();
    void random();
    void print(string name) const;
    // get an entry value
    double getEntry(const int& rInd, const int& cInd) const;
    double operator()(const int& rInd, const int& cInd) const;
    // set an entry value
    void setEntry(const int& rInd, const int& cInd, const double& val);
    double& operator() (const int& rInd, const int&cInd);
    Matrix& operator=(const Matrix& mat);

    // addition operator
    Matrix operator+(const Matrix& mat);
};

#endif // !_HEADER_MATRIX_