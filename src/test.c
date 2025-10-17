#include "test.h"
#include "test_helper.h"

void print_test_statement(int passed, const char* TEST_NAME);

int main() {
    print_test_statement(1, "------------------ Running unit tests ------------------");
    if (!unit_test()) 
    {
        print_test_statement(0, "------------------ Some tests failed ------------------");
    } else 
    {
        print_test_statement(1, "------------------ Test End ------------------");
    }
    return 0;
}

typedef struct testing_framework
{
    char* testName;
    int (*testFunctions)();
} TestingFramework;

static TestingFramework testFramework[] = 
{
    {"test_is_blank_base_case", test_is_blank_base_case},
    {"test_is_blank_non_empty_case", test_is_blank_non_empty_case},
    {"test_is_blank_null_case", test_is_blank_null_case},
    {"test_clean_spaces_trailing_base_case", test_clean_spaces_trailing_base_case},
    {"test_clean_spaces_blank_first_case", test_clean_spaces_blank_first_case},
    {"test_clean_spaces_both_ends_case", test_clean_spaces_both_ends_case},
    {"test_clean_spaces_non_spaces_case", test_clean_spaces_non_spaces_case},
    {"test_clean_spaces_null_case", test_clean_spaces_null_case},
    {"test_clean_spaces_new_line_case", test_clean_spaces_new_line_case},
    {"test_clean_spaces_carriage_case", test_clean_spaces_carriage_case},
    {"test_clean_spaces_tab_case", test_clean_spaces_tab_case},
    {"test_clean_spaces_space_case", test_clean_spaces_space_case},
    {NULL, NULL}
};

int unit_test() 
{
    int all_test_passed = 1;
    int test_passed = 1;
    for (int i=0; testFramework[i].testName != NULL; i++)
    {
        test_passed = testFramework[i].testFunctions();
        print_test_statement(test_passed, testFramework[i].testName);
        all_test_passed &= test_passed;
    }
    return all_test_passed;
}

void print_test_statement(int passed, const char* TEST_NAME)
{
    if (passed)
        printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n", TEST_NAME);
    else
        printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", TEST_NAME);
}
