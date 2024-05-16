#include "circle.h"

#include <stdlib.h>
#include <math.h>

Circle circle_init()
{
    Circle c;

    // Initialize circle properties
    c.speed = 0.0f;
    c.radius = 0.0f;
    c.angle_i = 0.0f;
    c.angle = 0.0f;
    c.local_x = 0.0f;
    c.local_y = 0.0f;

    return c;
}

int circle_update(Circle *c, float t)
{
    // Check for invalid input
    if (c == NULL || t < 0.0f)
        return CIRCLE_ERROR_INVALID_INPUT;

    // Update angle, local_x, and local_y
    int update_angle = circle_update_angle(c, t);
    int update_local_x = circle_update_local_x(c);
    int update_local_y = circle_update_local_y(c);

    // Check if any update function failed
    if (update_angle != CIRCLE_SUCCESS ||
        update_local_x != CIRCLE_SUCCESS ||
        update_local_y != CIRCLE_SUCCESS)
    {
        return update_angle != CIRCLE_SUCCESS ? update_angle : update_local_x != CIRCLE_SUCCESS ? update_local_x
                                                                                                : update_local_y;
    }

    // Return success if all updates were successful
    return CIRCLE_SUCCESS;
}

int circle_update_angle(Circle *c, float t)
{
    // Check for invalid input
    if (c == NULL)
        return CIRCLE_ERROR_INVALID_INPUT;

    // Update angle
    c->angle = c->angle_i + c->speed * t;

    // Return success
    return CIRCLE_SUCCESS;
}

int circle_update_local_x(Circle *c)
{
    // Check for invalid input
    if (c == NULL)
        return CIRCLE_ERROR_INVALID_INPUT;

    // Update local_x
    c->local_x = c->radius * cos(c->angle);

    // Return success
    return CIRCLE_SUCCESS;
}

int circle_update_local_y(Circle *c)
{
    // Check for invalid input
    if (c == NULL)
        return CIRCLE_ERROR_INVALID_INPUT;

    // Update local_y
    c->local_y = c->radius * sin(c->angle);

    // Return success
    return CIRCLE_SUCCESS;
}
