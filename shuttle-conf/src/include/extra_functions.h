#ifndef EXTRA_H
#define EXTRA_H
#include <sys/stat.h>
#include <stdbool.h>
extern bool check_for_file(const char *path);
extern bool touch(const char *path);
extern int arr_len(char **arr);
#endif
