#ifndef PARSE_H
#define PARSE_H
#define BUF_SIZE 256
#include <string.h>
#include <stdio.h>
char buffer[BUF_SIZE];
char *key;
char *value;
char *parse(FILE *fp, char *flag)
{
    while (fgets(buffer, BUF_SIZE, fp))
    {
        key = strtok_r(buffer, "=", &value);
        if (strcmp(key, flag) == 0)
        {
            return (value);
        }
    }
}
#endif
