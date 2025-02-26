#ifndef UTILS_H
#define UTILS_H

#include "exec.h"

int execve_wrap(t_exec_args *args);

int and_proc(t_exec_args *args);

int none_proc(t_exec_args *args);

int or_proc(t_exec_args *args);

int pipe_proc(t_exec_args *args);

int exec_redirect_i_proc(t_exec_args *args);

int exec_redirect_o_proc(t_exec_args *args);

int exec_heredoc_o_proc(t_exec_args *args);

int paren_proc(t_exec_args *args);


int sequential_proc(t_exec_args *args, bool (*f)(int));

int exec_rdt_proc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *), // close
	int (*open_func)(char *),// open
	int (*inner_exec)(t_exec_args *, int) //
			// args        , fd
);

#endif
