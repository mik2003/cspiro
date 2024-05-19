#include "cli.h"
#include "util.h"

#include <stdio.h>
#include <time.h>

void description()
{
    printf("Welcome to cspiro, a command-line tool for making spirographs.\n\n");
    printf("The mathematical basis of the program follows the definitions laid out in the Spirograph Wikipedia page (https://en.wikipedia.org/wiki/Spirograph#Mathematical_basis)\n");
    printf("There are two different drawing modes, spirograph and epicycle. An epicycle is a more general version of a spirograph and gives the user more control, its mathematical basis can be found on the Epicycle Wikipedia page (https://en.wikipedia.org/wiki/Deferent_and_epicycle#Mathematical_formalism).\n\n");
}

void description_spirograph()
{
    printf("Some important definitions:\n");
    printf("C_o : Fixed outer circle.\n");
    printf("C_i : Smaller inner circle that rolls inside C_o without slipping.\n");
    printf("R : Radius of C_o.\n");
    printf("r : Radius of C_i.\n");
    printf("A : Location of the drawing head. Physically, this should be within C_i.\n");
    printf("rho : Distance from A to center of C_i.\n");
    printf("l : Ratio between rho and r. Physically must follow 0<l<1, but mathematically can exceed these bounds. Negative values will result in equivalent spirographs. Values larger than 1 will exceed the size of the output SVG.\n");
    printf("k : Ratio between r and R. Must follow 0<k<1. In order for the spirograph to be periodic (thus not eventually be just a filled disk), this value must be a rational fraction, thus numerator and denominator are input seperatly as integers.\n\n");
}

void description_epicycle()
{
    printf("An epicycle is constructed from a set of circles, where the firs circle's center is fixed at the origin and each next circle is connected to a point on the previous circle's circumference. Each circle accepts three variables, the radius, the angular velocity, and the initial rotation.\n\n");
}

int select_mode()
{
    printf("Drawing modes\n");
    printf("0 : Spirograph\n");
    printf("1 : Epicycle\n");

    int mode;
    while (1)
    {
        printf("Choose drawing mode: ");
        if (scanf("%d", &mode) != 1 || (mode != 0 && mode != 1))
        {
            printf("Invalid mode. Please enter a valid mode.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            printf("\n");
            break;
        }
    }

    return mode;
}

float input_spirograph_l()
{
    float l;
    while (1)
    {
        printf("Enter the value of l: ");
        if (scanf("%f", &l) != 1 || l <= 0)
        {
            printf("Invalid input. Please enter a positive number for l.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }
    return l;
}

int input_spirograph_k_n()
{
    int k_n;
    while (1)
    {
        printf("Enter the numerator of k: ");
        if (scanf("%d", &k_n) != 1 || k_n <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the numerator.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }
    return k_n;
}

int input_spirograph_k_d()
{
    int k_d;
    while (1)
    {
        printf("Enter the denominator of k: ");
        if (scanf("%d", &k_d) != 1 || k_d <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the denominator.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }
    return k_d;
}

int input_epicycle_n()
{
    int n;
    while (1)
    {
        printf("Enter number of circles: ");
        if (scanf("%d", &n) != 1 || n <= 1)
        {
            printf("Invalid input. There must be at least two circles. Please enter a positive integer for the number of circles.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }

    return n;
}

float input_epicycle_data(int n, float *radius, float *speed, float *angle_i)
{
    float period;
    while (1)
    {
        int i = 0;
        float r, s, a;
        for (i = 0; i < n; i++)
        {
            // Input for radius
            while (1)
            {
                printf("Radius of circle %d: ", i + 1);
                if (scanf("%f", &r) != 1)
                {
                    printf("Invalid input. Please enter a number for the radius.\n");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }
                else
                {
                    radius[i] = r;
                    break; // Exit the loop if input is valid
                }
            }

            // Input for angular velocity
            while (1)
            {
                printf("Angular velocity of circle %d: ", i + 1);
                if (scanf("%f", &s) != 1)
                {
                    printf("Invalid input. Please enter a number for the angular velocity.\n");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }
                else
                {
                    speed[i] = s;
                    break; // Exit the loop if input is valid
                }
            }

            // Input for initial angle
            while (1)
            {
                printf("Initial angle of circle %d: ", i + 1);
                if (scanf("%f", &a) != 1)
                {
                    printf("Invalid input. Please enter a number for the initial angle.\n");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }
                else
                {
                    angle_i[i] = a;
                    break; // Exit the loop if input is valid
                }
            }
        }
        printf("\n");

        if (check_rational_relations_and_period(n, speed, &period))
        {
            printf("All angular velocities are rationally related.\n");
            printf("The period of the epicycle is: %f seconds\n\n", period);
            break;
        }
        else
        {
            printf("Some angular velocities are not rationally related. Input new values.\n\n");
        }
    }

    return period;
}

int input_curve_precision()
{
    int precision;
    while (1)
    {
        printf("Enter the precision (points per full rotation): ");
        if (scanf("%d", &precision) != 1 || precision <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the precision.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }
    return precision;
}

int input_svg_size()
{
    int size;
    while (1)
    {
        printf("Enter the size of the SVG image (px): ");
        if (scanf("%d", &size) != 1 || size <= 0)
        {
            printf("Invalid input. Please enter a positive integer for the size.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    }
    return size;
}

void output_svg_result(int result, char *filename)
{
    if (result == 0)
    {
        printf("SVG file \"%s\" generated successfully.\n", filename);
    }
    else
    {
        printf("Failed to generate SVG file \"%s\".\n", filename);
    }
    printf("\n");
}

void output_execution_time(clock_t start_time)
{
    clock_t end_time = clock();
    float execution_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.3f ms.\n", execution_time * 1000);
}
