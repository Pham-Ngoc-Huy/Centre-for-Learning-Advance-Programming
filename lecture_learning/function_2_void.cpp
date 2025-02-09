#include <iostream>
#include <cmath>
using namespace std;


//pass by ref
void add(int& a, int& b, int& c) //void mean return - then return empty -> still return but use full reference
{
    c = a + b;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
}
void add(const int& a, const int& b, const int& c, int& d) // can share same name but different input
{
    d = a + b + c + d;
}
//polar 2 Cartesian 
void pol2car(double& x, double& y, double& r, double& theta)
{
    x  = r*cos(theta);
    y = r*sin(theta);
}
int main(){
    int x = 10;
    int y = 20;
    int z;
    add(x,y,z);
    cout << &x << endl;
    cout << &y << endl;
    cout << &z << endl;
}