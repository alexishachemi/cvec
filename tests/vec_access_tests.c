#include <criterion/criterion.h>
#include "cvec_dev.h"

Test(vec_at, null_vec)
{
    cr_assert_null(vec_at(NULL, 0));
}

Test(vec_at, null_data)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_null(vec_at(&vec, 0));
}

Test(vec_at, out_of_bounds)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    cr_assert_not_null(vec_at(&vec, 9));
    cr_assert_null(vec_at(&vec, 10));
    vec_free_data(&vec);
}

Test(vec_at, simple_access)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec_at(&vec, i))[0], i);
    vec_free_data(&vec);
}

Test(vec_at, negative_index_access)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    cr_assert_eq(vec_at(&vec, -1), vec_at(&vec, 9));
    cr_assert_eq(vec_at(&vec, -2), vec_at(&vec, 8));
    cr_assert_eq(vec_at(&vec, -10), vec_at(&vec, 0));
    cr_assert_null(vec_at(&vec, -11));
    vec_free_data(&vec);
}

Test(vec_fast_at, null_vec)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec_fast_at(&vec, i))[0], i);
    vec_free_data(&vec);
}

Test(vec_safe_at, null_vec)
{
    cr_assert_null(vec_safe_at(NULL, 0));
}

Test(vec_safe_at, null_data)
{
    vec_t vec = vec_create(sizeof(int));

    cr_assert_not_null(vec_safe_at(&vec, 0));
    cr_assert_eq(vec.size, 1);
    vec_free_data(&vec);
}

Test(vec_safe_at, out_of_bounds)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 3);
    cr_assert_eq(vec.size, 3);
    cr_assert_not_null(vec_safe_at(&vec, 2));
    cr_assert_not_null(vec_safe_at(&vec, 3));
    cr_assert_eq(vec.size, 4);
    cr_assert_not_null(vec_safe_at(&vec, 12));
    cr_assert_eq(vec.size, 13);
    cr_assert_not_null(vec_safe_at(&vec, 3));
    cr_assert_eq(vec.size, 13);
    vec_free_data(&vec);
}

Test(vec_safe_at, negative_index_access)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    cr_assert_eq(vec_safe_at(&vec, -1), vec_safe_at(&vec, 9));
    cr_assert_eq(vec_safe_at(&vec, -2), vec_safe_at(&vec, 8));
    cr_assert_eq(vec_safe_at(&vec, -10), vec_safe_at(&vec, 0));
    cr_assert_null(vec_safe_at(&vec, -11));
    cr_assert_eq(vec.size, 10);
    vec_free_data(&vec);
}

Test(vec_at_macro, simple)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        VEC_AT(int, &vec, i) = i * 2;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec.data)[i], i * 2);
    vec_free_data(&vec);
}

Test(vec_safe_at_macro, simple)
{
    vec_t vec = vec_create(sizeof(int));

    vec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        VEC_SAFE_AT(int, &vec, i) = i * 2;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec.data)[i], i * 2);
    vec_free_data(&vec);
}
