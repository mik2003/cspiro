#include "matrix.h"
#include "spirograph.h"
#include "svg.h"
#include "transform.h"
#include "epicycle.h"
#include "cli.h"
#include "util.h"
#include "argparse.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc,     // Number of strings in array argv
         char *argv[], // Array of command-line argument strings
         char **envp)  // Array of environment variable strings
{
    // General variables
    int mode, cli_mode, precision, size;
    // Spirograph variables
    float l;
    int k_n, k_d;
    // Epicycle variables
    float period;
    int n;

    int arr_size = 1; // !(FIX) Temporary maximum array size
    float *radius = (float *)malloc(arr_size * sizeof(float));
    float *speed = (float *)malloc(arr_size * sizeof(float));
    float *angle_i = (float *)malloc(arr_size * sizeof(float));
    if (radius == NULL || speed == NULL || angle_i == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    int parsed = argparse(argc,
                          argv,
                          envp,
                          &mode, &cli_mode, &precision, &size,
                          &l, &k_n, &k_d,
                          &period, &n, &radius, &speed, &angle_i);

    if (parsed != 0)
    {
        printf("Argument parsing failed.\n");
        free(radius);
        free(speed);
        free(angle_i);
        return -1;
    }

    if (cli_mode)
    {
        description();
        mode = select_mode();
    }
    if (mode == 0)
    {
        if (cli_mode)
        {
            description_spirograph();

            l = input_spirograph_l();
            k_n = input_spirograph_k_n();
            k_d = input_spirograph_k_d();
            precision = input_spirograph_precision();
            size = input_svg_size();
        }

        clock_t start_time = clock();

        // Numerator of k fraction corresponds to the spirograph periodicity.
        float k = (float)k_n / k_d;

        Mat2D *t = angles(0, k_n * 2 * M_PI, precision * k_n);
        Mat2D *spiro_temp_0 = spirograph(l, k, t);
        Mat2D *spiro_temp_1 = translate_2d(spiro_temp_0, 1, 1);
        Mat2D *spiro = scale_2d(spiro_temp_1, size / 2, size / 2);

        // Generate SVG path
        char *svg_path = generate_svg_path(spiro->array[0], spiro->array[1], spiro->n_cols);
        char filename[] = "./out/spiro.svg";
        int result = generate_svg(filename, svg_path, size);
        output_svg_result(result, filename);
        free(svg_path);

        mat2d_free(t);
        mat2d_free(spiro_temp_0);
        mat2d_free(spiro_temp_1);
        mat2d_free(spiro);

        output_execution_time(start_time);
    }
    else if (mode == 1)
    {
        if (cli_mode)
        {
            description_epicycle();

            n = input_epicycle_n();

            radius = realloc(radius, n * sizeof(float));
            speed = realloc(speed, n * sizeof(float));
            angle_i = realloc(angle_i, n * sizeof(float));
            if (radius == NULL || speed == NULL || angle_i == NULL)
            {
                free(radius);
                free(speed);
                free(angle_i);
                return -1;
            }

            period = input_epicycle_data(n, radius, speed, angle_i);
            size = input_svg_size();
        }

        float t_0 = 0.0;          // [s]
        float t_f = t_0 + period; // [s]
        int steps = round(100 * period * arr_max(n, speed));

        clock_t start_time = clock();

        Epicycle *e = epicycle_init();
        Mat2D *time = mat2d_range(t_0, t_f, steps); // Times [s]
        epicycle_assign_t(e, time);
        epicycle_add_new_circles(e, n, radius, speed, angle_i);

        Mat2D *ec_temp = epicycle(e);
        if (ec_temp->array == NULL)
        {
            printf("Invalid epicycle.\n");
        }
        Mat2D *ec = translate_2d(ec_temp, size / 2, size / 2);

        // Generate SVG path
        char *svg_path = generate_svg_path(ec->array[0], ec->array[1], steps);
        char filename[] = "./out/epicycle.svg";
        int result = generate_svg(filename, svg_path, size);
        output_svg_result(result, filename);
        free(svg_path);

        epicycle_free(e);
        mat2d_free(ec);

        output_execution_time(start_time);
    }

    free(radius);
    free(speed);
    free(angle_i);

    return 0;
}
