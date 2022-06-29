#ifndef PROGRAM_STRUCTS_H
#define PROGRAM_STRUCTS_H
#include <stdbool.h>

struct Vim
{
    bool termguicolors;
    bool number;
    bool autoindent;
    bool ttyfast;
    bool syntax;
    bool nocompatible;
    int tabstop;
    int shiftwidth;
    char mapleader;
    char *encoding;
};

struct Fish
{
    bool greeting;
    bool neofetch;
    char *prompt;
};

struct Bash
{
    bool neofetch;
    char *prompt;
};

struct Zsh
{
    bool neofetch;
    char *prompt;
};

#endif
