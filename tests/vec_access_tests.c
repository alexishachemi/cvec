#include <criterion/criterion.h>
#include "cvec.h"

Test(cvec_at, null_vec)
{
    cr_assert_null(cvec_at(NULL, 0));
}

Test(cvec_at, null_data)
{
    cvec_t vec = cvec_create(sizeof(int));

    cr_assert_null(cvec_at(&vec, 0));
}

Test(cvec_at, out_of_bounds)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    cr_assert_not_null(cvec_at(&vec, 9));
    cr_assert_null(cvec_at(&vec, 10));
    cvec_free_data(&vec);
}

Test(cvec_at, simple_access)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)cvec_at(&vec, i))[0], i);
    cvec_free_data(&vec);
}

Test(cvec_at, negative_index_access)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    cr_assert_eq(cvec_at(&vec, -1), cvec_at(&vec, 9));
    cr_assert_eq(cvec_at(&vec, -2), cvec_at(&vec, 8));
    cr_assert_eq(cvec_at(&vec, -10), cvec_at(&vec, 0));
    cr_assert_null(cvec_at(&vec, -11));
    cvec_free_data(&vec);
}

Test(cvec_safe_at, null_vec)
{
    cr_assert_null(cvec_safe_at(NULL, 0));
}

Test(cvec_safe_at, null_data)
{
    cvec_t vec = cvec_create(sizeof(int));

    cr_assert_not_null(cvec_safe_at(&vec, 0));
    cr_assert_eq(vec.size, 1);
    cvec_free_data(&vec);
}

Test(cvec_safe_at, out_of_bounds)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 3);
    cr_assert_eq(vec.size, 3);
    cr_assert_not_null(cvec_safe_at(&vec, 2));
    cr_assert_not_null(cvec_safe_at(&vec, 3));
    cr_assert_eq(vec.size, 4);
    cr_assert_not_null(cvec_safe_at(&vec, 12));
    cr_assert_eq(vec.size, 13);
    cr_assert_not_null(cvec_safe_at(&vec, 3));
    cr_assert_eq(vec.size, 13);
    cvec_free_data(&vec);
}

Test(cvec_safe_at, negative_index_access)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    cr_assert_eq(cvec_safe_at(&vec, -1), cvec_safe_at(&vec, 9));
    cr_assert_eq(cvec_safe_at(&vec, -2), cvec_safe_at(&vec, 8));
    cr_assert_eq(cvec_safe_at(&vec, -10), cvec_safe_at(&vec, 0));
    cr_assert_null(cvec_safe_at(&vec, -11));
    cr_assert_eq(vec.size, 10);
    cvec_free_data(&vec);
}

Test(cvec_at_macro, simple)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        CVEC_AT(int, &vec, i) = i * 2;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec.data)[i], i * 2);
    cvec_free_data(&vec);
}

Test(cvec_safe_at_macro, simple)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    for (size_t i = 0; i < vec.size; i++)
        ((int *)vec.data)[i] = i;
    for (size_t i = 0; i < vec.size; i++)
        CVEC_SAFE_AT(int, &vec, i) = i * 2;
    for (size_t i = 0; i < vec.size; i++)
        cr_assert_eq(((int *)vec.data)[i], i * 2);
    cvec_free_data(&vec);
}
