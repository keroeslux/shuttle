#include <sys/stat.h>
#include <stdbool.h>
#include "../include/colors.h"
extern bool check_for_file(const char *path)
{
    struct stat buff;
    int cc = stat(path, &buff);
    if (cc==0) {return true; }
    else {return false; }
}


void crash(char *str)
{
    red();
    printf(str);
    abort();
}
