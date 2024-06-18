/*
** EPITECH PROJECT, 2024
** cvec
** File description:
** validity check functions
*/

#include "cvec.h"
#include "cvec_dev.h"

bool vec_is_valid(vec_t *vec, bool check_data)
{
    return vec && vec->elem_size > 0 && (!check_data || vec->data);
}
