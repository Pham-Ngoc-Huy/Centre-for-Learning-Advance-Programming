// programming tip: do not define in a header file
// --> move all definition to func_defined.cpp

#ifndef _FUNC_DECLARED_HEADER_
#define _FUNC_DECLARED_HEADER_

#include <iostream>
using namespace std;

double areaTri(const double& h, const double& b);
double areaRec(const double& w, const double& h);
void printTotal();


#endif