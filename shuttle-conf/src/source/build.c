#include <stdbool.h>
#include <stdlib.h>
#include "../include/program_options.h"
#include "../include/parse.h"
#include "../include/extra_functions.h"
#include "../include/build.h"
#define BUFFERSIZE 512
char *options[4] = {"Vim", "Zsh", "Fish", "Bash"};



void build(char **arr) {printf("building...");}

void dump_arr(char **arr)
{
    int i = 0;
    while(arr[i] != NULL)
    {
        printf("%s ", arr[i]);
        i++;
    }
}

void can_build(const char *path, bool force)
{
    char *buffer;
    char *arr[BUFFERSIZE];
    FILE *ptr = fopen(path, "r");
    for (int i = 0; i<4;i++)
    {
        buffer = options[i];
        if (scan_file(ptr, path, buffer)==true)
        {
            arr[i] = buffer;
        }
    }
    if (force == true)
    {
        build(arr);
    }
    else
    {
        char yn;
        printf("Located: ");
        dump_arr(arr);
        printf(":: Continue? [y\\n]: ");
        scanf("%c",&yn);
        if (yn == 'y')
        {
            build(arr);
        }
        else
        {
            return;
        }
    }
}
