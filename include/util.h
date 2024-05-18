#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

/**
 * Function to calculate the greatest common divisor.
 *
 * Parameters
 * ----------
 * a : int
 *     First number.
 * b : int
 *     Second number.
 *
 * Returns
 * -------
 * int
 *     Greatest common divisor.
 */
int gcd(int a, int b);

/**
 * Function to calculate the least common multiple.
 *
 * Parameters
 * ----------
 * a : int
 *     First number.
 * b : int
 *     Second number.
 *
 * Returns
 * -------
 * int
 *     Least common multiple.
 */
int lcm(int a, int b);

/**
 * Function to calculate if two numbers are rationally related
 * (within a certain precision due to floating points).
 *
 * Parameters
 * ----------
 * a : int
 *     First number.
 * b : int
 *     Second number.
 * numerator : int *
 *     Pointer to the numerator of the rational relation,
 *     will be set if there exists a rational relation.
 * denominator : int *
 *     Pointer to the denominator of the rational relation,
 *     will be set if there exists a rational relation.
 *
 * Returns
 * -------
 * bool
 *     Wether numbers are rationally related.
 */
bool is_rationally_related(float a, float b, int *numerator, int *denominator);

/**
 * Function to check rational relationship for each pair of numbers in
 * input array and calculate period if rational relationship exists.
 * (See README for more information on epicycle periodicity)
 *
 * Parameters
 * ----------
 * n : int
 *     Number of circles.
 * speed : float *
 *     Pointer to list of angular velocities of circles.
 * period : float *
 *     Pointer to the period value,
 *     will be set if rational relationship exists.
 *
 * Returns
 * -------
 * bool
 *     Wether numbers are rationally related.
 */
bool check_rational_relations_and_period(int n, float *speed, float *period);

/**
 * Function to calculate the maximum value in an array.
 *
 * Parameters
 * ----------
 * n : int
 *     Number of elements in the array.
 * arr : float *
 *     Pointer to the array.
 *
 * Returns
 * -------
 * float
 *     Maximum value in the array.
 */
float arr_max(int n, float *arr);

/**
 * Function to calculate the minimum value in an array.
 *
 * Parameters
 * ----------
 * n : int
 *     Number of elements in the array.
 * arr : float *
 *     Pointer to the array.
 *
 * Returns
 * -------
 * float
 *     Minimum value in the array.
 */
float arr_min(int n, float *arr);

#endif /* UTIL_H */