#ifndef CIRCLE_H
#define CIRCLE_H

#include "matrix.h"

/**
 * Circle type. Holds information about a construction circle for an epicycle.
 *
 * Members
 * -------
 * radius : float
 *     Radius of the circle.
 * speed : float
 *     Angular velocity of the circle [rad/s].
 * angle_i : float
 *     Initial angle of the circle [rad]. If this circle is the last one
 *     in the epicycle construction circles, the point on the circumference
 *     will be the drawing point, otherwise it will be the point
 *     on which the center of the next circle is located.
 * angles : Mat2D *
 *     Pointer to a list of the range of angles [rad].
 * local_x : Mat2D *
 *     Pointer to a list of x positions with respect to the circle center.
 * local_y : Mat2D *
 *     Pointer to a list of y positions with respect to the circle center.
 */
typedef struct Circle
{
    float radius;
    float speed;
    float angle_i;
    Mat2D *angle;
    Mat2D *local_x;
    Mat2D *local_y;
} Circle;

/**
 * Function to initialize a Circle.
 * Memory is allocated dynamically and must be freed with `circle_free`.
 *
 * Parameters
 * ----------
 * radius : float
 *     Radius of the circle.
 * speed : float
 *     Angular velocity of the circle [rad/s].
 * angle_i : float
 *     Initial angle of the circle [rad].
 *
 * Returns
 * -------
 * Circle *
 *     Pointer to the initialized Circle.
 */
Circle *circle_init(float radius, float speed, float angle_i);

/**
 * Function to free Circle memory.
 *
 * Parameters
 * ----------
 * c : Circle *
 *     Pointer to the Circle to be freed.
 *
 * Returns
 * -------
 * int
 *     0 if free is successful.
 */
int circle_free(Circle *c);

/******************/
/* Circle METHODS */
/******************/
/*
 * Circle methods act directly on the input Circle instance.
 */

/**
 * Function to update Circle with new time range.
 * Calls `circle_update_angle`,
 * `circle_update_local_x`, `circle_update_local_y`.
 *
 * Parameters
 * ----------
 * c : Circle *
 *     Pointer to the circle to be updated.
 * t : Mat2D *
 *     Pointer to the new time range.
 *
 * Returns
 * -------
 * int
 *     0  if update is successful;
 *     -1 otherwise.
 */
int circle_update(Circle *c, Mat2D *t);

/**
 * Function to update Circle angle array with new time range.
 *
 * Parameters
 * ----------
 * c : Circle *
 *     Pointer to the circle to be updated.
 * t : Mat2D *
 *     Pointer to the new time range.
 *
 * Returns
 * -------
 * int
 *     0  if update is successful;
 *     -1 otherwise.
 */
int circle_update_angle(Circle *c, Mat2D *t);

/**
 * Function to update Circle local_x array.
 *
 * Parameters
 * ----------
 * c : Circle *
 *     Pointer to the circle to be updated.
 *
 * Returns
 * -------
 * int
 *     0  if update is successful;
 *     -1 otherwise.
 */
int circle_update_local_x(Circle *c);

/**
 * Function to update Circle local_y array.
 *
 * Parameters
 * ----------
 * c : Circle *
 *     Pointer to the circle to be updated.
 *
 * Returns
 * -------
 * int
 *     0  if update is successful;
 *     -1 otherwise.
 */
int circle_update_local_y(Circle *c);

#endif /* CIRCLE_H */
