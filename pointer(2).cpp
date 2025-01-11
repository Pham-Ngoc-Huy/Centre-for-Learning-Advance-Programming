#include <iostream>
using namespace std;

int main(){
    // define a variable (var)
    int a = 10;
    int* p = &a;
    int** q = &p;

    cout << q<<endl; // address of p
    cout << &q<<endl; // address of q
    cout << *q<<endl; // address of a
    cout << **q <<endl; // content of a
}