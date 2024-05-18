#include "util.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

bool is_rationally_related(float a, float b, int *numerator, int *denominator)
{
    const float tolerance = 1e-12;

    if (fabs(a) < tolerance || fabs(b) < tolerance)
    {
        return false;
    }

    float ratio = a / b;
    int num, denom;
    float closest_ratio;
    float best_diff = FLT_MAX;

    for (denom = 1; denom <= 1e6; ++denom)
    {
        num = round(ratio * denom);
        closest_ratio = (float)num / denom;
        float diff = fabs(closest_ratio - ratio);

        if (diff < tolerance)
        {
            *numerator = num;
            *denominator = denom;
            return gcd(num, denom) == 1;
        }

        if (diff < best_diff)
        {
            best_diff = diff;
            *numerator = num;
            *denominator = denom;
        }
    }

    return false;
}

bool check_rational_relations_and_period(int n, float *speed, float *period)
{
    int overall_lcm = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int num, denom;
            if (!is_rationally_related(speed[i], speed[j], &num, &denom))
            {
                return false;
            }
            overall_lcm = lcm(overall_lcm, denom);
        }
    }

    *period = 2 * M_PI * overall_lcm / arr_max(n, speed);
    return true;
}

float arr_max(int n, float *arr)
{
    float m = -INFINITY;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }

    return m;
}

float arr_min(int n, float *arr)
{
    float m = INFINITY;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < m)
        {
            m = arr[i];
        }
    }

    return m;
}
