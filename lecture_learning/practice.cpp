#include <iostream>
using namespace std;

int main(){

int v[4] = { 1, 2, 3, 4 };
int* p1 = v;
cout<<v<<endl;
cout<<p1<<endl;
cout<<&v[0]<<endl;
int(*p2)[4] = &v;
cout<<*p2[4]<<endl;

cout << "v␣=␣" << v << ",␣ sizeof (v)␣=␣" << sizeof (v) << endl ;
cout << "*v␣=␣" << *v << ",␣ sizeof (*v)␣=␣" << sizeof (*v) << endl ; // size of*v mean that is 4 byte for *v[1]
cout << "p1␣=␣" << p1 << ",␣ sizeof (p1)␣=␣" << sizeof (p1) << endl ;
cout << "*p1␣=␣" << *p1 << ",␣ sizeof (* p1)␣=␣" << sizeof (* p1) << endl ;
cout << "p2␣=␣" << p2 << ",␣ sizeof (p2)␣=␣" << sizeof (p2) << endl ;
cout << "*p2␣=␣" << *p2 << ",␣ sizeof (* p2)␣=␣" << sizeof (* p2) << endl ;

// for (int i = 0; i < 4; ++i) {
// cout << "*p1␣=␣" << *p1 << ",␣";
// p1 ++;
// }
// cout << endl ;

// for (int i = 0; i < 4; ++i)
// cout << "(* p2 )[" << i << "]␣=␣" << (* p2 )[i] << ",␣";
// cout << endl ;

// p1 -= 2; *p1 = 50;
// (* p2 )[0] = 500 ;

// for (int i = 0; i < 4; ++i)
// cout << "v[" << i << "]␣=␣" << v[i] << ",␣";
// cout << endl ;

}