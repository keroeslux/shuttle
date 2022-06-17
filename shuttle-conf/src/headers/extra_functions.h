#include <sys/stat.h>


extern bool check_for_file(const char *path)
{
    struct stat buff;
    int cc = stat(path, &buff);
    if (cc==0) {return true; }
    else {return false; }
}
