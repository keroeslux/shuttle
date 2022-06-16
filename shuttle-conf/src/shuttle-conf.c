#include "./headers/argparse.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
void handle_args(int argc, char **argv)
{
    bool verbose = parse_flag(argc, argv, "-v", "--verbose");
    bool help = parse_flag(argc, argv, "-h", "--help");
    char *config_file = parse_arg(argc, argv, "-c", "--config-file");
    if (verbose == true)
    {
        puts("murica");
    }
    puts(config_file);
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

