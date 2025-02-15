#ifndef UTILS_H
#define UTILS_H

#include "exec.h"
#include "parser.h"

int execve_wrap(t_exec_args *args);

int and_proc(t_exec_args *args);

int none_proc(t_exec_args *args);

int or_proc(t_exec_args *args);

int pipe_proc(t_exec_args *args);

#endif
