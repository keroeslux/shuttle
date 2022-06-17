#ifndef PARSE_H
#define PARSE_H
#include <string.h>
#include <stdbool.h>
#define BUF_SIZE 256 
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "./log.h"
#include "./colors.h"
extern bool scan_file(FILE *ptr, char *flag)
{
    char *token;
    char buffer[BUF_SIZE];
    while(fgets(buffer, BUF_SIZE, ptr))
    {
        token = (char*)strtok(buffer, " ");
        if (strcmp(token, flag)==0)
        {
            return true;
        }
    }
    return false;
}
extern int line_num(FILE *ptr, char *flag)
{
    int a = 1;
    char buffer[BUF_SIZE];
    char *token;
    char *bufline;
    while(fgets(buffer, BUF_SIZE, ptr))
    {
        token = (char*)strtok(buffer, " ");
        bufline = (char*)strtok(buffer, "\n");
        if (strcmp(token, flag)==0 || strcmp(bufline, flag)==0)
        {
            return a;
        }
        a++;
    }
    return EXIT_FAILURE;
}
extern char *p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        if (buffer == '}')
        {
            break;
        }
        key = (char*)strtok_r(buffer, "=", &value);
        if ((int)strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", (int)strlen(flag), BUF_SIZE);
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
    return (char *)EXIT_FAILURE;
}
extern int p_to_int(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        if (buffer == "}")
        {
            break;
        }
        key = strtok_r(buffer, "=", &value);
        if ((int)strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", (int)strlen(flag), BUF_SIZE);
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
    return EXIT_FAILURE;
}
extern unsigned int p_to_unsigned_int(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
        if (buffer == "}")
        {
            break;
        }
        key = strtok_r(buffer, "=", &value);
        if ((int)strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n", (int)strlen(flag), BUF_SIZE);
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
                    }
                    else
                    {
                        return (unsigned)(atoi(value));
                    }
                }
            }
        }
    }
    return EXIT_FAILURE;
}
#endif
