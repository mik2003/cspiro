#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    int size;
    float *arr;
} Vector;

Vector vec_new(int size);
int vec_addf(Vector *v, float f);
int vec_subf(Vector *v, float f);

#endif /* VECTOR_H */
