#include <iostream>
using namespace std;

extern double x;
extern double y;
extern const double c;
extern void mult(const double& x, const double& c, double& y);

int main () {
   {
     double x;
     x = 100.0 ;
   }

   cout << "x = " << x << endl;
   mult (x, c);
   cout << "y = " << y << endl;
}