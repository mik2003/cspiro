#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

float **arr2d_malloc(int n_rows, int n_cols)
{
    float **arr = (float **)malloc(n_rows * sizeof(float *));
    if (arr == NULL)
        return NULL;

    for (int i = 0; i < n_rows; ++i)
    {
        arr[i] = (float *)malloc(n_cols * sizeof(float));
        if (arr[i] == NULL)
        {
            // Allocation failed
            for (int j = 0; j < i; ++j)
                free(arr[j]);
            free(arr);
            return NULL;
        }
    }
    return arr;
}

Mat2D mat2d_new(int n_rows, int n_cols)
{
    Mat2D out;
    out.n_rows = n_rows;
    out.n_cols = n_cols;

    // Allocate memory for the array
    out.array = arr2d_malloc(n_rows, n_cols);
    if (out.array == NULL)
    {
        out = mat2d_empty();
        return out;
    }
    else
    {
        // Initialize all elements to zero
        for (int i = 0; i < n_rows; ++i)
        {
            for (int j = 0; j < n_cols; ++j)
            {
                out.array[i][j] = 0.0f;
            }
        }
    }

    return out;
}

Mat2D mat2d_empty()
{
    Mat2D out;
    out.size = 0;
    out.n_rows = 0;
    out.n_cols = 0;
    out.array = NULL;

    return out;
}

int mat2d_free(Mat2D *m)
{
    int i;
    for (i = 0; i < m->n_rows; i++)
    {
        free(m->array[i]);
    }
    free(m->array);
    return 0;
}

int mat2d_print(Mat2D *m)
{
    int i;
    int j;
    for (i = 0; i < m->n_rows; i++)
    {
        for (j = 0; j < m->n_cols; j++)
        {
            printf("%8.2f", m->array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

Mat2D mat2d_mul(Mat2D *m1, Mat2D *m2)
{
    Mat2D out;
    // Wrong matrices shapes
    if (m1->n_cols != m2->n_rows)
    {
        out = mat2d_empty();
        return out;
    }
    int n = m1->n_rows;
    int m = m1->n_cols;
    int p = m2->n_cols;
    out.size = n * p;
    out.n_rows = n;
    out.n_cols = p;
    // Allocate memory for the array
    out.array = arr2d_malloc(n, p);
    if (out.array == NULL)
    {
        out = mat2d_empty();
        return out;
    }

    int i;
    int j;
    int k;
    float sum;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            sum = 0;
            for (k = 0; k < m; k++)
            {
                sum += m1->array[i][k] * m2->array[k][j];
            }
            out.array[i][j] = sum;
        }
    }

    return out;
}
