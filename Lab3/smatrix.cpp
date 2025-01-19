#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include "matrix.h"
#include "vector.h"
#include "smatrix.h"

using namespace std;
SquareMatrix::SquareMatrix (const int& s) : Matrix(s,s){
    size = s;
}
SquareMatrix::SquareMatrix(const int& s, const double val) : Matrix(s,s,val){
    size = s;
}
SquareMatrix::SquareMatrix(const Matrix& mat) : Matrix(mat){
    assert(mat.isSquare());
    size = getRows();
}
SquareMatrix::SquareMatrix(const SquareMatrix& mat) : Matrix(mat){
    size = getRows();
}
SquareMatrix::~SquareMatrix(){
}
SquareMatrix& SquareMatrix::operator=(const Matrix& mat){
    assert(mat.isSquare());
    Matrix::operator=(mat);
    return *this;
}
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& mat){
    Matrix::operator=(mat);
    return *this;
}
int SquareMatrix::getSize() const{
    return size;
}

bool SquareMatrix::islowTri() const{
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (entry[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

bool SquareMatrix::isupTri() const{
    for (int i = 1; i < size; i++){
        for (int j = 0; j < i; j++){
            if (entry[i][j] != 0){
                return false;
            }
    }
        }
    return true;
}

double SquareMatrix::det() const {
	int	size_h(size);	
	double	result(0.0);

	if (size_h == 1)
		result = entry[0][0];
	else
	{
		size_h = size - 1;
		for (int j = 0; j < size; ++j)
		{
			SquareMatrix Ah(size_h);
			Ah.zeros();
			for (int ii = 0; ii < size_h; ++ii)
			{
				for (int jj = 0; jj < j; ++jj)
					Ah(ii, jj) = entry[ii + 1][jj];
				for (int jj = j; jj < size_h; ++jj)
					Ah(ii, jj) = entry[ii + 1][jj + 1];
			}
			result += pow(-1.0, j) * entry[0][j] * Ah.det();
		}
    }

	return result;
}
SquareMatrix SquareMatrix::cofactor(const int& p, const int& q) const {
	assert(p > -1 && p < size);
	assert(q > -1 && q < size);		

	Matrix temp(size - 1, size, 0.0);
	for (int jj = 0; jj < temp.getCols(); ++jj)
	{
		for (int ii = 0; ii < p; ++ii)
			temp(ii, jj) = entry[ii][jj];
		for (int ii = p; ii < temp.getRows(); ++ii)
			temp(ii, jj) = entry[ii+1][jj];
	}

    SquareMatrix co(size - 1, 0.0);
	for (int ii = 0; ii < co.getSize(); ++ii)
	{
		for (int jj = 0; jj < q; ++jj)
			co(ii, jj) = temp(ii,jj);
		for (int jj = q; jj < co.getSize(); ++jj)
			co(ii, jj) = temp(ii,jj+1);
	}

	return co;
}

SquareMatrix SquareMatrix::adjoint() const {
	SquareMatrix adj(size, 0.0);
    int sign = 1;
    SquareMatrix temp(size-1, 0.0);
	if (size == 1) {
		adj(0, 0) = 1;
		return adj;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp = cofactor(i, j);
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			adj(j,i) = (sign) * temp.det();
		}
	}
	return adj;
}

SquareMatrix SquareMatrix::inverse() const {
	assert(fabs(det()) > 0.0 );

	SquareMatrix adj = adjoint();

	SquareMatrix inv(size, 0.0);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			inv(i,j) = adj(i,j) / det();

	return inv;
}