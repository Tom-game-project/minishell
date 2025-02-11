# ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include "dict.h"
# include <unistd.h>
# include <stdbool.h>

// src/exec/exec.c

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int exec2(t_ast *ast, t_str_dict *envp_dict, int input_fd, int ppid);

//checker.c
// bool    check_logical_operator(t_ast *ast, int exit_status);

// bool	check_update_arg(t_ast *ast);

int fd_write(int fd);

# endif
