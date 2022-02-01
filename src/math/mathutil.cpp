#include "mathutil.h"
#include <math.h>

bool aboutEquals(double n1, double n2) {
	return fabs(n1-n2) < defaultEpsilon;
}

bool aboutEquals(double n1, double n2, double epsilon) {
	return fabs(n1 - n2) < epsilon;
}
