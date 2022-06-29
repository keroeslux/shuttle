#ifndef BUILD_H
#define BUILD_H
#include <stdbool.h>
#include <stdlib.h>
#include "program_options.h"
#include "parse.h"
#include "extra_functions.h"
#include "build.h"

void build(char **arr);
void dump_arr(char **arr);
void can_build(const char *path, bool force);

#endif
