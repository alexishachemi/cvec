#include <criterion/criterion.h>
#include "cvec.h"

Test(cvec_init_tests, cvec_create)
{
    cvec_t vec = cvec_create(sizeof(int));

    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.elem_size, sizeof(int));
    cr_assert_eq(vec.size, 0);
}

Test(cvec_init_tests, cvec_free_data)
{
    cvec_t vec = cvec_create(sizeof(int));

    cvec_resize(&vec, 10);
    cr_assert_not_null(vec.data);
    cvec_free_data(&vec);
    cr_assert_null(vec.data);
    cr_assert_eq(vec.elem_size, sizeof(int));
    cr_assert_eq(vec.size, 0);
}
