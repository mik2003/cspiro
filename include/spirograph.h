#ifndef SPIROGRAPH_H
#define SPIROGRAPH_H

#include "matrix.h"

/**
 * Function to calculate a range of angles.
 * Calls `mat2d_range`.
 *
 * Parameters
 * ----------
 * ti : float
 *     Starting angle of the range (included).
 * tf : float
 *     Ending angle of the range (included).
 * n : int
 *     Steps in the range (output will have `n + 1` points).
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix (will be of shape `1` by `n + 1`).
 * NULL
 *     If memory allocation failed.
 */
Mat2D *angles(float ti, float tf, int n);

/**
 * Function to calculate a spirograph.
 *
 * Parameters
 * ----------
 * l : float
 *     Ratio between rho an r (see README for definitions).
 * k : float
 *     Ratio between r and R (see README for definitions).
 * t : Mat2D *
 *     Pointer to the range of angles over which to calculate the spirograph.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the spirograph matrix.
 * NULL
 *     If memory allocation failed or wrong t shape.
 */
Mat2D *spirograph(float l, float k, Mat2D *t);

#endif /* SPIROGRAPH_H */
