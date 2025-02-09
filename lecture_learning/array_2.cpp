#include <iostream>
using namespace std;

int main(){
    int v[4]= {1,2,3,4};
    for (int i=0; i<4;++i) {
        cout <<v[i]<<endl;
    }
    cout << "v ="<<endl;
    int* p = v; // p is free pointer - with p = p +1 which mean the address + 4 byte to move to the next address in the array
    cout <<"*p = "<< *p <<endl;
    p = p +1;
    cout <<"*p = "<< *p <<endl;

}