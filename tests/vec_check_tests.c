#include <criterion/criterion.h>
#include "cvec_dev.h"

Test(vec_is_valid, null_vec)
{
    cr_assert_eq(vec_is_valid(NULL, false), false);
}

Test(vec_is_valid, null_data)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_eq(vec_is_valid(&vec, true), false);
    cr_assert_eq(vec_is_valid(&vec, false), true);
}

Test(vec_is_valid, zero_elem_size)
{
    vec_t vec = vec_create(0);

    cr_assert_eq(vec_is_valid(&vec, false), false);
}
