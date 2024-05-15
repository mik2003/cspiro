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
    int k_n = 13;
    int k_d = 37;
    float k = (float)k_n / k_d;
    int precision = 120;
    int size = 500;

    Mat2D t = angles(0, k_n * 2 * M_PI, precision * k_n);
    Mat2D spiro_temp_0 = spirograph(l, k, &t);
    Mat2D spiro_temp_1 = translate_2d(&spiro_temp_0, 1, 1);
    Mat2D spiro = scale_2d(&spiro_temp_1, size / 2, size / 2);

    // Generate SVG path
    char *svg_path = generate_svg_path(spiro.array[0], spiro.array[1], spiro.n_cols);
    char filename[] = "./out/test.svg";
    int result = generate_svg(filename, svg_path, size);
    if (result == 0)
    {
        printf("SVG file \"%s\" generated successfully.\n", filename);
    }
    else
    {
        printf("Failed to generate SVG file \"%s\".\n", filename);
    }
    free(svg_path);

    mat2d_free(&t);
    mat2d_free(&spiro_temp_0);
    mat2d_free(&spiro_temp_1);
    mat2d_free(&spiro);

    return 0;
}
