#ifndef EPICYCLE_H
#define EPICYCLE_H

#include "circle.h"

typedef struct
{
    int n;           // Number of circles
    Circle *circles; // List of circles
    float x;         // Current x position wrt first circle center
    float y;         // Current y position wrt first circle center
    float t;         // Current time [s]
} Epicycle;

Epicycle epicycle_init();
int epicycle_free(Epicycle *e);
int epicycle_free_circles(Epicycle *e);

int epicycle_add_new_circle(Epicycle *e, float radius, float speed, float angle_i);
int epicycle_add_existing_circle(Epicycle *e, Circle *c);
int epicycle_add_existing_circles(Epicycle *e, int m, Circle *c);

int epicycle_update(Epicycle *e);

#endif /* EPICYCLE_H */