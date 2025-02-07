#include <iostream>
#include <cmath>
using namespace std;

class Shape{
    public:
        // double area;
        // //constructor
        // Shape() : area(0) {};
        virtual double area() = 0;
        virtual ~Shape(){};

};
class Circle : public Shape
{
    protected:
        double radius;
    public:
        //constructor:
        Circle(const double& radius_) : radius(radius_){};
        double area() override
        {
            return 3.14*pow(radius,2);

        }
};
class Rectangle : public Shape
{
    protected:
        double length;
        double width;
    public:
        //constructor:
        Rectangle(const double& length_, const double& width_) : length(length_), width(width_){};
        double area() override
        {
            return length*width;
        }
};
int main(){
    Shape* shapes[2];
    shapes[0] = new Circle(3.0);
    shapes[1] = new Rectangle(4.0, 5.0);

    for (int i = 0; i < 2; i++) {
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];  // Free memory
    }

    return 0;
}

