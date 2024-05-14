#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    Mat2D m1 = mat2d_new(3, 3);
    Mat2D m2 = mat2d_new(3, 3);
    Mat2D mat = mat2d_mul(&m1, &m2);

    // Assign values to m1 and m2
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m1.array[i][j] = i * 3 + j + 1;
            m2.array[i][j] = i * 3 + j + 1;
        }
    }
    mat = mat2d_mul(&m1, &m2);
    mat2d_print(&mat);

    mat2d_free(&m1);
    mat2d_free(&m2);
    mat2d_free(&mat);

    return 0;
}
