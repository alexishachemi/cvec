#include <criterion/criterion.h>

#define CVEC_IMPLEMENTATION
#include "cvec.h"

Test(cvec_is_valid, null_vec)
{
    cr_assert_eq(_cvec_is_valid(NULL, false), false);
}

Test(cvec_is_valid, null_data)
{
    cvec_t vec = cvec_create(sizeof(int));

    cr_assert_eq(_cvec_is_valid(&vec, true), false);
    cr_assert_eq(_cvec_is_valid(&vec, false), true);
}

Test(cvec_is_valid, zero_elem_size)
{
    cvec_t vec = cvec_create(0);

    cr_assert_eq(_cvec_is_valid(&vec, false), false);
}
