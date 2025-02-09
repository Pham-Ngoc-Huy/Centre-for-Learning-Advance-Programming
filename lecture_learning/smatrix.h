#ifndef _SQUARE_MATRIX_
#define _SQUARE_MATRIX_

#include "matrix.h"

class SquareMatrix : public Matrix {
protected:
	int size;

public:
	// constructors and destructor
	SquareMatrix(const int& s);
	SquareMatrix(const int& s, const double& val);
	SquareMatrix(const Matrix& mat);  // if mat isSquare()
	SquareMatrix(const SquareMatrix& mat);
	virtual ~SquareMatrix();  // defined

	// assignment operators
	int getSize() const;
	SquareMatrix& operator=(const Matrix& mat);
	SquareMatrix& operator=(const SquareMatrix& mat);

	// additional methods
	double det() const;  // defined
	SquareMatrix inverse() const;  // defined

	// these serve for the purpose of finding the inverse
	SquareMatrix cofactor(const int& p, const int& q) const;  // defined
	SquareMatrix adjoint() const;	// defined
};



#endif
