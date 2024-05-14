#include "matrix.h"
#include "spirograph.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    // Numerator of k fraction corresponds to the spirograph periodicity.
    float l = 1.0;
    int k_n = 1;
    int k_d = 2;
    float k = (float)k_n / k_d;
    int precision = 12;

    printf("l = %f\n", l);
    printf("k = %f\n", k);

    Mat2D t = angles(0, k_n * 2 * M_PI, precision * k_n);
    Mat2D spiro = spirograph(l, k, &t);

    printf("t =\n");
    mat2d_print(&t);
    printf("spiro =\n");
    mat2d_print(&spiro);

    mat2d_free(&t);
    mat2d_free(&spiro);

    return 0;
}
