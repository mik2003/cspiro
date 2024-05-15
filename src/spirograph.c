#include "matrix.h"

#include <math.h>
#include <stdio.h>

Mat2D angles(float ti, float tf, int n)
{
    Mat2D out = mat2d_empty();
    out.size = n + 1;
    out.n_rows = 1;
    out.n_cols = n + 1;
    out.array = arr2d_malloc(1, n + 1);

    int i;
    float step = (tf - ti) / n;
    for (i = 0; i < n + 1; i++)
    {
        out.array[0][i] = ti + i * step;
    }

    return out;
}

Mat2D spirograph(float l, float k, Mat2D *t)
{
    Mat2D out = mat2d_empty();
    if (t->n_rows != 1)
    {
        return out;
    }

    Mat2D sint = mat2d_sin(t);
    Mat2D cost = mat2d_cos(t);

    float omk = 1 - k;
    float lk = l * k;
    float omkdk = omk / k;

    Mat2D omkdkt = mat2d_multiply_float(t, omkdk);
    Mat2D sinomkdkt = mat2d_sin(&omkdkt);
    Mat2D cosomkdkt = mat2d_cos(&omkdkt);

    Mat2D omksint = mat2d_multiply_float(&sint, omk);
    Mat2D omkcost = mat2d_multiply_float(&cost, omk);

    Mat2D lksinomkdkt = mat2d_multiply_float(&sinomkdkt, lk);
    Mat2D lkcosomkdkt = mat2d_multiply_float(&cosomkdkt, lk);

    Mat2D x = mat2d_add(&omkcost, &lkcosomkdkt);
    Mat2D y = mat2d_subtract(&omksint, &lksinomkdkt);

    Mat2D xy = mat2d_stack(&x, &y, 0);
    Mat2D o = mat2d_ones(1, t->n_cols);

    out = mat2d_stack(&xy, &o, 0);

    // printf("sint =\n");
    // mat2d_print(&sint);
    // printf("cost =\n");
    // mat2d_print(&cost);
    // printf("omk = %f\n", omk);
    // printf("lk = %f\n", lk);
    // printf("omkdk = %f\n", omkdk);
    // printf("omkdkt =\n");
    // mat2d_print(&omkdkt);
    // printf("sinomkdkt =\n");
    // mat2d_print(&sinomkdkt);
    // printf("cosomkdkt =\n");
    // mat2d_print(&cosomkdkt);
    // printf("omksint =\n");
    // mat2d_print(&omksint);
    // printf("omkcost =\n");
    // mat2d_print(&omkcost);
    // printf("lksinomkdkt =\n");
    // mat2d_print(&lksinomkdkt);
    // printf("lkcosomkdkt =\n");
    // mat2d_print(&lkcosomkdkt);
    // printf("x =\n");
    // mat2d_print(&x);
    // printf("y =\n");
    // mat2d_print(&y);

    mat2d_free(&sint);
    mat2d_free(&cost);
    mat2d_free(&omkdkt);
    mat2d_free(&sinomkdkt);
    mat2d_free(&cosomkdkt);
    mat2d_free(&omksint);
    mat2d_free(&omkcost);
    mat2d_free(&lksinomkdkt);
    mat2d_free(&lkcosomkdkt);
    mat2d_free(&x);
    mat2d_free(&y);
    mat2d_free(&xy);
    mat2d_free(&o);

    return out;
}
