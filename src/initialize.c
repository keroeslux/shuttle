#include "./headers/log.h"
#include "./headers/parse.h"
#include "./headers/colors.h"
#include <stdio.h>
int main()
{
    FILE *ptr;
    reset();
    ptr = fopen("config", "r");
    char *sus = p_to_char(ptr, "Welkommen");
    printf("%s", sus);
}


