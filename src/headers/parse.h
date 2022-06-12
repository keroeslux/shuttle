#ifndef PARSE_H
#define PARSE_H
#define BUF_SIZE 256
#include <string.h>
#include <stdio.h>
char *p_to_char(FILE *ptr, char *flag)
{
    char buffer[BUF_SIZE];
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strcmp(key, flag) == 0)
        {
            return (value);
        }
    }
}
int p_to_int(FILE *ptr, char *flag)
{
    char buffer[BUF_SIZE];
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strcmp(key, flag) == 0)
        {
            return atoi(value);
        }
    }
}
unsigned int p_to_unsigned_int(FILE *ptr, char *flag)
{
    char buffer[BUF_SIZE];
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strcmp(key, flag) == 0)
        {
            if ((unsigned int xint = atoi(value)) != atoi(value))
            {
                return EXIT_FAILURE;
            }
            else
            {
                return xint;
            }
        }
    }
}


#endif
