#ifndef TEST_UTIL_H
#define TEST_UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"

#define MAX_TEST_RESULT_FIELD_LEN 100

typedef struct testResult
{
    char *message;   // MAX length of 100
    char *excepcted; // MAX length of 100
    char *actual;
    int *passed;
} TestResult;

TestResult *createResult(char *excpected, char *actual, char *message, int passed);
TestResult *destroyResult(TestResult *);
void debugResult(TestResult *, char *);
#endif