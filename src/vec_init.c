/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** creation/destruction related functions
*/

#include <stdlib.h>
#include "cvec_dev.h"

vec_t vec_create(size_t elem_size)
{
    return (vec_t){NULL, 0, elem_size};
}

void vec_free_data(vec_t *vec)
{
    VEC_ASSERT_V(vec);
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
}
