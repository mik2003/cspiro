#ifndef MATRIX_H
#define MATRIX_H

/**
 * Mat2D type. Holds a 2-dimensional m by n matrix.
 *
 * Members
 * -------
 * size : int
 *     The number of elements in the matrix (equivalent to m*n).
 * n_rows : int
 *     The number m of rows in the matrix.
 * n_cols : int
 *     The number n of columns in the matrix.
 * array : float **
 *     The 2-dimensional array corresponding to the matrix
 *     represented via a pointer that points to a list of pointers
 *     to the row arrays of the matrix.
 *     Elements can be accessed as a 2-dimensional array
 *     `array[i][j]` for row `i` and column `j`.
 */
typedef struct Mat2D
{
    int size;
    int n_rows;
    int n_cols;
    float **array;
} Mat2D;

/**
 * Function to allocate memory for a 2-dimensional array.
 *
 * Parameters
 * ----------
 * n_rows : int
 *     Number of rows in the array.
 * n_cols : int
 *     Number of columns in the array.
 *
 * Returns
 * -------
 * float **
 *     Pointer to the 2-dimensional array
 * NULL
 *     If memory allocation failed.
 *     If a partial allocation was achieved, the allocated memory is freed.
 */
float **arr2d_malloc(int n_rows, int n_cols);

/*******************/
/* Mat2D UTILITIES */
/*******************/

/**
 * Function to free the memory of the Mat2D type.
 * First, the memory of the array member is freed;
 * then, the memory of the Mat2D struct itself is freed.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to a 2-dimensional matrix to be freed.
 *
 * Returns
 * -------
 * int
 *     Returns 0 if free is successful.
 */
int mat2d_free(Mat2D *mat);

/**
 * Function to print a representation of Mat2D.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to a 2-dimensional matrix to be printed.
 *
 * Returns
 * -------
 * int
 *     Returns 0 if print is successful.
 */
int mat2d_print(Mat2D *mat);

/**********************/
/* Mat2D INITIALIZERS */
/**********************/

/**
 * Function to initialize an empty Mat2D instance.
 * This dynamically allocates memory for the struct,
 * thus needs to be freed with `mat2d_free`.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the initialized matrix.
 */
Mat2D *mat2d_empty();

/**
 * Function to initialize a new Mat2D instance.
 * Calls `mat2d_zeros`.
 *
 * Parameters
 * ----------
 * n_rows : int
 *     Number of rows in the matrix.
 * n_cols : int
 *     Number of columns in the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the initialized matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *mat2d_new(int n_rows, int n_cols);

/**
 * Function to initialize a zeroed instance of Mat2D.
 *
 * Parameters
 * ----------
 * n_rows : int
 *     Number of rows in the matrix.
 * n_cols : int
 *     Number of columns in the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the initialized matrix.
 * NULL
 *     If memory allocation failed.
 */
Mat2D *mat2d_zeros(int n_rows, int n_cols);

/**
 * Function to initialize an instance of Mat2D
 * with all elements set to one.
 *
 * Parameters
 * ----------
 * n_rows : int
 *     Number of rows in the matrix.
 * n_cols : int
 *     Number of columns in the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the initialized matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_ones(int n_rows, int n_cols);

/*****************/
/* Mat2D METHODS */
/*****************/
/*
 * All the methods DO NOT act on the original matrix.
 * They allocate memory for a new matrix and return its pointer.
 * Thus both the original and the new matrix must be freed using `mat2d_free`.
 */

/**
 * Function to make a deep copy of a Mat2D instance.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be copied.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the copied matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_copy(Mat2D *mat);

/**
 * Function to stack two matrices together.
 *
 * Parameters
 * ----------
 * mat1 : Mat2D *
 *     Pointer to the first matrix.
 * mat2 : Mat2D *
 *     Pointer to the second matrix.
 * axis : int
 *     Axis along which to stack the matrices.
 *     0 -> rows will be appended, the matrices
 *     must have the same number of columns.
 *     1 -> columns will be appended, the matrices
 *     must have the same number of rows.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the stacked matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_stack(Mat2D *mat1, Mat2D *mat2, int axis);

/**
 * Function to transpose a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the matrix to be transposed.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the transposed matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_transpose(Mat2D *mat);

/**
 * Function to add a float to each element in a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 * f : float
 *     Float to be added to the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed (calls `mat2d_copy`).
 */
Mat2D *mat2d_add_float(Mat2D *mat, float f);

/**
 * Function to subtract a float from each element in a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 * f : float
 *     Float to be subtracted from the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed (calls `mat2d_copy`).
 */
Mat2D *mat2d_subtract_float(Mat2D *mat, float f);

/**
 * Function to multiply a float to each element in a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 * f : float
 *     Float to be added to the matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed (calls `mat2d_copy`).
 */
Mat2D *mat2d_multiply_float(Mat2D *mat, float f);

/**
 * Function to divide each element in a matrix by a float.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 * f : float
 *     Float to to divide the matrix by.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed (calls `mat2d_copy`).
 */
Mat2D *mat2d_divide_float(Mat2D *mat, float f);

/**
 * Function to elementwise add two matrices together.
 *
 * Parameters
 * ----------
 * mat1 : Mat2D *
 *     Pointer to the first matrix.
 * mat2 : Mat2D *
 *     Pointer to the second matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_add(Mat2D *mat1, Mat2D *mat2);

/**
 * Function to elementwise subtract one matrix from another.
 *
 * Parameters
 * ----------
 * mat1 : Mat2D *
 *     Pointer to the first matrix (to be subtracted from).
 * mat2 : Mat2D *
 *     Pointer to the second matrix (to subtract).
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_subtract(Mat2D *mat1, Mat2D *mat2);

/**
 * Function to perform matrix multiplication between two matrices.
 *
 * Parameters
 * ----------
 * mat1 : Mat2D *
 *     Pointer to the first matrix.
 * mat2 : Mat2D *
 *     Pointer to the second matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_multiply(Mat2D *mat1, Mat2D *mat2);

/**
 * Function to elementwise multiply two matrices.
 *
 * Parameters
 * ----------
 * mat1 : Mat2D *
 *     Pointer to the first matrix.
 * mat2 : Mat2D *
 *     Pointer to the second matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_multiply_elementwise(Mat2D *mat1, Mat2D *mat2);

/**
 * Function to elementwise calculate the sine of a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_sin(Mat2D *mat);

/**
 * Function to elementwise calculate the cosine of a matrix.
 *
 * Parameters
 * ----------
 * mat : Mat2D *
 *     Pointer to the input matrix.
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix.
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_cos(Mat2D *mat);

/**
 * Function to calculate a range of values.
 *
 * Parameters
 * ----------
 * start : float
 *     Starting point of the range (included).
 * end : float
 *     Ending point of the range (included).
 * steps : int
 *     Steps in the range (output will have `steps + 1` points).
 *
 * Returns
 * -------
 * Mat2D *
 *     Pointer to the output matrix (will be of shape `1` by `steps + 1`).
 * NULL
 *     If memory allocation failed.
 *     Partially allocated memory is automatically freed.
 */
Mat2D *mat2d_range(float start, float end, int steps);

#endif /* MATRIX_H */
