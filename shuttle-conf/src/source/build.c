#include <stdbool.h>
#include "../include/program_structs.h"
#include "../include/parse.h"
#include "../include/extra_functions.h"
const int count = arr_len(structs);

void can_build(const char *path, bool force)
{
    static char *arr[count];
    FILE *ptr = fopen(path, "r");
    for (int i = 0; structs[i] != NULL; i++)
    {
        if (scan_file(ptr, path, structs[i]) == true)
        {
            arr[i] = structs[i];
        }
    }
}    
