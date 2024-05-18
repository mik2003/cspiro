#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

/*
 * Module for 2-dimensional transformations of Mat2D instances.
 * All input matrices have x-values on the first row
 * y-values on the second row and all ones on the third row
 * since homogeneous coordinates are used for the transformations.
 *
 * All the transformations DO NOT act on the original matrix.
 * They allocate memory for a new matrix and return its pointer.
 * Thus both the original and the new matrix must be freed using `mat2d_free`.
 */

/**
 * Function to translate a series of 2d points.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be translated (must be 3 by n).
 * tx : float
 *     Translation in x-direction.
 * ty : float
 *     Translation in y-direction.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the translated matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *translate_2d(Mat2D *mat, float tx, float ty);

/**
 * Function to rotate a series of 2d points (with pivot at the origin).
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be rotated (must be 3 by n).
 * r : float
 *     Rotation angle in radians.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the rotated matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *rotate_2d(Mat2D *mat, float r);

/**
 * Function to scale a series of 2d points (with pivot at the origin).
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be scaled (must be 3 by n).
 * sx : float
 *     Scaling factor in x-direction.
 * sy : float
 *     Scaling factor in y-direction.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the scaled matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *scale_2d(Mat2D *mat, float sx, float sy);

/**
 * Function to rotate a series of 2d points (with arbitrary pivot point).
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be rotated (must be 3 by n).
 * r : float
 *     Rotation angle in radians.
 * px : float
 *     x-coordinate of the pivot point.
 * py : float
 *     y-coordinate of the pivot point.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the rotated matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *rotate_p_2d(Mat2D *mat, float r, float px, float py);

/**
 * Function to scale a series of 2d points (with arbitrary pivot point).
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be scaled (must be 3 by n).
 * sx : float
 *     Scaling factor in x-direction.
 * sy : float
 *     Scaling factor in y-direction.
 * px : float
 *     x-coordinate of the pivot point.
 * py : float
 *     y-coordinate of the pivot point.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the scaled matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *scale_p_2d(Mat2D *mat, float sx, float sy, float px, float py);

#endif /* TRANSFORM_H */
