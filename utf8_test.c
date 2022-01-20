//
// Created by carlos on 1/20/22.
//
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

static void test_hello(void **state) {
    (void) state;
    assert_int_equal(1, 2);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_hello),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}