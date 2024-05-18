#ifndef SVG_H
#define SVG_H

/**
 * Function to generate svg path argument from array of points.
 *
 * Parameters
 * ----------
 * x : float *
 *     Pointer to an array of x-coordinates.
 * y : float *
 *     Pointer to an array of y-coordinates.
 * n : int
 *     Number of points in the path.
 *
 * Returns
 * -------
 * char *
 *     Pointer to the svg path argument string.
 * NULL
 *     If memory allocation failed or buffer overflow.
 */
char *generate_svg_path(float *x, float *y, int n);

/**
 * Function to generate svg and write to file.
 *
 * Parameters
 * ----------
 * filename : char *
 *     Pointer to the filename string.
 * svg_path : char *
 *     Pointer to the svg path argument string.
 * size : int
 *     Size of the SVG image in pixels. Both width and height are set.
 *
 * Returns
 * -------
 * int
 *     0  if successful;
 *     -1 if filename or svg_path is NULL;
 *     -2 if failed to open file.
 */
int generate_svg(const char *filename, char *svg_path, int size);

#endif /* SVG_H */