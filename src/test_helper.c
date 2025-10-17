#include "test_helper.h"

int test_clean_spaces_space_case()
{
    char* cleaned = trim(" ");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_tab_case()
{
    char* cleaned = trim("\t");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_carriage_case()
{
    char* cleaned = trim("\r");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_new_line_case()
{
    char* cleaned = trim("\n");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_null_case()
{
    char* cleaned = trim("");
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_non_spaces_case()
{
    char notCleaned[BUFF_SIZE] = "Test";
    char expected[BUFF_SIZE] = "Test";
    char* cleaned = trim(notCleaned);
    int result = (strcmp(cleaned, expected) == 0) ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_both_ends_case()
{
    char notCleaned[BUFF_SIZE] = "\nTest\n";
    char* cleaned = trim(notCleaned);
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_blank_first_case()
{
    char notCleaned[BUFF_SIZE] = "\nTest";
    char* cleaned = trim(notCleaned);
    int result = ((cleaned[0]) == '\0') ? 1 : 0;
    free(cleaned);
    return result;
}

int test_clean_spaces_trailing_base_case()
{
    char notCleaned[BUFF_SIZE] = "Test\n";
    char expected[BUFF_SIZE] = "Test";
    char* cleaned = trim(notCleaned);
    int result = (strcmp(cleaned, expected) == 0) ? 1 : 0;
    free(cleaned);
    return result;
}

int test_is_blank_null_case()
{
    int result = 0;
    result = isBlank(NULL);
    return result;
}

int test_is_blank_non_empty_case()
{
    int result = 0;
    char empty[BUFF_SIZE] = "Hello Test";
    result = isBlank(empty);
    return !result;
}

int test_is_blank_base_case() 
{
    int result = 0;
    char empty[BUFF_SIZE] = {0};
    result = isBlank(empty);
    return result;
}