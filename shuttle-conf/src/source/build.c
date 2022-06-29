#include <stdbool.h>
#include <stdlib.h>
#include "../include/program_options.h"
#include "../include/parse.h"
#include "../include/extra_functions.h"
#include "../include/build.h"
const char *options[4] = {"Vim", "Zsh", "Fish", "Bash"};

#define count arr_len(options)


void build(char **arr) {printf("building...");}

void dump_arr(char **arr)
{
    int i = 0;
    while(arr[i] != NULL)
    {
        printf("%s, ", options[i]);
        i++;
    }
}

void can_build(const char *path, bool force)
{
    char *arr[count];
    FILE *ptr = fopen(path, "r");
    for (int i = 0; options[i] != NULL; i++)
    {
        if (scan_file(ptr, path, options[i]) == true)
        {
            printf("ahhh");
            arr[i] = options[i];
        }
    }
    if (force == true)
    {
        build(arr);
    }
    else
    {
        char buff[3];
        printf("Found the following: ");
        dump_arr(arr);
        printf(" :: continue? [y\\n]: ");
        fgets(buff, 3, stdin);
        if (buff == 'y')
        {
            build(arr);
        }
        else
        {
            abort();
        }
    }
}
