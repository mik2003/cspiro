#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include <stdbool.h>

int gcd(int a, int b);                                                          // Greatest common divisor
int lcm(int a, int b);                                                          // Least common multiple
bool is_rationally_related(float a, float b, int *numerator, int *denominator); // Rational relationship

#endif /* UTIL_H */