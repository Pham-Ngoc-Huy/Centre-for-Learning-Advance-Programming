#include <iostream>
#include <cmath>
#include "library.h"

using namespace std;

double Circle::area() const {
    return M_PI*radius*radius;
}
void Circle::display() const {
    cout << "Circle: with radius " <<radius<<" , the area "<< area() 
    <<" and the perimeter is: " << perimeter() <<endl;
}
double Circle::perimeter() const{
    return 2*M_PI*radius;
}
double Rectangle::area() const{
    return length*width;
}
double Rectangle::perimeter() const{
    return 2*(length+width);
}
void Rectangle::display() const{
    cout << "Rectangle: with length " << length << " , width "<<width
    <<" ,area " <<area()<<" and the perimeter " << perimeter() <<endl;
}
double Sphere::area() const{
    return 4*M_PI*radius*radius;
}
double Sphere::volume() const{
    return (4.0/3.0)*M_PI*radius*radius*radius;
}
void Sphere::display() const{
    cout << "Sphere: has the radius "<<radius<<
    " ,the area is: " << area()<< " ,and the volume is: "<< volume() <<endl;
}
double Cuboid::area() const{
    return 2*(length*width+length*height+width*height);
}
double Cuboid::volume() const{
    return length*width*height;
}
void Cuboid::display() const{
    cout << "Cuboid: has the length " << length << " ,width "<< width
    << " ,height " << height << " ,area " << area() << " ,and the volume " << volume() <<endl;
}