#ifndef _MATRIX_UP_TRI_
#define _MATRIX_UP_TRI_
#include "smatrix.h"

using namespace std;
class MatrixDoubleUpTri: public SquareMatrix{
    public:
        //construction
        MatrixDoubleUpTri(const int& s);
        MatrixDoubleUpTri(const int& s, const double& val);

        MatrixDoubleUpTri(const SquareMatrix& mat);
    
        //deconstruction
        ~MatrixDoubleUpTri();
        void setvalfornonzero(const double& val);
        void setEntry(const int& r, const int& c, const double& val);
        void ones();
        void random();

        //operators
        MatrixDoubleUpTri& operator*=(const Matrix &mat);
        MatrixDoubleUpTri& operator+=(const Matrix &mat);
        MatrixDoubleUpTri& operator=(const Matrix &mat);


    } 
 

;
#endif