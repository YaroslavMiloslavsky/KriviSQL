#ifndef HELPER_H
#define HELPER_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "global.h"

#define CONTROL_CHARS_END 31

int isBlank(const char*);
char* trim(char*);
char* tokenize(char*);
#endif