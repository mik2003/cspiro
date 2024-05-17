#include "epicycle.h"

Epicycle *epicycle_init()
{
    Epicycle *out = (Epicycle *)malloc(sizeof(Epicycle));
    if (out == NULL)
    {
        return NULL;
    }

    out->n = 0;
    out->circles = NULL;
    out->x = NULL;
    out->y = NULL;
    out->t = NULL;

    return out;
}

int epicycle_assign_t(Epicycle *e, Mat2D *t)
{
    if (e == NULL || t == NULL)
    {
        return -1;
    }

    e->t = t;
    Mat2D *x = mat2d_zeros(1, t->n_cols);
    Mat2D *y = mat2d_zeros(1, t->n_cols);

    e->x = x;
    e->y = y;

    return 0;
}

int epicycle_free(Epicycle *e)
{
    if (e == NULL)
    {
        return -1;
    }

    int freed_circles = epicycle_free_circles(e);
    mat2d_free(e->x);
    mat2d_free(e->y);
    mat2d_free(e->t);
    free(e);

    return freed_circles;
}

int epicycle_free_circles(Epicycle *e)
{
    if (e->circles == NULL)
    {
        return -1;
    }

    int i;
    for (i = 0; i < e->n; i++)
    {
        circle_free(&e->circles[i]);
    }
    free(e->circles);

    return 0;
}

int epicycle_add_new_circle(Epicycle *e, float radius, float speed, float angle_i)
{
    Circle *c = circle_init(radius, speed, angle_i);
    int circle_updated = circle_update(c, e->t);
    int circle_added = epicycle_add_existing_circle(e, c);
    int updated = epicycle_update_xy(e);

    return circle_updated != 0 ? circle_updated
           : circle_added != 0 ? circle_added
           : updated != 0      ? updated
                               : 0;
}

int epicycle_add_new_circles(Epicycle *e, int n, float *radius, float *speed, float *angle_i)
{
    int i;
    for (i = 0; i < n; i++)
    {
        epicycle_add_new_circle(e, radius[i], speed[i], angle_i[i]);
    }

    return 0;
}

int epicycle_add_existing_circle(Epicycle *e, Circle *c)
{
    epicycle_add_existing_circles(e, 1, c);

    return 0;
}

int epicycle_add_existing_circles(Epicycle *e, int m, Circle *circles)
{
    e->n += m;
    e->circles = (Circle *)realloc(e->circles, e->n * sizeof(Circle));
    if (e->circles == NULL)
    {
        return -1;
    }

    int i;
    for (i = 0; i < m; i++)
    {
        e->circles[e->n - m + i] = circles[i];
    }

    return 0;
}

int epicycle_update_xy(Epicycle *e)
{
    int m = e->t->n_rows;
    int n = e->t->n_cols;
    Mat2D *x = mat2d_zeros(m, n);
    Mat2D *y = mat2d_zeros(m, n);
    Mat2D *x_temp;
    Mat2D *y_temp;

    int i;
    for (i = 0; i < e->n; i++)
    {
        // Update each circle with the new time
        circle_update(&e->circles[i], e->t);

        // Add the local x and y of the current circle to x and y
        x_temp = mat2d_add(x, e->circles[i].local_x);
        y_temp = mat2d_add(y, e->circles[i].local_y);

        // Free the old x and y matrices
        mat2d_free(x);
        mat2d_free(y);

        // Assign the new matrices to x and y
        x = x_temp;
        y = y_temp;
    }

    int freed_x = mat2d_free(e->x);
    int freed_y = mat2d_free(e->y);
    if (freed_x != 0 || freed_y != 0)
    {
        return -1;
    }
    e->x = x;
    e->y = y;

    return 0;
}

Mat2D *epicycle(Epicycle *e)
{
    if (e == NULL || e->x == NULL || e->y == NULL || e->t == NULL)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();
    Mat2D *xy = mat2d_stack(e->x, e->y, 0);
    Mat2D *o = mat2d_ones(1, e->t->size);

    out = mat2d_stack(xy, o, 0);

    mat2d_free(xy);
    mat2d_free(o);

    return out;
}
