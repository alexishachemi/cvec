/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** main header file
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#define VEC_AT(type, vec_ptr, i) (*(type*)vec_at(vec_ptr, i))
#define VEC_FAST_AT(type, vec_ptr, i) (*(type*)vec_fast_at(vec_ptr, i))
#define VEC_SAFE_AT(type, vec_ptr, i) (*(type*)vec_safe_at(vec_ptr, i))

typedef struct {
    void *data;
    size_t size;
    size_t elem_size;
} vec_t;

// init
vec_t vec_create(size_t elem_size);
void vec_free_data(vec_t *vec);

// access
void *vec_at(vec_t *vec, ssize_t i);
void *vec_fast_at(vec_t *vec, size_t i);
void *vec_safe_at(vec_t *vec, ssize_t i);

// size
size_t vec_size(vec_t *vec);
bool vec_resize_fast(vec_t *vec, size_t size);
bool vec_resize(vec_t *vec, size_t size);
