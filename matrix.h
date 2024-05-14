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
int mat2d_free(Mat2D *mat);
int mat2d_print(Mat2D *mat);

Mat2D mat2d_stack(Mat2D *mat1, Mat2D *mat2, int axis);
Mat2D mat2d_transpose(Mat2D *mat);

Mat2D mat2d_multiply(Mat2D *mat1, Mat2D *mat2);

#endif /* MATRIX_H */
