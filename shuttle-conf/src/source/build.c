#include <stdbool.h>
#include <stdlib.h>
#include "../include/program_structs.h"
#include "../include/parse.h"
#include "../include/extra_functions.h"
#define count arr_len(structs)

void build(char **arr) {}

void dump_arr(char **arr)
{
    int i = 0;
    while(arr[i] != NULL)
    {
        printf("%s, ", arr[i]);
        i++;
    }
}

void can_build(const char *path, bool force)
{
    char *arr[count];
    FILE *ptr = fopen(path, "r");
    for (int i = 0; structs[i] != NULL; i++)
    {
        if (scan_file(ptr, path, structs[i]) == true)
        {
            arr[i] = structs[i];
        }
    }
    if (force == true)
    {
        build(arr);
    }
    else
    {
        char buff[3];
        printf("Found the following: %s :: continue? [y\\n]: ", dump_arr(arr));
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
}
}
}
}    
