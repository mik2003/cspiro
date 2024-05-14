#include "matrix.h"
#include "spirograph.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    Mat2D t = angles(0, 2 * M_PI, 12);
    Mat2D spiro = spirograph(1, 0.5, &t);

    printf("t =\n");
    mat2d_print(&t);
    printf("spiro =\n");
    mat2d_print(&spiro);

    mat2d_free(&t);
    mat2d_free(&spiro);

    return 0;
}
