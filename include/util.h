#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

int gcd(int a, int b);                                                          // Greatest common divisor
int lcm(int a, int b);                                                          // Least common multiple
bool is_rationally_related(float a, float b, int *numerator, int *denominator); // Rational relationship

bool check_rational_relations_and_period(int n, float *speed, float *period);

float arr_max(int n, float *arr);
float arr_min(int n, float *arr);

#endif /* UTIL_H */