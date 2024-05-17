#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H

#include <math.h>
#include <stdio.h>

#include "matrix.h"

Mat2D *angles(float ti, float tf, int n);
Mat2D *spirograph(float l, float k, Mat2D *t);

#endif /* SPIROGRAPH_H */
