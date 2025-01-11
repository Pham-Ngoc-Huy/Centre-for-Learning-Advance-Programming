#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 1;
    int *c = &a;
    if (a == b)
    {
        cout<<"option1"<<endl;
        cout<<a<<endl;
        cout<<b<<endl;
    }
    else{
        cout<<"option2"<<endl;
    }
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<&c<<endl;
} 
