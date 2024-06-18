/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** size related functions
*/

#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "cvec_dev.h"

size_t vec_size(vec_t *vec)
{
    VEC_ASSERT(vec, 0);
    return vec->size;
}

static bool realloc_vec(vec_t *vec, size_t size)
{
    if (size == vec->size)
        return true;
    vec->data = realloc(vec->data, vec->elem_size * (size + 1));
    if (vec->data)
        memset(vec->data + (size * vec->elem_size), 0, vec->elem_size);
    return vec->data;
}

bool vec_fast_resize(vec_t *vec, size_t size)
{
    VEC_ASSERT_NO_DC(vec, false);
    if (!realloc_vec(vec, size))
        return false;
    vec->size = size;
    return true;
}

bool vec_resize(vec_t *vec, size_t size)
{
    ssize_t diff = 0;
    size_t old_size = 0;

    VEC_ASSERT_NO_DC(vec, false);
    if (!realloc_vec(vec, size))
        return false;
    old_size = vec->size;
    vec->size = size;
    diff = size - old_size;
    if (diff <= 0)
        return true;
    memset(vec->data + (old_size * vec->elem_size), 0, diff * vec->elem_size);
    return true;
}
