#include "svg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate SVG path string from x and y arrays
char *generate_svg_path(float *x, float *y, int n)
{
    char *path = (char *)malloc(n * 100 * sizeof(char)); // Assuming a maximum of 40 characters per point
    char temp[100];
    int len = snprintf(path, 100, "M%.6f,%.6f", x[0], y[0]); // Move to the first point
    if (len >= 100)
    {
        free(path);
        return NULL; // Error: buffer overflow
    }
    for (int i = 1; i < n; i++)
    {
        len = snprintf(temp, 100, " L%.6f,%.6f", x[i], y[i]); // Line to the next point
        if (len >= 100)
        {
            free(path);
            return NULL; // Error: buffer overflow
        }
        strcat(path, temp);
    }
    return path;
}

int generate_svg(char *svg_path, int size)
{
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", size, size);
    printf("<path d=\"%s\" fill=\"none\" stroke=\"black\" />\n", svg_path);
    printf("</svg>\n");

    return 0;
}
