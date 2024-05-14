#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n = 4;
    int m = 3;

    Mat2D mat1 = mat2d_new(n, m);
    Mat2D mat2 = mat2d_new(n, m);
    Mat2D mat_out;

    // Assign values to m1 and m2
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            mat1.array[i][j] = i * 3 + j + 1;
            mat2.array[i][j] = i * 3 + j + 1;
        }
    }
    mat_out = mat2d_transpose(&mat1);
    mat2d_print(&mat1);
    printf("\n");
    mat2d_print(&mat_out);

    mat2d_free(&mat1);
    mat2d_free(&mat2);
    mat2d_free(&mat_out);

    return 0;
}
