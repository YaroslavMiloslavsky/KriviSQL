#include "command.h"
#include "enums.h"

CommandResponse* parseCommand(char* command) 
{
    if (strlen(command) > 0)
    {
        int code = -111;
        char* cleaned = trim(command);
    
        if (strcmp(cleaned, EXIT_STR) == 0) 
        {
            code = EXIT;
        }
        else 
        {
            char tokens[] = tokenize(command);
        }

        CommandResponse* response = (CommandResponse*)malloc(sizeof(CommandResponse));
        response->code=code;
    
        free(cleaned);
        return response;
    }
    return NULL;
}
