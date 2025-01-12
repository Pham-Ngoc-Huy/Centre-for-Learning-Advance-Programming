#ifndef _FUNC_DEFINED_HEADER_
#define _FUNC_DEFINED_HEADER_

#include "func_declared.h"  // include declared.h one time

double areaTri(const double& h, const double& b) {
	return 0.5 * h * b;
}

double areaRec(const double& w, const double& h) {
	return w * h;
}

#endif // !_FUNC_DEFINED_HEADER_


