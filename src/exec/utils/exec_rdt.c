#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int exec_rdt_proc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *), // close
	int (*open_func)(char *),// open
	int (*inner_exec)(t_exec_args *, int) //
			// args        , fd
)
{
	char *str;
	int fd;

	close_fd(args);
	str = str_list_get_elem(args->ast->arg, 0);
	if (str == NULL) // NULL
	{
		// TODO:もし見つからなければ
		// ここで見つからないのはありえない
		// Error
	}
	fd = open_func(str);
	if (fd == -1)
	{
		perror("minishell"); // TODO
		return (1);
	}
	inner_exec(args, fd);
	//close(fd);
	return (0);
}

int exec_rdt_proc_heredoc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *), // close
	int (*inner_exec)(t_exec_args *, int) //
			// args        , fd
)
{
	int fd;

	close_fd(args);
	fd = int_list_pop(args->heredoc_fd_list, 0);
	if (fd == -1)
	{
		perror("minishell"); // TODO
		return (1);
	}
	inner_exec(args, fd);
	return (0);
}
