#include "MathUtil.h"
#include <math.h>

bool aboutEquals(double n1, double n2) {
	return abs(n1-n2) < defaultEpsilon;
}

bool aboutEquals(double n1, double n2, double epsilon) {
	return abs(n1 - n2) < epsilon;
}
