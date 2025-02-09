#include <iostream>
using namespace std;

int add(int& a, int& b)
{
    int c;
    c = a + b;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    return c;
}
int main(){
    int x = 10;
    int y = 20;
    int z;
    z = add(x,y);
    cout << &x << endl;
    cout << &y << endl;
    cout << &z << endl;
}

// this is referece but still return the slot in the function