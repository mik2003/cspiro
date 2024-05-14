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

int mat2d_free(Mat2D *mat)
{
    int i;
    for (i = 0; i < mat->n_rows; i++)
    {
        free(mat->array[i]);
    }
    free(mat->array);
    return 0;
}

int mat2d_print(Mat2D *mat)
{
    int i;
    int j;
    for (i = 0; i < mat->n_rows; i++)
    {
        for (j = 0; j < mat->n_cols; j++)
        {
            printf("%8.2f", mat->array[i][j]);
        }
        printf("\n");
    }
    return 0;
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

Mat2D mat2d_new(int n_rows, int n_cols)
{
    return mat2d_zeros(n_rows, n_cols);
}

Mat2D mat2d_zeros(int n_rows, int n_cols)
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

Mat2D mat2d_ones(int n_rows, int n_cols)
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
        // Initialize all elements to one
        for (int i = 0; i < n_rows; ++i)
        {
            for (int j = 0; j < n_cols; ++j)
            {
                out.array[i][j] = 1.0f;
            }
        }
    }

    return out;
}

Mat2D mat2d_copy(Mat2D *mat)
{
    Mat2D out;

    int m = mat->n_rows;
    int n = mat->n_cols;

    out.size = mat->size;
    out.n_rows = m;
    out.n_cols = n;
    out.array = arr2d_malloc(m, n);

    int i;
    int j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            out.array[i][j] = mat->array[i][j];
        }
    }

    return out;
}

Mat2D mat2d_stack(Mat2D *mat1, Mat2D *mat2, int axis)
{
    Mat2D out;
    int m;
    int n;
    int p;
    int i;
    int j;
    switch (axis)
    {
    case 0:
        if (mat1->n_cols != mat2->n_cols)
        {
            out = mat2d_empty();
            break;
        }
        m = mat1->n_rows;
        n = mat1->n_cols;
        p = mat2->n_rows;

        out.size = mat1->size + mat2->size;
        out.n_rows = m + p;
        out.n_cols = n;
        out.array = arr2d_malloc(m + p, n);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                out.array[i][j] = mat1->array[i][j];
            }
        }
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < n; j++)
            {
                out.array[m + i][j] = mat1->array[i][j];
            }
        }
        break;

    case 1:
        if (mat1->n_rows != mat2->n_rows)
        {
            out = mat2d_empty();
            break;
        }
        m = mat1->n_rows;
        n = mat1->n_cols;
        p = mat2->n_cols;

        out.size = mat1->size + mat2->size;
        out.n_rows = m;
        out.n_cols = n + p;
        out.array = arr2d_malloc(m, n + p);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                out.array[i][j] = mat1->array[i][j];
            }
            for (j = 0; j < p; j++)
            {
                out.array[i][n + j] = mat2->array[i][j];
            }
        }
        break;

    default:
        out = mat2d_empty();
        break;
    }

    return out;
}

Mat2D mat2d_transpose(Mat2D *mat)
{
    Mat2D out;

    int m = mat->n_cols;
    int n = mat->n_rows;

    out.size = mat->size;
    out.n_rows = m;
    out.n_cols = n;
    out.array = arr2d_malloc(m, n);

    int i;
    int j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            out.array[i][j] = mat->array[j][i];
        }
    }

    return out;
}

Mat2D mat2d_add_float(Mat2D *mat, float f)
{
    Mat2D out = mat2d_copy(mat);

    int i;
    int j;
    for (i = 0; i < mat->n_rows; i++)
    {
        for (j = 0; j < mat->n_cols; j++)
        {
            out.array[i][j] += f;
        }
    }

    return out;
}

Mat2D mat2d_subtract_float(Mat2D *mat, float f)
{
    Mat2D out = mat2d_copy(mat);

    int i;
    int j;
    for (i = 0; i < mat->n_rows; i++)
    {
        for (j = 0; j < mat->n_cols; j++)
        {
            out.array[i][j] -= f;
        }
    }

    return out;
}

Mat2D mat2d_multiply_float(Mat2D *mat, float f)
{
    Mat2D out = mat2d_copy(mat);

    int i;
    int j;
    for (i = 0; i < mat->n_rows; i++)
    {
        for (j = 0; j < mat->n_cols; j++)
        {
            out.array[i][j] *= f;
        }
    }

    return out;
}

Mat2D mat2d_divide_float(Mat2D *mat, float f)
{
    Mat2D out = mat2d_copy(mat);

    int i;
    int j;
    for (i = 0; i < mat->n_rows; i++)
    {
        for (j = 0; j < mat->n_cols; j++)
        {
            out.array[i][j] /= f;
        }
    }

    return out;
}

Mat2D mat2d_multiply(Mat2D *mat1, Mat2D *mat2)
{
    Mat2D out;
    // Wrong matrices shapes
    if (mat1->n_cols != mat2->n_rows)
    {
        out = mat2d_empty();
        return out;
    }
    int m = mat1->n_rows;
    int n = mat1->n_cols;
    int p = mat2->n_cols;
    out.size = m * p;
    out.n_rows = m;
    out.n_cols = p;
    // Allocate memory for the array
    out.array = arr2d_malloc(m, p);
    if (out.array == NULL)
    {
        out = mat2d_empty();
        return out;
    }

    int i;
    int j;
    int k;
    float sum;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += mat1->array[i][k] * mat2->array[k][j];
            }
            out.array[i][j] = sum;
        }
    }

    return out;
}
