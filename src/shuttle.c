#include "headers/parse.h"
#include "headers/argparse.h"
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
    FILE *file;
    file = fopen("/usr/share/shuttle/config", "r");
    char *sugoma = parse(file, "RESOLUTION");
    puts(sugoma);
    char *sus;
    bool c = parse_arg(argc, argv, "-sus", sus);
    puts(sus);
    if (c == true)
    {
        printf("AMongus!");
    }
    else
    {
        printf("nomongus :(");
    }
}


