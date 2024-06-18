#include <criterion/criterion.h>
#include "cvec_dev.h"

Test(vec_init_tests, vec_create)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.elem_size, sizeof(int));
    cr_assert_eq(vec.size, 0);
}

Test(vec_init_tests, vec_free_data)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    cr_assert_not_null(vec.data);
    vec_free_data(&vec);
    cr_assert_null(vec.data);
    cr_assert_eq(vec.elem_size, sizeof(int));
    cr_assert_eq(vec.size, 0);
}
