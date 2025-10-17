#ifndef TEST_HELPER_H
#define TEST_HELPER_H
#include <stdlib.h>
#include <stdio.h>

#include "global.h"
#include "helper.h"
#include "test_util.h"

// isBlank
TestResult *test_is_blank_base_case();
TestResult *test_is_blank_non_empty_case();
TestResult *test_is_blank_null_case();

// trim
TestResult *test_clean_spaces_trailing_base_case();
TestResult *test_clean_spaces_blank_first_case();
TestResult *test_clean_spaces_both_ends_case();
TestResult *test_clean_spaces_non_spaces_case();
TestResult *test_clean_spaces_null_case();
TestResult *test_clean_spaces_new_line_case();
TestResult *test_clean_spaces_carriage_case();
TestResult *test_clean_spaces_tab_case();
TestResult *test_clean_spaces_space_case();

// tokenize
TestResult *test_tokenize_base_case();
TestResult *test_tokenize_base_special_chars_case();
TestResult *test_tokenize_empty_case();
TestResult *test_tokenize_null_case();
TestResult *test_tokenize_single_token_case();
TestResult *test_tokenize_single_too_long_case();

#endif