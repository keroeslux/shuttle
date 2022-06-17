#include "../include/colors.h"

void warning(const char *warning)
{
    yellow();
    puts(warning);
    reset();
}
void info(const char *info)
{
    green();
    puts(info);
    reset();
}
void fatal(const char *fatal)
{
    red();
    puts(fatal);
    reset();
}
void error(const char *error)
{
    red();
    puts(error);
    reset();
}


