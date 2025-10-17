#include<stdio.h>
#include<string.h>

#include "global.h"
#include "helper.h"
#include "command.h"
#include "enums.h"

int main() 
{
    printf(" ---------- Welcome to Minimal SQL version %0.2f ----------\n", VERSION);

    char buffer[BUFF_SIZE] = {0};
    memset(buffer, '\0', sizeof(buffer));
    int commandCode = 0;
    do {
        printf(PLOMBY);
        if (!isBlank(buffer)) {
            CommandResponse* command = parseCommand(buffer);
            if (command != NULL)
            {
                commandCode = command -> code;
                memset(buffer, '\0', sizeof(buffer));
                free(command);
            }
        }
        fflush(stdin);
    } while (commandCode != EXIT && fgets(buffer, BUFF_SIZE - 1, stdin) != NULL);
    printf("\nGoodbye :) Do come again!\n");
    fflush(NULL);
    return 0;
}