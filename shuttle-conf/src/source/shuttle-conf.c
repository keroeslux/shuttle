#include "../include/argparse.h"
#include "../include/parse.h"
#include "../include/build.h"
#include "../include/extra_functions.h"
#include "../include/colors.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void help_menu()
{
    printf("FIX THIS\n");
}

void handle_args(int argc, char **argv)
{
    bool vb = false;
    bool verbose = parse_flag(argc, argv, "-v", "--verbose");
    bool help = parse_flag(argc, argv, "-h", "--help");
    bool force = parse_flag(argc, argv, "-f", "--force");
    char *config_file = parse_arg(argc, argv, "-c", "--config-file");
    if (verbose == true)
    {
        vb = true;
    }
    else if (help == true)
    {
        help_menu();
    }
    else if (config_file != (char*)EXIT_FAILURE)
    {
        FILE *ptr = fopen(config_file, "r");
        if (check_for_file(config_file) == true)
        {
            can_build(config_file, force);
        }
        else
        {
            red();
            printf("File: %s was not found.", config_file);
        }
    }
    else
    {
        puts("No option specified!");
    }
}

int main(int argc, char **argv)
{
#ifdef _WIN32
    puts("Windows is not supported by Shuttle-Conf Or Any Shuttle product");
    abort();
#elif __APPLE__
    puts("MacOSX is not supported by Shuttle-Conf Or Any Shuttle Product");
    abort();
#else
    handle_args(argc, argv);
#endif
}

