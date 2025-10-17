#ifndef COMMANDS_H
#define COMMANDS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "global.h"
#include "helper.h"

typedef struct commandResponse
{
    int code;
} CommandResponse;

/**
 * Returns a code for action
 * -1 - EXIT
 */
CommandResponse *parseCommand(char *COMMAND);

#endif