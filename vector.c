#include "vector.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Vector vec_new(int size)
{
    Vector out;
    out.size = size;
    out.arr = (float *)malloc(size * sizeof(float));
    if (out.arr == NULL)
    {
        out.size = 0;
    }
    else
    {
        memset(out.arr, 0, size * sizeof(float));
    }
    return out;
}

int vec_addf(Vector *v, float f)
{
    int i;
    for (i = 0; i < v->size; i++)
    {
        v->arr[i] += f;
        printf("%d:\t%f\n", i, v->arr[i]);
    }
    return 0;
}

int vec_subf(Vector *v, float f)
{
    int i;
    for (i = 0; i < v->size; i++)
    {
        v->arr[i] -= f;
        printf("%d:\t%f\n", i, v->arr[i]);
    }
    return 0;
}