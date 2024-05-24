#include "test_helpers.h"
#include "matrix.h"

void test_matrix_shape1();
void test_matrix_shape2();

void test_matrix_shape1()
{
    Mat2D *a = mat2d_zeros(3, 3);
    Mat2D *b = mat2d_zeros(2, 2);
    ASSERT_MATRIX_EQUAL(a, b);
    mat2d_free(a);
    mat2d_free(b);
}

void test_matrix_shape2()
{
    Mat2D *a = mat2d_zeros(3, 3);
    ASSERT_MATRIX_EQUAL(a, a);
    mat2d_free(a);
}

int main()
{
    test_matrix_shape1();
    test_matrix_shape2();
    return 0;
}
