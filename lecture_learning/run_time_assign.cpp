#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    // assign the value of a during compile time
    a = 10;
    
    // assign the value of a during run time
    // --> cin
    cout << "Input the value of:"<<endl;
    cin>>a;
    // cout<<&a<<endl;
    cout << "Updated a ="<< a <<endl;
}