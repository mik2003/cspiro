#ifndef CIRCLE_H
#define CIRCLE_H

// Error codes
#define CIRCLE_SUCCESS 0
#define CIRCLE_ERROR_INVALID_INPUT -1

typedef struct
{
    float radius;  // Radius
    float speed;   // Angular velocity [rad/s]
    float angle_i; // Initial angle [rad]
    float angle;   // Current angle [rad]
    float local_x; // Current x position wrt circle center
    float local_y; // Current y position wrt circle center
} Circle;

Circle circle_init();

int circle_update(Circle *c, float t);
int circle_update_angle(Circle *c, float t);
int circle_update_local_x(Circle *c);
int circle_update_local_y(Circle *c);

#endif /* CIRCLE_H */
