#ifndef PARSE_H
#define PARSE_H
#include <string.h>
#define BUF_SIZE 256 
#include <stdio.h>
#include <stdlib.h>
#include "./log.h"
#include "./colors.h"
char *p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE);
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strlen(flag) > BUF_SIZE)
        {
            free(buffer);
            error("Buffer Overflow. Aborting");
            abort();
        }
        else
        {
            if (sizeof(buffer) > BUF_SIZE)
            {
                free(buffer);
                error("Buffer Overflow. Aborting.");
                abort();
            }
            else
            {
                if (strcmp(key, flag) == 0)
                {
                    return (value);
                }
            }
        }
    }
    exit(0);
}
int p_to_int(FILE *ptr, char *flag)
{
    char *buffer;
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (sizeof(buffer) > sizeof(BUF_SIZE))
        {
            buffer = malloc(sizeof(BUF_SIZE) + sizeof(key));
            error("Buffer Overflow. Attempting to rescue.");
            reset();
        }
        else
        {
            if (strcmp(key, flag) == 0)
            {
                return atoi(value);
            }
        }
    }
}
unsigned int p_to_unsigned_int(FILE *ptr, char *flag)
{
    char *buffer;
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (sizeof(buffer) > sizeof(BUF_SIZE))
        {
            buffer = malloc(sizeof(BUF_SIZE) * sizeof(key));
            error("Buffer Overflow. Attempting to rescue.");
            reset();
        }
        else
        {
            if (strcmp(key, flag) == 0)
            {
                unsigned int xint = atoi(value);
                if (sizeof(xint) != sizeof(atoi(value)))
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
}


#endif
