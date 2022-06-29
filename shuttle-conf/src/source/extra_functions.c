#include <stdbool.h>
#include <stdlib.h>
#include "../include/colors.h"
#include <sys/stat.h>
extern bool check_for_file(const char *path)
{
    struct stat buff;
    int cc = stat(path, &buff);
    if (cc==0) {return true; }
    else {return false; }
}

extern int arr_len(char **arr)
{
    int i;
    for (i = 0; arr[i] != NULL; i++)
    {
        ;
    }
    return i;
}
extern bool touch(const char *path)
{
    FILE *ptr;
    if((ptr = fopen(path, "a"))==0)
    {
        return true;
    } else
    {
        return false;
    }
}


void crash(char *str)
{
    red();
    printf(str);
    abort();
}
