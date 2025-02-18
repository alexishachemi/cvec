#ifndef CVEC_H_

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#define CVEC_AT(type, cvec_ptr, i) (*(type*)cvec_at(cvec_ptr, i))
#define CVEC_SAFE_AT(type, cvec_ptr, i) (*(type*)cvec_safe_at(cvec_ptr, i))
#define CVEC_FAST_AT(cvec_ptr, i) ((cvec_ptr)->data + ((cvec_ptr)->elem_size * i))

#define _CVITT_TYPE size_t
#define _CVITT __cvec_itt_idx
#define CVEC_FOREACH(type, cvec_ptr, itt, body) {                       \
    type *(itt) = NULL;                                                 \
    for (_CVITT_TYPE _CVITT = 0; _CVITT < (cvec_ptr)->size; _CVITT++)   \
    {                                                                   \
        (itt) = CCVEC_FAST_AT(cvec_ptr, _CVITT);                         \
        if ((itt) == NULL)                                              \
            break;                                                      \
        body;                                                           \
    }}

typedef struct {
    void *data;
    size_t size;
    size_t elem_size;
} cvec_t;

cvec_t cvec_create(size_t elem_size);
void cvec_free_data(cvec_t *vec);
void *cvec_at(cvec_t *vec, ssize_t i);
void *cvec_safe_at(cvec_t *vec, ssize_t i);
size_t cvec_size(cvec_t *vec);
bool cvec_fast_resize(cvec_t *vec, size_t size);
bool cvec_resize(cvec_t *vec, size_t size);

///////////////////////////////////////////////////////////////////////////////

#ifdef CVEC_IMPLEMENTATION

#include <stdlib.h>
#include <string.h>

static bool _cvec_is_valid(cvec_t *vec, bool check_data)
{
    return vec && vec->elem_size > 0 && (!check_data || vec->data);
}

static bool _cvec_realloc(cvec_t *vec, size_t size)
{
    if (size == vec->size)
        return true;
    vec->data = realloc(vec->data, vec->elem_size * (size + 1));
    if (vec->data)
        memset(vec->data + (size * vec->elem_size), 0, vec->elem_size);
    return vec->data;
}

cvec_t cvec_create(size_t elem_size)
{
    return (cvec_t){NULL, 0, elem_size};
}

void cvec_free_data(cvec_t *vec)
{
    if (!_cvec_is_valid(vec, true))
        return
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
}

void *cvec_at(cvec_t *vec, ssize_t i)
{
    if (!_cvec_is_valid(vec, true))
        return NULL;
    if (i < 0)
        i += vec->size;
    if (i < 0 || (size_t)i >= vec->size)
        return NULL;
    return CVEC_FAST_AT(vec, i);
}

void *cvec_safe_at(cvec_t *vec, ssize_t i)
{
    if (!_cvec_is_valid(vec, false))
        return NULL;
    if (i < 0)
        i += vec->size;
    if (i < 0)
        return NULL;
    if ((size_t)i >= vec->size && !cvec_resize(vec, i + 1))
        return NULL;
    return CVEC_FAST_AT(vec, i);
}

size_t cvec_size(cvec_t *vec)
{
    if (!_cvec_is_valid(vec, true))
        return 0;
    return vec->size;
}

bool cvec_fast_resize(cvec_t *vec, size_t size)
{
    if (!_cvec_is_valid(vec, false))
        return false;
    if (!_cvec_realloc(vec, size))
        return false;
    vec->size = size;
    return true;
}

bool cvec_resize(cvec_t *vec, size_t size)
{
    ssize_t diff = 0;
    size_t old_size = 0;

    if (!_cvec_is_valid(vec, false))
        return false;
    if (!_cvec_realloc(vec, size))
        return false;
    old_size = vec->size;
    vec->size = size;
    diff = size - old_size;
    if (diff <= 0)
        return true;
    memset(vec->data + (old_size * vec->elem_size), 0, diff * vec->elem_size);
    return true;
}

#endif // CVEC_IMPLEMENTATION

#endif // CVEC_H_