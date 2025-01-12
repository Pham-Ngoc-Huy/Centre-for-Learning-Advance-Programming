#ifndef _FUNCTION_DEFINED_
#define _FUNCTION_DEFINED_
#include "func_declared.h"  // include declared.h one time

double areaTri(const double& h, const double& b) {
	return 0.5 * h * b;
}

double areaRec(const double& w, const double& h) {
	return w * h;
}
#endif


