#ifndef PARSE_H
#define PARSE_H
#include <string.h>
#define BUF_SIZE 256 
#include <stdio.h>
#include <stdlib.h>
#include "./log.h"
#include "./colors.h"

static char *p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", strlen(flag), BUF_SIZE);
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
                    return (value); /* Dont forget to free */
                }
            }
        }
    }
    exit(0);
}
static int p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", strlen(flag), BUF_SIZE);
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
                    return atoi(value); /* Dont forget to free */
                }
            }
        }
    }
    exit(0);
}
static unsigned int p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", strlen(flag), BUF_SIZE);
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
                    if (atoi(value) < 0)
                    {
                        return EXIT_FAILURE;
                    else
                        return (unsigned)(atoi(value));
                    }
                }
            }
        }
    }
    exit(0);
}
#endif
