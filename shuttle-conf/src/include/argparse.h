#ifndef ARGS_H
#define ARGS_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
bool parse_flag(int size, char *argv[], char *flag_short, char *flag_long)
{
    int temp = 0;
    while(temp<size)
    {
        if(strcmp(argv[temp], flag_short)==0 || strcmp(argv[temp], flag_long)==0)
        {
            return true;
        }
        else
        {
            ++temp;
        }
    }
    return false;
}
char *parse_arg(int size, char **argv, char *flag_short, char *flag_long)
{
    if((argv[0]) == NULL)
    {
        exit(1);
    }
    else
    {
        int temp = 0;
        while(temp<size)
        {
            if(strcmp(argv[temp],flag_short)==0 || strcmp(argv[temp], flag_long)==0)
            {
                temp+=1;
                if(temp>=size)
                {
                    exit(1);
                }
                else
                {
                    return argv[temp]; 
                }
            }
            else
            {
                ++temp;
            }
        }
    }
    return (char *)EXIT_FAILURE;
}
char *parse_args(int size, char **argv, char *flag_short, char *flag_long, int count)
{
    char *args[sizeof(argv) / sizeof(argv[0])];
    char *ptr;
    if((argv[0]) == NULL)
    {
        exit(1);
    }
    else
    {
        int temp = 0;
        while(temp<size)
        {
            if(strcmp(argv[temp],flag_short)==0 || strcmp(argv[temp], flag_long)==0)
            {
                temp+=1;
                if(temp>=size)
                {
                    exit(1);
                }
                else
                {
                    int i;
                    while(i<count)
                    {
                        args[i] = argv[temp];
                        temp+=1;
                        i+=1;
                    }
                    ptr = &args;
                    return ptr;
                }
            }
            else
            {
                ++temp;
            }
        }
    }
    return (char *)EXIT_FAILURE;
}

#endif
