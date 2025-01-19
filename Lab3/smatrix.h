#ifndef _HEADER_MATRIX_SQUARE_
#define _HEADER_MATRIX_SQUARE_
#include <iostream>
#include <cassert>
#include <string>
#include "vector.h"
#include "matrix.h"
#include <cmath>

using namespace std;

class SquareMatrix: public Matrix{
    protected:
        int rows;
        int cols;
        int size;
    public:
        // constructors:
        SquareMatrix(const int& s);
        SquareMatrix(const int& s, const double val);
        SquareMatrix(const Matrix& mat);
        SquareMatrix(const SquareMatrix& mat);
        //virtual methods
        virtual ~SquareMatrix();
        virtual double det() const;

        //overload assignment operators
        SquareMatrix& operator=(const Matrix& mat);
        SquareMatrix& operator=(const SquareMatrix& mat);
        
        // additional or modified methods:
        int  getSize() const;
        bool islowTri() const;
        bool isupTri() const;
        SquareMatrix cofactor (const int& p, const int& q) const;
        SquareMatrix adjoint() const;
        SquareMatrix inverse() const;

};

#endif