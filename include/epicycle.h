#ifndef EPICYCLE_H
#define EPICYCLE_H

#include "circle.h"
#include "matrix.h"

typedef struct Epicycle
{
    int n;           // Number of circles
    Circle *circles; // List of circles
    Mat2D *x;        // x positions wrt first circle center
    Mat2D *y;        // y positions wrt first circle center
    Mat2D *t;        // Times [s]
} Epicycle;

Epicycle *epicycle_init();
int epicycle_assign_t(Epicycle *e, Mat2D *t);
int epicycle_free(Epicycle *e);
int epicycle_free_circles(Epicycle *e);

int epicycle_add_new_circle(Epicycle *e, float radius, float speed, float angle_i);
int epicycle_add_new_circles(Epicycle *e, int n, float *radius, float *speed, float *angle_i);
int epicycle_add_existing_circle(Epicycle *e, Circle *c);
int epicycle_add_existing_circles(Epicycle *e, int m, Circle *c);

int epicycle_update_xy(Epicycle *e);

Mat2D *epicycle(Epicycle *e);

#endif /* EPICYCLE_H */