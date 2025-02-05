#include <iostream>

using namespace std;

int main(){


    // REFERENCE AND VARIABLES
    // int a(10);
    // int &b = a;
    // // b = 12.0;
    // cout <<a<<endl;
    // cout <<sizeof(a)<<endl;
    // cout <<&a<<endl;
    // cout <<&b<<endl;
    // cout <<b<<endl;
    // cout <<a<<endl;

    // int &d = b;
    // double e = b;
    // b = 10;
    // cout << a <<"/n"<<&a<<endl;
    // cout << b <<"/n"<<&b<<endl;

    // cout << d <<"/n"<<&d<<endl;
    // cout << e <<"/n"<<&e<<endl;

        // POINTER
    // int a = 12;
    // int *b = &a;

    // cout << sizeof(int*) << endl;
    // cout << b<< endl; //value of the pointer is address 
    // cout << &b<<endl; //address of the pointer
    // // =============== which mean pointer has 2 address - value and address
    // cout << *b <<endl; //value of the address


        // POINTER I

//     int a = 12;
//     int *b = &a;
//     int **c;
//     c = &b;

//     cout << *b <<endl; // => value of pointer b is address of a, => value of address of a is 12
//     cout << *c << "--" << **c <<endl;

//     *b =120;
//     cout<<a<<"--"<<&a<<endl;

//     /* which mean - can understand the pointer** c is the address of the pointer b
//     , and the value of the address of the pointer b is the address of a
//     , and the value of the address of a is 12 */


//     /* the option of the pointer c: (**c) - 
//     - first is its address
//     - second is the value of the address of the pointer c is the address of the pointer b
//     - third is the address
//     */
//    cout <<&a<<endl;
//    cout <<&b<<endl;
//    cout <<&c<<endl;
//    cout <<&*c << "--" << &c <<"--"<< *c << "--"<< **c<< "--" << &**c <<endl;
//    /* Conclusion: the address of the pointer c is the address of the pointer b
//     , the value of the address of the pointer c is the address of the pointer b
//     , the value of the pointer c is the address of a
//         => contain 3 addresses - 1 value 
//         => &*c: provide the slot for the address of *c
//         => &c: provide the slot for the address of c
//         => *c: provide the slot for the address of a
//         => **c: provide the slot for the value of a
//         => &**c: provide the slot for the address of a

//    */

//     return 0;
 //================================================//
 // POINTER I
// int a1 = 12;
// int a2 = 120;
// int *b;
 
// b = &a1;
// cout << *b <<endl;
// cout << b <<endl;
// cout << &b <<endl;


// b = &a2;
// cout << *b <<endl;
// cout << b <<endl;
// cout << &b <<endl;

// ===============================================//
// POINTER II

int a = 12;
int *b = &a;
int **c;
c = &b;
cout << &a<< endl;
a = 100;
// cout << &a<< endl;
cout << c<<endl;
cout << *c <<endl;
cout << &c <<endl;
cout << **c <<endl;
}