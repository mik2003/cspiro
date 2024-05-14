#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
    int size;
    int n_rows;
    int n_cols;
    float **array;
} Mat2D;

float **arr2d_malloc(int n_rows, int n_cols);
Mat2D mat2d_new(int n_rows, int n_cols);
Mat2D mat2d_empty();
int mat2d_free(Mat2D *m);
int mat2d_print(Mat2D *m);

Mat2D mat2d_mul(Mat2D *m1, Mat2D *m2);

#endif /* MATRIX_H */
