#include <criterion/criterion.h>
#include "cvec_dev.h"

Test(vec_resize, simple_resize)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_eq(vec_resize(&vec, 10), true);
    cr_assert_eq(vec.size, 10);
    cr_assert_not_null(vec.data);
    for (size_t i = 0; i <= vec.size; i++)
        cr_assert_eq(((int *)vec.data)[i], 0);
    vec_free_data(&vec);
}

Test(vec_resize, multiple_resize)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_eq(vec_resize(&vec, 10), true);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    cr_assert_eq(vec_resize(&vec, 20), true);
    cr_assert_eq(vec.size, 20);
    for (size_t i = 0; i < 10; i++)
        cr_assert_eq(((int *)vec.data)[i], i);
    for (size_t i = 10; i < 20; i++)
        cr_assert_eq(((int *)vec.data)[i], 0);
    for (size_t i = 10; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < 20; i++)
        cr_assert_eq(((int *)vec.data)[i], i);
    cr_assert_eq(vec_resize(&vec, 3), true);
    cr_assert_eq(vec.size, 3);
    for (size_t i = 0; i < 3; i++)
        cr_assert_eq(((int *)vec.data)[i], i);
    cr_assert_eq(((int *)vec.data)[3], 0);
    vec_free_data(&vec);
}
