#include <iostream>
#include "matrix.h"
using namespace std;

int main(){
    Matrix A(2,5);
    Matrix B(2,5,3.14);
    Matrix C(B);
    
    A.random();
    A.print("A");
    B.print("B");

    // get the value of an entry
    cout<<"A(1,1) =";
}
// A and B out-of-scope --> delete