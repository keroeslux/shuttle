#include "./headers/parse.h"


void scan_and_exec(FILE *ptr)
{
    scan_file(ptr, "Vim");
    scan_file(ptr, "Fish");
    scan_file(ptr, "Bash");
    scan_file(ptr, "Zsh");
}
