# ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include <unistd.h>
# include <stdbool.h>

//checker.c
bool    check_logical_operator(t_ast *ast, int exit_status);

bool	check_update_arg(t_ast *ast);

# endif