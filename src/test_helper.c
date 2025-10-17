/**
 * test_helper
 * Class to test the helper.h/c methods
 */

#include "test_helper.h"
#define EMPTY_STR "Empty String"
#define NOT_EMPTY_STR "Non Empty String"

TestResult *test_tokenize_base_case()
{
    char* string = "Test Test A B";
    char **tokens = tokenize(string);
    char **expected = {"test", "test", "a", "b"};
    
}

TestResult *test_tokenize_base_special_chars_case()
{

}

TestResult *test_tokenize_empty_case()
{

}

TestResult *test_tokenize_null_case()
{

}

TestResult *test_tokenize_single_token_case()
{

}

TestResult *test_tokenize_single_too_long_case()
{

}

TestResult *test_clean_spaces_space_case()
{
    char *cleaned = trim(" ");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_tab_case()
{
    char *cleaned = trim("\t");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_carriage_case()
{
    char *cleaned = trim("\r");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_new_line_case()
{
    char *cleaned = trim("\n");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_null_case()
{
    char *cleaned = trim("");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_non_spaces_case()
{
    char notCleaned[BUFF_SIZE] = "Test";
    char expected[BUFF_SIZE] = "Test";
    char *cleaned = trim(notCleaned);
    int result = (strcmp(cleaned, expected) == 0) ? 1 : 0;
    TestResult *testRes = createResult(
        expected,
        cleaned,
        "",
        result);
    free(cleaned);
    return testRes;
}

TestResult *test_clean_spaces_both_ends_case()
{
    char notCleaned[BUFF_SIZE] = "\nTest\n";
    char *cleaned = trim(notCleaned);
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_blank_first_case()
{
    char notCleaned[BUFF_SIZE] = "\nTest";
    char *cleaned = trim(notCleaned);
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return createResult(
        EMPTY_STR,
        result == 1 ? EMPTY_STR : NOT_EMPTY_STR,
        "",
        result);
}

TestResult *test_clean_spaces_trailing_base_case()
{
    char notCleaned[BUFF_SIZE] = "Test\n";
    char expected[BUFF_SIZE] = "Test";
    char *cleaned = trim(notCleaned);
    int result = (strcmp(cleaned, expected) == 0) ? 1 : 0;
    TestResult *testRes = createResult(
        expected,
        cleaned,
        "",
        result);
    free(cleaned);
    return testRes;
}

TestResult *test_is_blank_null_case()
{
    int result = isBlank(NULL);
    return createResult(
        "1",
        result == 1 ? "1" : "0",
        "",
        result);
}

TestResult *test_is_blank_non_empty_case()
{
    char empty[BUFF_SIZE] = "Hello Test";
    int result = !isBlank(empty);
    return createResult(
        "1",
        result == 1 ? "1" : "0",
        "",
        result);
}

TestResult *test_is_blank_base_case()
{
    char empty[BUFF_SIZE] = {0};
    int result = isBlank(empty);
    return createResult(
        "1",
        result == 1 ? "1" : "0",
        "",
        result);
}