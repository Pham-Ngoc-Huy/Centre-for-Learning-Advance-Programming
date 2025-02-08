#ifndef __LIB_AREA__
#define __LIB_AREA__
#include <iostream>
using namespace std;

class Shape{
    protected:
    public:
        //constructor
        double s;
        Shape():s(0) {};
        virtual double area() const = 0;
        //member function
        virtual void display() const = 0;
        virtual ~Shape() {}; 

};
class TwoDimensionalShape : public Shape{  
    public:
        virtual double perimeter() const = 0;
};
class ThreeDimensionalShape : public Shape{
    public:
        virtual double volume() const = 0;
};
class Circle : public TwoDimensionalShape{
    protected:
        double radius;
    public:
        //constructor:
        Circle(const double& radius_):radius(radius_){};
        double area() const override;
        void display() const override;
        double perimeter() const override;
        virtual ~Circle() {};
};
class Rectangle : public TwoDimensionalShape{
    protected:
        double length;
        double width;
    public:
        //constructor
        Rectangle(const double& length_, const double& width_) : length(length_), width(width_){};
        double area() const override;
        void display() const override;
        double perimeter() const override;
        virtual ~Rectangle() {};
};
class Sphere : public ThreeDimensionalShape{
    protected:
        double radius;
    public:
        Sphere(const double& radius_):radius(radius_){};
        double area() const override;
        void display() const override;
        double volume() const override;
        virtual ~Sphere(){};

};
class Cuboid : public ThreeDimensionalShape{
    protected:
        double length;
        double height;
        double width;
    public:
        Cuboid(const double& length_, const double& height_, const double& width_):length(length_), height(height_), width(width_){};
        double area() const override;
        void display() const override;
        double volume() const override;
        virtual ~Cuboid(){};
};
#endif