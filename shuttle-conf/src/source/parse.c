#include <string.h>
#include <stdbool.h>
#define BUF_SIZE 256 
#include <stdio.h>
#include <stdarg.h> 
#include <stdlib.h>
#include "../include/log.h"
#include "../include/colors.h"
#include "../include/extra_functions.h"
#include "../include/parse.h"
/* I should build a function to take multiple strings and find the line of each and return them in an array */

int *var_line_num(int count, FILE *ptr, const char *path, char *far, ...)
{
    int cc, a = 1, arr[count];
    char buffer[BUF_SIZE];
    char *token, *bufline, *fr;
    va_list valist;
    va_start(valist, far);
    fr = va_arg(valist, char*);
    for (int i = 0;i<=count;i++)
    {
        if (check_for_file(path) == true)
        {
            while(fgets(buffer, BUF_SIZE, ptr))
            {
                token = strtok(buffer, " ");
                bufline = strtok(buffer, "\n");
                if (strcmp(token, fr)==0 || strcmp(bufline, fr)==0)
                {
                    arr[a] = (int)fr;
                }
                else
                {
                    a++;
                    cc = (int)va_arg(valist, char*);
                    fr = cc;
                }
            }
        }
        else
        {
            red();
            printf("File: `%s` was not found.\n",path);
            reset();
            return 1;
        }
    }
    return &arr;
}


bool scan_yes_no(FILE *ptr, char *flag)
{
    char *buffer = malloc(BUF_SIZE);
    char *key, *value;
    while(fgets(buffer, BUF_SIZE, ptr))
    {
        key = strtok_r(buffer, "=", &value);
        if (strlen(flag) > BUF_SIZE)
        {
            printf("SIZE: %d :: Please lower flag to %d\n",(int)strlen(flag), BUF_SIZE);
            free(buffer);
            error("Buffer Overflow. Aborting");
            abort();
        }
        else
        {
            if (sizeof(buffer) > BUF_SIZE)
            {
                free(buffer);
                error("Buffer Overflow. Aborting");
                abort();
            }
            else
            {
                if (strcmp(key, flag)==0)
                {
                    if (strcmp(key, "true")==0 || strcmp(key, "on")==0)
                    {
                        return true;
                    }
                    else if (strcmp(key, "false")==0 || strcmp(key, "off")==0)
                    {
                        return false;
                    }
                    else
                    {
                        yellow();
                        printf("Error: %s is not a valid filter. Returning false",key);
                        return false;
                    }
                }

            }
        }
    }
}
bool scan_file(FILE *ptr, const char *path, char *flag)
{
    char *token;
    char buffer[BUF_SIZE];
    if (check_for_file(path))
    {
        while(fgets(buffer, BUF_SIZE, ptr))
        {
            token = (char*)strtok(buffer, " ");
            if (strcmp(token, flag)==0)
            {
                return true;
            }
        }
    }
    return false;
}
int line_num(FILE *ptr, const char *path, char *flag)
{
    int a = 1;
    char buffer[BUF_SIZE];
    char *token;
    char *bufline;
    if (check_for_file(path) == true) // FIX FOR SCAN_FILE !!!!
    {
        while(fgets(buffer, BUF_SIZE, ptr))
        {
            token = strtok(buffer, " ");
            if ((strtok(buffer, "\n")) != 0)
            {
                bufline = strtok(buffer, "\n");
                if (strcmp(token, flag)==0 || strcmp(bufline, flag)==0)
                {
                    return a;
                }
                else
                {
                    a++;
                }
            }
            else
            {
                a++;
            }
        }
    }
    else
    {
        red();
        printf("File: `%s` was not found.\n", path);
        reset();
        return -1;
    }
    return -1;
}
char *p_to_char(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
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
int p_to_int(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
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
unsigned int p_to_unsigned_int(FILE *ptr, char *flag)
{
    char *buffer;
    buffer = malloc(BUF_SIZE + sizeof(char *));
    char *key, *value;
    while (fgets(buffer, BUF_SIZE, ptr))
    {
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
