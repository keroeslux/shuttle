#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdbool.h>
#define BUF_SIZE 256
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "./extra_functions.h"
#include "./log.h"
#include "./colors.h"
#include <stdarg.h>
static bool scan_file(FILE *ptr, const char *path, char *flag);
static int line_num(FILE *ptr, const char *path, char *flag);
static char *p_to_char(FILE *ptr, char *flag);
static int p_to_int(FILE *ptr, char *flag);
static unsigned int p_to_unsigned_int(FILE *ptr, char *flag);
static int var_line_number(int count, FILE *ptr, const char path, char*, ...)
static bool scan_yes_no(FILE *ptr, char *flag);

#endif
