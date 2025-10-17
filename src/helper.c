#include "helper.h"

int isBlank(const char *STRING)
{
    if (STRING == NULL || STRING[0] == '\0' || strlen(STRING) == 0)
        return 1;
    return 0;
}

char *_cleanIllegalChars(char *string)
{
    char *cleaned = (char *)malloc(BUFF_SIZE * sizeof(char));
    if (cleaned == NULL)
    {
        return NULL;
    }
    memset(cleaned, '\0', BUFF_SIZE);

    int i = 0;
    int j = 0;
    while (!isalnum(string[j]))
        j++;
    while (string[j] && string[j] != '\n')
    {
        cleaned[i] = string[j];
        j++;
        i++;
    }
    cleaned[i] = '\0';
    return cleaned;
}

char *trim(char *string)
{
    if (string[0] > CONTROL_CHARS_END && string[0] != ' ' && strlen(string) > 0)
    {
        return _cleanIllegalChars(string);
    }
    char *empty = (char *)malloc(sizeof(char));
    if (empty == NULL)
    {
        return NULL;
    }
    memset(empty, '\0', 1);
    return empty;
}

char *tokenize(char *string)
{
    return NULL;
}