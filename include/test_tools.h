#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include "parser.h"

/// this file is for debug mode
///
/// function can use while develop even if it forbidden


int debug_dprintf(int fd,const char *format, ...) __attribute__((format(printf, 2, 3)));

int print_ast(t_ast *ast, int depth);

int debug_getpid();

int debug_getppid();

#endif
