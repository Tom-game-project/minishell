#ifndef BUILT_IN_H
#define BUILT_IN_H

#include "dict.h"

/// TODO:
/// この関数は最終的に削除する必要がある
int say_hello();

int return_one_func();

// src/built-in/cd.c
int built_in_cd(char *path);

int built_in_env(char *envp[]);
#endif
