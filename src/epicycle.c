#include "epicycle.h"
#include "circle.h"

#include <stdlib.h>

Epicycle epicycle_init()
{
    Epicycle e;

    e.n = 0;
    e.circles = NULL;
    e.x = 0.0f;
    e.y = 0.0f;
    e.t = 0.0f;

    return e;
}

int epicycle_free(Epicycle *e)
{
    if (e == NULL)
    {
        return -1;
    }
    int freed_circles = epicycle_free_circles(e);
    free(e);

    return freed_circles;
}

int epicycle_free_circles(Epicycle *e)
{
    if (e->circles == NULL)
    {
        return -1;
    }
    free(e->circles);

    return 0;
}

int epicycle_add_new_circle(Epicycle *e, float radius, float speed, float angle_i)
{
    Circle c = circle_init();
    c.radius = radius;
    c.speed = speed;
    c.angle_i = angle_i;
    int circle_updated = circle_update(&c, e->t);
    int circle_added = epicycle_add_existing_circle(e, &c);
    int updated = epicycle_update(e);

    return circle_updated != 0 ? circle_updated
           : circle_added != 0 ? circle_added
           : updated != 0      ? updated
                               : 0;
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

int epicycle_update(Epicycle *e)
{
    float x = 0.0f;
    float y = 0.0f;

    int i;
    for (i = 0; i < e->n; i++)
    {
        circle_update(&e->circles[i], e->t);
        x += e->circles[i].local_x;
        y += e->circles[i].local_y;
    }

    e->x = x;
    e->y = y;

    return 0;
}
