#include "header/test_util.h"

void _initFromSrc(char* dest, char* src)
{
    memset(dest, '\0', MAX_TEST_RESULT_FIELD_LEN);
    size_t len = strlen(src) > MAX_TEST_RESULT_FIELD_LEN ? MAX_TEST_RESULT_FIELD_LEN - 1 : strlen(src);
    strncpy(dest, src, len);
    dest[len] = '\0';
}

TestResult *createResult(char *excpected, char *actual, char *message, int passed)
{
    TestResult *result = (TestResult *)malloc(sizeof(TestResult));
    if (result == NULL)
    {
        return NULL;
    }

    result->actual = (char *)malloc(MAX_TEST_RESULT_FIELD_LEN * sizeof(char));
    if (result->actual == NULL)
    {
        free(result);
        return NULL;
    }
    _initFromSrc(result->actual, actual);

    result->excepcted = (char *)malloc(MAX_TEST_RESULT_FIELD_LEN * sizeof(char));
    if (result->excepcted == NULL)
    {
        free(result->actual);
        free(result);
        return NULL;
    }
    _initFromSrc(result->excepcted, excpected);

    result->message = (char *)malloc(MAX_TEST_RESULT_FIELD_LEN * sizeof(char));
    if (result->message == NULL)
    {
        free(result->actual);
        free(result->excepcted);
        free(result);
        return NULL;
    }
    _initFromSrc(result->message, message);

    result->passed = (int *)malloc(sizeof(int));
    if (result->passed == NULL)
    {
        free(result->actual);
        free(result->excepcted);
        free(result->message);
        free(result);
        return NULL;
    }
    *(result->passed) = passed;

    return result;
}

TestResult *destroyResult(TestResult *result)
{
    if (result == NULL)
    {
        return NULL;
    }
    free(result->actual);
    free(result->excepcted);
    free(result->message);
    free(result->passed);
    free(result);
    return NULL;
}

void debugResult(TestResult *result, char *name)
{
    printf(ANSI_COLOR_RED);

    printf("\nFAILURE: %s\n", name);
    printf("==================================\n");
    printf("Expected: %s\n", result->excepcted);
    printf("Actual:   %s\n", result->actual); // Align 'Actual' for comparison
    printf("==================================\n");
    
    if (!result->message)
        printf("Message:  %s\n", result->message);
    printf(ANSI_COLOR_RESET "\n");
}