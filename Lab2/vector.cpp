#include "vector.h"

Vector::Vector(const int &m){
	size = m;
	allocate();
}

Vector::Vector(const int &m, const double &val):Vector(m){
	for(int i = 0; i < size; i++)
		entry[i] = val;
}

Vector::Vector(const Vector &v){
	size = v.getSize();
	allocate();
	for(int i = 0; i < size; i++)
		entry[i] = v.getEntry(i);
}

Vector::~Vector(){
	delete[] entry;
}

void Vector::allocate(){
	entry = new double[size];
}

int Vector::getSize() const{
	return size;
}

void Vector::setEntry(const int &i, const double &val){
	entry[i] = val;
}

double Vector::getEntry(const int i) const{
	return entry[i];
}

void Vector::zeros(){
	for(int i = 0; i < size; i++)
		entry[i] = 0;
}

void Vector::ones(){
	for(int i = 0; i < size; i++)
		entry[i] = 1;
}

void Vector::random(){
	for(int i = 0; i < size; i++)
		entry[i] = 1 + rand() % 10;
}

double Vector::norm(const int &p){
	double result = 0;
	for(int i = 0; i < size; i++)
		result += pow(entry[i], p);
	result = pow(result, 1.0/p);
	return result;
}

void Vector::print(){
	cout << "[";
	for(int i = 0; i < size; i++){
		cout << entry[i];
		if(i < size - 1){
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

double &Vector::operator()(const int i){
	assert(i > -1 && i < size);
	return entry[i];
}

double Vector::operator()(const int i) const{
	assert(i > -1 && i < size);
	return entry[i];
}
Vector &Vector::operator=(const Vector &vec){
	assert(size == vec.getSize());
	for(int i = 0; i < size; i++)
		entry[i] = vec(i);
	return *this;
}

Vector Vector::operator-(){
	Vector Temp(size);
	for(int i = 0; i < size; i++)
		Temp(i) = -entry[i];
	return Temp;
}

Vector &Vector::operator++(){
	for(int i = 0; i < size; i++)
		this->entry[i]+=1;
	return *this;
}

Vector &Vector::operator+=(const Vector &vec){
	assert(size == vec.getSize());
	for(int i = 0; i < size; i++)
		entry[i] += vec(i);
	return *this;
}

Vector &Vector::operator*=(const double &scalar){
	for(int i = 0; i < size; i++)
		entry[i] *= scalar;
	return *this;
}

Vector Vector::operator+(const Vector &vec){
	assert(size == vec.getSize());
	Vector Temp(size);
	for(int i = 0; i < size; i++)
		Temp(i) = entry[i] + vec(i);
	return Temp;
}

Vector Vector::operator-(const Vector &vec){
	assert(size == vec.getSize());
	Vector Temp(size);
	for(int i = 0; i < size; i++)
		Temp(i) = entry[i] - vec(i);
	return Temp;
}

Vector Vector::operator*(const double &scalar){
	Vector Temp(size);
	for(int i = 0; i < size; i++)
		Temp(i) = scalar * entry[i];
	return Temp;
}

double dot(const Vector &vec1, const Vector &vec2){
	assert(vec1.getSize() == vec2.getSize());
	double result = 0;
	for(int i = 0; i < vec1.getSize(); i++)
		result += vec1(i) * vec2(i);
	return result;
}
