#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;

#ifndef VECTOR_H
#define VECTOR_H
	class Vector{
		private:
			int size;
			double *entry;
			void allocate();
			
		public:
			Vector(const int &m);
			Vector(const int &m, const double &val);
			Vector(const Vector &v);
			~Vector();
			
			int getSize() const;
			void setEntry(const int &i, const double &val);
			double getEntry(const int i) const;
			void zeros();
			void ones();
			void random();
			double norm(const int &p);
			void print();
			
			double &operator()(const int i);
			double operator()(const int i) const;
			Vector &operator=(const Vector &vec);
			Vector operator-();
			Vector &operator++();
			Vector &operator+=(const Vector &vec);
			Vector &operator*=(const Vector &vec);
			Vector &operator*=(const double &scalar);
			Vector operator+(const Vector &vec);
			Vector operator-(const Vector &vec);
			Vector operator*(const Vector &vec);
			Vector operator*(const double &scalar);
			
			Vector dot(const Vector &vec1, const Vector &vec2);
	};
	
	double dot(const Vector &vec1, const Vector &vec2);
#endif
