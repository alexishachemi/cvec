/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** usage example
*/

#include <stdio.h>
#define CVEC_IMPLEMENTATION
#include "cvec.h"

// The vector's size can be accessed with cvec_size or the struct member.
// Beware that the struct member should not be modified directly.
void size(cvec_t *vec)
{
    for (size_t i = 0; i < cvec_size(vec); i++)
        CVEC_AT(int, vec, i) = 42;
    for (size_t i = 5; i < vec->size; i++)
        CVEC_AT(int, vec, i) = i;
}

// Resize reallocs the vector. When extended, the new allocated memory is
// initialized to 0 bytes. fast_resize does not initialize the new memory.
// When resized by any functions, vectors are null terminated.
void resize(cvec_t *vec)
{
    cvec_resize(vec, 10);
    cvec_fast_resize(vec, 10);
}

// Memory is accessed using the cvec_at functions or the CVEC_AT macros for
// direct casting. Safe access will resize the vector if the index is out
// of bounds. Fast access will not check if the index is out of bounds. CVEC_AT
// performs a fast access. Access can be done with negative indexes, which
// will be converted to positive indexes starting from the end of the vector.
void access(cvec_t *vec)
{
    *(int *)cvec_at(vec, 0) = 8;
    *(int *)cvec_safe_at(vec, 2) = 32;
    CVEC_AT(int, vec, 2) = 64;
    CVEC_AT(int, vec, -2) = -64;
    CVEC_SAFE_AT(int, vec, vec->size + 10) = 128;
}

// Vectors are initialized using the cvec_create function. The size must be a
// non-zero positive integer representing the size in bytes of each element
// to be stored. The vector's data should be freed at the end of its use.
// This is done using the cvec_free_data function.
int main(void)
{
    cvec_t vec = cvec_create(sizeof(int));

    resize(&vec);
    size(&vec);
    access(&vec);
    printf("vector size: %lu\n", vec.size);
    printf("vector data: [%d", CVEC_AT(int, &vec, 0));
    for (size_t i = 1; i < vec.size; i++)
        printf(", %d", CVEC_AT(int, &vec, i));
    printf("]\n");
    cvec_free_data(&vec);
    return 0;
}
