#include <iostream>
using namespace std;

// a function to: c = a + b
int add(int a, int b) 
{
    int c = 0;
    c = a + b;
    
    cout << "INSIDE add:" <<endl;
    cout << &a <<endl;
    cout << &b <<endl;
    cout << &c <<endl;
    return c; //return the value to the caller
} 
int main()
{
    int x = 10, y = 20;
    int z = 0;
    // call the add function
    z = add(x,y);
    cout << "z = x + y = "<< z << endl;
    cout << &x <<endl;
    cout << &y <<endl;
    cout << &z <<endl;
}