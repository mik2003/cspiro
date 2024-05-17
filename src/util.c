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
    const float tolerance = 1e-6;

    if (fabs(a) < tolerance || fabs(b) < tolerance)
    {
        return false;
    }

    float ratio = a / b;
    float multiplier = 1.0;

    while (fabs(round(ratio * multiplier) - ratio * multiplier) > tolerance)
    {
        multiplier *= 10.0;
        if (multiplier > 1e6)
        {
            return false;
        }
    }

    *numerator = round(ratio * multiplier);
    *denominator = round(multiplier);
    return gcd(*numerator, *denominator) == 1;
}
