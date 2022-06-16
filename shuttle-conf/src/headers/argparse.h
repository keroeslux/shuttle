#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
bool parse_flag(int size, char *argv[], char *flag)
{
    int temp = 0;
    while(temp<size)
    {
        if(strcmp(argv[temp], flag)==0)
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
bool *parse_arg(int size, char **argv, char *flag, char *out)
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
            if(strcmp(argv[temp],flag)==0)
            {
                temp+=1;
                if(temp>=size)
                {
                    return false;
                }
                else
                {
                    out = argv[temp];
                }
            }
            else
            {
                ++temp;
            }
        }
    }
}
