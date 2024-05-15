#include "matrix.h"
#include "spirograph.h"
#include "svg.h"
#include "transform.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    // Numerator of k fraction corresponds to the spirograph periodicity.
    float l = 1.0;
    int k_n = 1;
    int k_d = 3;
    float k = (float)k_n / k_d;
    int precision = 120;

    // printf("l = %f\n", l);
    // printf("k = %f\n", k);

    int size = 500;

    Mat2D t = angles(0, k_n * 2 * M_PI, precision * k_n);
    Mat2D spiro_temp_0 = spirograph(l, k, &t);
    Mat2D spiro_temp_1 = translate_2d(&spiro_temp_0, 1, 1);
    Mat2D spiro = scale_2d(&spiro_temp_1, size / 2, size / 2);

    // printf("t =\n");
    // mat2d_print(&t);
    // printf("spiro =\n");
    // mat2d_print(&spiro);

    // Generate SVG path
    char *svg_path = generate_svg_path(spiro.array[0], spiro.array[1], spiro.n_cols);
    generate_svg(svg_path, size);
    free(svg_path);

    mat2d_free(&t);
    mat2d_free(&spiro_temp_0);
    mat2d_free(&spiro_temp_1);
    mat2d_free(&spiro);

    // Mat2D test = mat2d_ones(3, 10);
    // mat2d_print(&test);
    // Mat2D temp = scale_2d(&test, M_PI, -2.9);
    // mat2d_print(&temp);

    return 0;
}
