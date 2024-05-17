#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate_svg_path(float *x, float *y, int n);
int generate_svg(const char *filename, char *svg_path, int size);

#endif /* SVG_H */