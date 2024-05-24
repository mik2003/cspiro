#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <math.h> // Include other necessary headers
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Define macros or utility functions if needed
// Example: a macro to check floating point equality
#define TEST_ASSERT_FLOAT_EQUAL(expected, actual, delta) \
    TEST_ASSERT_TRUE(fabs((expected) - (actual)) < (delta))

// Utility macro for test assertions
#define ASSERT(condition, message)                                                    \
    do                                                                                \
    {                                                                                 \
        if (!(condition))                                                             \
        {                                                                             \
            fprintf(stderr, "Assertion failed: %s, function %s, file %s, line %d.\n", \
                    message, __func__, __FILE__, __LINE__);                           \
            exit(EXIT_FAILURE);                                                       \
        }                                                                             \
    } while (0)

#define FLOAT_TOLERANCE 1e-5

#define ASSERT_MATRIX_EQUAL(mat1, mat2)                                                \
    do                                                                                 \
    {                                                                                  \
        if ((mat1)->n_rows != (mat2)->n_rows || (mat1)->n_cols != (mat2)->n_cols)      \
        {                                                                              \
            fprintf(stderr, "Matrix size mismatch: (%d, %d) vs (%d, %d)\n",            \
                    (mat1)->n_rows, (mat1)->n_cols, (mat2)->n_rows, (mat2)->n_cols);   \
            exit(EXIT_FAILURE);                                                        \
        }                                                                              \
        for (int i = 0; i < (mat1)->n_rows; i++)                                       \
        {                                                                              \
            for (int j = 0; j < (mat1)->n_cols; j++)                                   \
            {                                                                          \
                if (fabs((mat1)->array[i][j] - (mat2)->array[i][j]) > FLOAT_TOLERANCE) \
                {                                                                      \
                    fprintf(stderr, "Matrix mismatch at element (%d, %d): %f vs %f\n", \
                            i, j, (mat1)->array[i][j], (mat2)->array[i][j]);           \
                    exit(EXIT_FAILURE);                                                \
                }                                                                      \
            }                                                                          \
        }                                                                              \
    } while (0)

#endif /* TEST_HELPERS_H */
