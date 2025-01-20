#ifndef _MATRIX_LOW_TRI_
#define _MATRIX_LOW_TRI_
#include "smatrix.h"

using namespace std;
class MatrixDoubleLowTri: public SquareMatrix{
    public:
        //construction
        MatrixDoubleLowTri(const int& s);
        MatrixDoubleLowTri(const int& s, const double& val);

        MatrixDoubleLowTri(const SquareMatrix& mat);
    
        //deconstruction
        ~MatrixDoubleLowTri();
        void setvalfornonzero(const double& val);
        void setEntry(const int& r, const int& c, const double& val);
        void ones();
        void random();

        //operators
        MatrixDoubleLowTri& operator*=(const Matrix &mat);
        MatrixDoubleLowTri& operator+=(const Matrix &mat);
        MatrixDoubleLowTri& operator=(const Matrix &mat);


    } 
 

;
#endif