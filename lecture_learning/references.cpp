#include <iostream>
using namespace std;

int main(){
    // define a variable
    int a = 10;
    // define a reference
    int& a1 = a;
    cout << &a1 <<endl;
    cout << &a << endl;

    // Even though when u change a - so a1 will change - cuz the same address - and 1 address for 1 value only
    a = 1000;
    cout<<a1<<endl;
}