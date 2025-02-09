#include <iostream>
#include <cmath>
using namespace std;

// forward declaration with keyword extern
extern int a;
extern void add(const int& a, const int& b, int& c);
extern const double pi;

// Linkable -> not linkable -> local var
        //  -> linkable -> global var
int main(){
    cout << "a = "<< a <<endl;
    int a = 10, b = 20, c= 0;
    add(a,b,c);
    cout << "pi = "<< pi << endl;
}

