#ifndef CIRCLE_H
#define CIRCLE_H

// Error codes
#define CIRCLE_SUCCESS 0
#define CIRCLE_ERROR_INVALID_INPUT -1

#include "matrix.h"

#include <stdlib.h>
#include <math.h>

typedef struct
{
    float radius;   // Radius
    float speed;    // Angular velocity [rad/s]
    float angle_i;  // Initial angle [rad]
    Mat2D *angle;   // Angles [rad]
    Mat2D *local_x; // x positions wrt circle center
    Mat2D *local_y; // y positions wrt circle center
} Circle;

Circle *circle_init(float radius, float speed, float angle_i);
int circle_free(Circle *c);

int circle_update(Circle *c, Mat2D *t);
int circle_update_angle(Circle *c, Mat2D *t);
int circle_update_local_x(Circle *c);
int circle_update_local_y(Circle *c);

#endif /* CIRCLE_H */
