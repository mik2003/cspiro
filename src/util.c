#include "util.h"

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
    const float tolerance = 1e-9;

    if (fabs(a) < tolerance || fabs(b) < tolerance)
    {
        return false;
    }

    float ratio = a / b;
    float multiplier = 1.0;

    while (fabs(round(ratio * multiplier) - ratio * multiplier) > tolerance)
    {
        multiplier += 1.0;
        if (multiplier > 1e6)
        {
            return false;
        }
    }

    *numerator = round(ratio * multiplier);
    *denominator = round(multiplier);
    return gcd(*numerator, *denominator) == 1;
}

bool check_rational_relations_and_period(int n, float *speed, float *period)
{
    int lcm_denom = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int num, denom;
            if (!is_rationally_related(speed[i], speed[j], &num, &denom))
            {
                return false;
            }
            lcm_denom = lcm(num, denom);
        }
    }

    *period = 2 * M_PI * lcm_denom / arr_max(n, speed);
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
