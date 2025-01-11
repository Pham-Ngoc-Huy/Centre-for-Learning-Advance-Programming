#include <iostream>
using namespace std;

int main(){
    //define a variable (var)
    int a = 10; // a:var
    //define a ref
    int& a1 = a; // a1:ref, i.e. a back door to the slot
    // define a pointer
    int* p; // a pointer
    p = &a;
    cout << a <<endl;
    cout << a1 <<endl;
    cout << *p <<endl;
}