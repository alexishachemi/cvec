/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** internal functions, not to be used by the user
*/

#pragma once

#include "cvec.h"

#define VEC_ASSERT(vecptr, ret) if (!vec_is_valid(vec, true)) return ret
#define VEC_ASSERT_V(vecptr) if (!vec_is_valid(vec, true)) return
#define VEC_ASSERT_NO_DC(vecptr, ret) if (!vec_is_valid(vec, false)) return ret
#define VEC_ASSERT_V_NO_DC(vecptr) if (!vec_is_valid(vec, false)) return

bool vec_is_valid(vec_t *vec, bool check_data);
size_t vec_wrap_index(vec_t *vec, ssize_t i);
