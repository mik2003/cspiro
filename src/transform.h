#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Mat2D *translate_2d(Mat2D *mat, float tx, float ty);
Mat2D *rotate_2d(Mat2D *mat, float r);
Mat2D *scale_2d(Mat2D *mat, float sx, float sy);
Mat2D *rotate_p_2d(Mat2D *mat, float r, float px, float py);
Mat2D *scale_p_2d(Mat2D *mat, float sx, float sy, float px, float py);

#endif /* TRANSFORM_H */
