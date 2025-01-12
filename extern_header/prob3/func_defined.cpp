#include "func_declared.h"

double totalArea = 0.0;   // definition

double areaTri ( const double& h, const double& b) {
  return 0.5 * h * b;
}

double areaRec ( const double& w, const double& h) {
  return w * h;
}

void printTotal() {
	cout << " The total area  = " << totalArea << endl;
}