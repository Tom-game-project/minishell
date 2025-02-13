#ifndef UTILS_H
#define UTILS_H

#include "parser.h"

int execve_wrap(t_ast *ast, t_str_dict *envp_dict);

int and_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int none_proc(t_ast *ast, t_str_dict *envp_dict,int input_fd);

int or_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int pipe_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd);

#endif
