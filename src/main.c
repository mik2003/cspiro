#include "matrix.h"
#include "spirograph.h"
#include "svg.h"
#include "transform.h"
#include "epicycle.h"
#include "cli.h"

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    description();

    int mode = select_mode();
    if (mode == 0)
    {
        description_spirograph();

        float l = input_spirograph_l();
        int k_n = input_spirograph_k_n();
        int k_d = input_spirograph_k_d();
        int precision = input_spirograph_precision();
        int size = input_svg_size();

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
        description_epicycle();

        int n = input_epicycle_n();

        float *radius = (float *)malloc(n * sizeof(float));
        float *speed = (float *)malloc(n * sizeof(float));
        float *angle_i = (float *)malloc(n * sizeof(float));

        float period = input_epicycle_data(n, radius, speed, angle_i);

        clock_t start_time = clock();

        int svg_size = input_svg_size(); // [px]
        float t_0 = 0.0;                 // [s]
        float t_f = t_0 + period;        // [s]
        int steps = round(100 * period * arr_max(n, speed));

        Epicycle *e = epicycle_init();
        Mat2D *time = mat2d_range(t_0, t_f, steps); // Times [s]
        epicycle_assign_t(e, time);
        epicycle_add_new_circles(e, n, radius, speed, angle_i);

        Mat2D *ec_temp = epicycle(e);
        if (ec_temp->array == NULL)
        {
            printf("Invalid epicycle.\n");
        }
        Mat2D *ec = translate_2d(ec_temp, svg_size / 2, svg_size / 2);

        // Generate SVG path
        char *svg_path = generate_svg_path(ec->array[0], ec->array[1], steps);
        char filename[] = "./out/epicycle.svg";
        int result = generate_svg(filename, svg_path, svg_size);
        output_svg_result(result, filename);
        free(svg_path);

        free(radius);
        free(speed);
        free(angle_i);

        epicycle_free(e);
        mat2d_free(ec);

        output_execution_time(start_time);
    }

    return 0;
}
