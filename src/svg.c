#include "svg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate SVG path string from x and y arrays
char *generate_svg_path(float *x, float *y, int n)
{
    // Maximum size of a point string (including space for M or L and commas) is 24 characters
    // We allocate slightly more to account for potential rounding in snprintf and for null termination
    const int max_point_size = 30;

    // Allocate memory for the path
    char *path = (char *)malloc((n * max_point_size) + 1);
    if (path == NULL)
    {
        return NULL; // Error: unable to allocate memory
    }

    int offset = 0;                                 // Keep track of where to append in the path
    int remaining_space = (n * max_point_size) + 1; // Initialize remaining space

    // Move to the first point
    int len = snprintf(path + offset, remaining_space, "M%.6f,%.6f", x[0], y[0]);
    if (len >= remaining_space)
    {
        free(path);
        return NULL; // Error: buffer overflow
    }
    remaining_space -= len; // Update remaining space
    offset += len;

    // Construct the path string
    for (int i = 1; i < n; i++)
    {
        len = snprintf(path + offset, remaining_space, " L%.6f,%.6f", x[i], y[i]);
        if (len >= remaining_space)
        {
            free(path);
            return NULL; // Error: buffer overflow
        }
        remaining_space -= len; // Update remaining space
        offset += len;
    }
    return path;
}

int generate_svg(char *svg_path, int size)
{
    if (svg_path == NULL)
    {
        return -1; // Error: svg_path is NULL
    }

    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", size, size);
    printf("<path d=\"%s\" fill=\"none\" stroke=\"black\" />\n", svg_path);
    printf("</svg>\n");

    return 0;
}

// char *generate_svg_path(float *x, float *y, int n)
// {
//     char *path = (char *)malloc(n * 100 * sizeof(char)); // Assuming a maximum of 40 characters per point
//     char temp[100];
//     int len = snprintf(path, 100, "M%.6f,%.6f", x[0], y[0]); // Move to the first point
//     if (len >= 100)
//     {
//         free(path);
//         return NULL; // Error: buffer overflow
//     }
//     for (int i = 1; i < n; i++)
//     {
//         len = snprintf(temp, 100, " L%.6f,%.6f", x[i], y[i]); // Line to the next point
//         if (len >= 100)
//         {
//             free(path);
//             return NULL; // Error: buffer overflow
//         }
//         strcat(path, temp);
//     }

//     return path;
// }

// int generate_svg(char *svg_path, int size)
// {
//     if (svg_path == NULL)
//     {
//         return -1; // Error: svg_path is NULL
//     }
//     printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", size, size);
//     printf("<path d=\"%s\" fill=\"none\" stroke=\"black\" />\n", svg_path);
//     printf("</svg>\n");

//     return 0;
// }
