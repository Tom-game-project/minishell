#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include "parser.h"

int my_dprintf(int fd,const char *format, ...) __attribute__((format(printf, 2, 3)));

int print_ast(t_ast *ast, int depth);
#endif
