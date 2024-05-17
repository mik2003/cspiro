#include "transform.h"

Mat2D *translate_2d(Mat2D *mat, float tx, float ty)
{
    if (mat->n_rows != 3)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();

    Mat2D *translation_matrix = mat2d_zeros(3, 3);
    translation_matrix->array[0][0] = 1;
    translation_matrix->array[0][1] = 0;
    translation_matrix->array[0][2] = tx;
    translation_matrix->array[1][0] = 0;
    translation_matrix->array[1][1] = 1;
    translation_matrix->array[1][2] = ty;
    translation_matrix->array[2][0] = 0;
    translation_matrix->array[2][1] = 0;
    translation_matrix->array[2][2] = 1;

    Mat2D *temp = mat2d_multiply(translation_matrix, mat);
    out = mat2d_copy(temp);

    mat2d_free(translation_matrix);
    mat2d_free(temp);

    return out;
}

Mat2D *rotate_2d(Mat2D *mat, float r)
{
    if (mat->n_rows != 3)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();

    Mat2D *rotation_matrix = mat2d_zeros(3, 3);
    rotation_matrix->array[0][0] = cos(r);
    rotation_matrix->array[0][1] = -sin(r);
    rotation_matrix->array[0][2] = 0;
    rotation_matrix->array[1][0] = sin(r);
    rotation_matrix->array[1][1] = cos(r);
    rotation_matrix->array[1][2] = 0;
    rotation_matrix->array[2][0] = 0;
    rotation_matrix->array[2][1] = 0;
    rotation_matrix->array[2][2] = 1;

    Mat2D *temp = mat2d_multiply(rotation_matrix, mat);
    out = mat2d_copy(temp);

    mat2d_free(rotation_matrix);
    mat2d_free(temp);

    return out;
}

Mat2D *scale_2d(Mat2D *mat, float sx, float sy)
{
    if (mat->n_rows != 3)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();

    Mat2D *scale_matrix = mat2d_zeros(3, 3);
    scale_matrix->array[0][0] = sx;
    scale_matrix->array[0][1] = 0;
    scale_matrix->array[0][2] = 0;
    scale_matrix->array[1][0] = 0;
    scale_matrix->array[1][1] = sy;
    scale_matrix->array[1][2] = 0;
    scale_matrix->array[2][0] = 0;
    scale_matrix->array[2][1] = 0;
    scale_matrix->array[2][2] = 1;

    Mat2D *temp = mat2d_multiply(scale_matrix, mat);
    out = mat2d_copy(temp);

    mat2d_free(scale_matrix);
    mat2d_free(temp);

    return out;
}

Mat2D *rotate_p_2d(Mat2D *mat, float r, float px, float py)
{
    if (mat->n_rows != 3)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();
    out->size = mat->size;
    out->n_rows = mat->n_rows;
    out->n_cols = mat->n_cols;

    Mat2D *translate_temp = translate_2d(mat, -px, -py);
    Mat2D *rotate_temp = rotate_2d(translate_temp, r);
    out = translate_2d(rotate_temp, px, py);

    mat2d_free(translate_temp);
    mat2d_free(rotate_temp);

    return out;
}

Mat2D *scale_p_2d(Mat2D *mat, float sx, float sy, float px, float py)
{
    if (mat->n_rows != 3)
    {
        return NULL;
    }

    Mat2D *out = mat2d_empty();
    out->size = mat->size;
    out->n_rows = mat->n_rows;
    out->n_cols = mat->n_cols;

    Mat2D *translate_temp = translate_2d(mat, -px, -py);
    Mat2D *scale_temp = scale_2d(translate_temp, sx, sy);
    out = translate_2d(scale_temp, px, py);

    mat2d_free(translate_temp);
    mat2d_free(scale_temp);

    return out;
}
