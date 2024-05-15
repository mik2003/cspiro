#include "matrix.h"
#include "spirograph.h"
#include "svg.h"
#include "transform.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    printf("Welcome to cspiro, a command-line tool for making spirographs.\n\n");
    printf("The mathematical basis of the program follows the definitions laid out in the Spirograph Wikipedia page (https://en.wikipedia.org/wiki/Spirograph#Mathematical_basis)\n");
    printf("Some important definitions:\n");
    printf("C_o : Fixed outer circle.\n");
    printf("C_i : Smaller inner circle that rolls inside C_o without slipping.\n");
    printf("R : Radius of C_o.\n");
    printf("r : Radius of C_i.\n");
    printf("A : Location of the drawing head. Physically, this should be within C_i.\n");
    printf("rho : Distance from A to center of C_i.\n");
    printf("l : Ratio between rho and r. Physically must follow 0<l<1, but mathematically can exceed these bounds. Negative values will result in equivalent spirographs. Values larger than 1 will exceed the size of the output SVG.\n");
    printf("k : Ratio between r and R. Must follow 0<k<1. In order for the spirograph to be periodic (thus not eventually be just a filled disk), this value must be a rational fraction, thus numerator and denominator are input seperatly as integers.\n\n");

    float l;
    int k_n, k_d, precision, size;
    int valid_input = 0;

    while (!valid_input)
    {
        printf("Enter the value of l: ");
        if (scanf("%f", &l) != 1 || l <= 0)
        {
            printf("Invalid input. Please enter a positive number for l.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        printf("Enter the numerator of k: ");
        if (scanf("%d", &k_n) != 1 || k_n <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the numerator.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        printf("Enter the denominator of k: ");
        if (scanf("%d", &k_d) != 1 || k_d <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the denominator.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        printf("Enter the precision (points per full rotation of the spirograph): ");
        if (scanf("%d", &precision) != 1 || precision <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the precision.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        printf("Enter the size of the SVG image (px): ");
        if (scanf("%d", &size) != 1 || size <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the size.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        valid_input = 1; // All inputs are valid
    }

    clock_t start_time = clock();

    // Numerator of k fraction corresponds to the spirograph periodicity.
    float k = (float)k_n / k_d;

    Mat2D t = angles(0, k_n * 2 * M_PI, precision * k_n);
    Mat2D spiro_temp_0 = spirograph(l, k, &t);
    Mat2D spiro_temp_1 = translate_2d(&spiro_temp_0, 1, 1);
    Mat2D spiro = scale_2d(&spiro_temp_1, size / 2, size / 2);

    // Generate SVG path
    char *svg_path = generate_svg_path(spiro.array[0], spiro.array[1], spiro.n_cols);
    char filename[] = "./out/spiro.svg";
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

    clock_t end_time = clock();
    float execution_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.3f ms.\n", execution_time * 1000);

    return 0;
}
