#ifndef EPICYCLE_H
#define EPICYCLE_H

#include "circle.h"
#include "matrix.h"

/**
 * Epicycle type. Holds information about the epicycle and its construction.
 *
 * Members
 * -------
 * n : int
 *     Number of construction circles.
 * circles : Circle *
 *     Pointer to a list of Circle instances.
 * x : Mat2D *
 *     Pointer to the matrix containing x positions with respect to the origin.
 * y : Mat2D *
 *     Pointer to the matrix containing y positions with respect to the origin.
 * t : Mat2D *
 *     Pointer to the matrix containing the time range values [s].
 */
typedef struct Epicycle
{
    int n;
    Circle *circles;
    Mat2D *x;
    Mat2D *y;
    Mat2D *t;
} Epicycle;

/**********************/
/* Epicycle UTILITIES */
/**********************/

/**
 * Function to initialize Epicycle.
 * Internal matrix pointers are set to NULL.
 * Memory is dynamically allocated, thus needs to be freed
 * using `epicycle_free`.
 *
 * Returns
 * -------
 * Epicycle *
 *     Pointer to the initialized Epicycle.
 * NULL
 *     If memory allocation failed.
 */
Epicycle *epicycle_init();

/**
 * Function to assign new time matrix to Epicycle.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the Epicycle to change.
 * t : Mat2D *
 *     Pointer to the new time matrix.
 *
 * Returns
 * -------
 * int
 *     0  if assignment is successful,
 *     -1 otherwise.
 */
int epicycle_assign_t(Epicycle *e, Mat2D *t);

/**
 * Function to free Epicycle memory.
 * Calls `epicycle_free_circles` and frees all internal arrays.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle to be freed.
 *
 * Returns
 * -------
 * int
 *     0  if memory is freed successfully,
 *     -1 otherwise.
 */
int epicycle_free(Epicycle *e);

/**
 * Function to free Epicycle circles memory.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle whose circles have to be freed.
 *
 * Returns
 * -------
 * int
 *     0  if memory is freed successfully,
 *     -1 otherwise.
 */
int epicycle_free_circles(Epicycle *e);

/********************/
/* Epicycle METHODS */
/********************/
/*
 * All Epicycle methods act directly on the input Epicycle.
 */

/**
 * Function to add a new construction circle to the Epicycle.
 * Calls `epicycle_add_existing_circle`, `epicycle_update_xy`.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle to which circle needs to be added.
 * radius : float
 *     Radius of the circle.
 * speed : float
 *     Angular velocity of the circle [rad/s].
 * angle_i : float
 *     Initial angle of the circle [rad].
 *
 * Returns
 * -------
 * int
 *     0  if circle is added successfully,
 *     -1 otherwise.
 */
int epicycle_add_new_circle(Epicycle *e, float radius, float speed, float angle_i);

/**
 * Function to add a set of new construction circles to the Epicycle.
 * Calls `epicycle_add_new_circle`.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle to which circle needs to be added.
 * n : int
 *     Number of circles to be added.
 * radius : float *
 *     Pointer to the array of radii of the circles.
 * speed : float *
 *     Pointer to the array of angular velocities of the circles [rad/s].
 * angle_i : float *
 *     Pointer to the array of initial angles of the circles [rad].
 *
 * Returns
 * -------
 * int
 *     0  if circles are added successfully,
 *     -1 otherwise.
 */
int epicycle_add_new_circles(Epicycle *e, int n, float *radius, float *speed, float *angle_i);

/**
 * Function to add an existing construction circle to the Epicycle.
 * Calls `epicycle_add_existing_circles`.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle to which circle needs to be added.
 * c : Circle *
 *     Pointer to the Circle to be added.
 *
 * Returns
 * -------
 * int
 *     0  if circle is added successfully,
 *     -1 otherwise.
 */
int epicycle_add_existing_circle(Epicycle *e, Circle *c);

/**
 * Function to add a set of new construction circles to the Epicycle.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the epicycle to which circle needs to be added.
 * m : int
 *     Number of circles to be added.
 * c : Circle *
 *     Pointer to the array of Circles to be added.
 *
 * Returns
 * -------
 * int
 *     0  if circles are added successfully,
 *     -1 otherwise.
 */
int epicycle_add_existing_circles(Epicycle *e, int m, Circle *c);

/**
 * Function to update x and y internal arrays of the Epicycle.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the Epicycle to be updated.
 *
 * Returns
 * -------
 * int
 *     0  if Epicycle is updated successfully,
 *     -1 otherwise.
 */
int epicycle_update_xy(Epicycle *e);

/**
 * Function to extract the epicycle from the struct.
 *
 * Parameters
 * ----------
 * e : Epicycle *
 *     Pointer to the Epicycle to be extracted.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the extracted epicycle matrix.
 */
Mat2D *epicycle(Epicycle *e);

#endif /* EPICYCLE_H */