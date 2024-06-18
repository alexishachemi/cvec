/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** access related functions
*/

#include "cvec_dev.h"

void *vec_at(vec_t *vec, ssize_t i)
{
    VEC_ASSERT(vec, NULL);
    if (i < 0)
        i += vec->size;
    if (i < 0 || (size_t)i >= vec->size)
        return NULL;
    return vec->data + (vec->elem_size * i);
}

void *vec_fast_at(vec_t *vec, size_t i)
{
    return vec->data + (vec->elem_size * i);
}

void *vec_safe_at(vec_t *vec, ssize_t i)
{
    VEC_ASSERT_NO_DC(vec, NULL);
    if (i < 0)
        i += vec->size;
    if (i < 0)
        return NULL;
    if ((size_t)i >= vec->size && !vec_resize(vec, i + 1))
        return NULL;
    return vec->data + (vec->elem_size * i);
}
