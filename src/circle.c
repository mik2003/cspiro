#include "circle.h"

#include <stdlib.h>
#include <math.h>

Circle *circle_init(float radius, float speed, float angle_i)
{
    Circle *out = (Circle *)malloc(sizeof(Circle));
    if (out == NULL)
    {
        return NULL;
    }

    // Initialize circle properties
    out->speed = speed;
    out->radius = radius;
    out->angle_i = angle_i;
    out->angle = NULL;
    out->local_x = NULL;
    out->local_y = NULL;

    return out;
}

int circle_free(Circle *c)
{
    free(c->angle);
    free(c->local_x);
    free(c->local_y);
    free(c);

    return 0;
}

int circle_update(Circle *c, Mat2D *t)
{
    // Check for invalid input
    if (c == NULL || t == NULL || t->n_rows != 1)
        return -1;

    // Update angle, local_x, and local_y
    int update_angle = circle_update_angle(c, t);
    int update_local_x = circle_update_local_x(c);
    int update_local_y = circle_update_local_y(c);

    // Check if any update function failed
    if (update_angle != 0 ||
        update_local_x != 0 ||
        update_local_y != 0)
    {
        return update_angle != 0 ? update_angle : update_local_x != 0 ? update_local_x
                                                                      : update_local_y;
    }

    // Return success if all updates were successful
    return 0;
}

int circle_update_angle(Circle *c, Mat2D *t)
{
    // Check for invalid input
    if (c == NULL)
        return -1;

    // Update angle
    Mat2D *relative_angle = mat2d_multiply_float(t, c->speed);
    Mat2D *absolute_angle = mat2d_add_float(relative_angle, c->angle_i);

    c->angle = absolute_angle;

    mat2d_free(relative_angle);

    // Return success
    return 0;
}

int circle_update_local_x(Circle *c)
{
    // Check for invalid input
    if (c == NULL)
        return -1;

    // Update local_x
    Mat2D *cos_angle = mat2d_cos(c->angle);
    Mat2D *rcos_angle = mat2d_multiply_float(cos_angle, c->radius);

    c->local_x = rcos_angle;

    mat2d_free(cos_angle);

    // Return success
    return 0;
}

int circle_update_local_y(Circle *c)
{
    // Check for invalid input
    if (c == NULL)
        return -1;

    // Update local_x
    Mat2D *sin_angle = mat2d_sin(c->angle);
    Mat2D *rsin_angle = mat2d_multiply_float(sin_angle, c->radius);

    c->local_y = rsin_angle;

    mat2d_free(sin_angle);

    // Return success
    return 0;
}
