//
// Created by carlos on 1/20/22.
//
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
#include "utf8.h"

static void test_su8_enc_cp_to_bytes(void **state) {
    (void) state;

    char output[5] = {0};
    assert_int_equal(su8_enc_cp_to_bytes(0x0045, output), 1);
    assert_string_equal(output, "E");

    assert_int_equal(su8_enc_cp_to_bytes(0x01C2, output), 2);
    assert_string_equal(output, "ǂ");

    assert_int_equal(su8_enc_cp_to_bytes(0x3297, output), 3);
    assert_string_equal(output, "㊗");

    assert_int_equal(su8_enc_cp_to_bytes(0x1F60C, output), 4);
    assert_string_equal(output, "😌");
}

static void test_su8_dec_bytes_to_cp(void **state){
    (void) state;

    uint32_t codepoint = 0L;
    assert_int_equal(su8_dec_bytes_to_cp("E", &codepoint), 1);
    assert_int_equal(codepoint, 0x0045);

    assert_int_equal(su8_dec_bytes_to_cp("ǂ", &codepoint), 2);
    assert_int_equal(codepoint, 0x01C2);

    assert_int_equal(su8_dec_bytes_to_cp("㊗", &codepoint), 3);
    assert_int_equal(codepoint, 0x3297);

    assert_int_equal(su8_dec_bytes_to_cp("😌", &codepoint), 4);
    assert_int_equal(codepoint, 0x1F60C);
}

static void test_su8_dec_bytes_to_cp_invalid_seqs(void **state) {
    (void) **state;
    // TODO: Actually detect and replace invalid UTF8 sequences
//    uint32_t codepoint;
//
//    char bad_input[5] = {(char) 0xC0, (char) 0x80, 0x00, 0x00};
//    assert_int_equal(su8_dec_bytes_to_cp(bad_input, &codepoint), 0);
//
//    char bad_input2[5] = {(char) 0xE0, (char) 0x81, (char) 0x80, 0x00};
//    assert_int_equal(su8_dec_bytes_to_cp(bad_input2, &codepoint), 0);
//
//    char bad_input3[5] = {(char) 0xF0, (char) 0x81, (char) 0x81, (char) 0x80};
//    assert_int_equal(su8_dec_bytes_to_cp(bad_input3, &codepoint), 0);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_su8_enc_cp_to_bytes),
            cmocka_unit_test(test_su8_dec_bytes_to_cp),
            cmocka_unit_test(test_su8_dec_bytes_to_cp_invalid_seqs),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}