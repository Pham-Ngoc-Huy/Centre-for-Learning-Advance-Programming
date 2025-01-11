#include <iostream>
#include "func_declared.h"
using namespace std;

extern double totalArea;  // forward declaration

int main ()
{
  double h = 5.0 , b = 2.0 ;
  double w = 3.0 ;
  double triArea , recArea ;
  triArea = areaTri(h, b);
  recArea = areaRec(w, h);
  totalArea = triArea + recArea ;

  cout << "Triangle area: " << triArea << endl ;
  cout << "Rectangle area: " << recArea << endl ;
  printTotal();
}