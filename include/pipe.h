#ifndef PIPE_H
# define PIPE_H

#include "parser.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*infile_name;
	char	*outfile_name;
	int		infile_fd;
	int		outfile_fd;
	t_ast	*head;
	char	**path;
	char	*full_path;
	int		pipe_fd[2];
	char	**execve_argv;
}	t_pipex;

int	pipex(t_ast	*ast, char *const *envp);

//allocation_pipex.c
t_pipex	*allocation_pipex(void);

//allocation_and_cpy.c
char	*allocation_and_cpy(t_pipex *pipex, const char *src);

//store_args_in_struct.c
void	store_args_in_struct(t_pipex *pipex, int argc, char **argv);

//get_path_from_envp.c
char	**get_path_from_envp(char *const *envp, t_pipex *pipex);

//spawn_child_and_process.c
int	spawn_child_and_process(t_ast *ast, t_pipex	*pipex, char *envp[]);

//false_fork.c
void	false_fork(t_pipex	*pipex);

//validate_cmd_full_path.c
char	*validate_cmd_full_path(t_pipex *pipex, char *cmd);

//chiled_process.c
void	chiled_process(t_pipex *pipex, char *const *envp, int cmdc_i);

//store_execve_argv.c
char	**store_execve_argv(t_pipex *pipex, char **cmd);

//voidexec_from_infile.c
void	from_infile(t_pipex *pipex);

//setup_filefd.c
void	setup_filefd(t_ast *ast, t_pipex *pipex);

//exec_setup_pipefd.c
void	setup_pipefd(t_ast *ast, t_pipex *pipex);

//exec_to_outfile.c
void	to_outfile(t_pipex *pipex);

//free_execve_argv.c
void	free_execve_argv(char **execve_argv);

//free_exit.c
int		free_exit(t_pipex	*pipex, int	exit_status);

#endif
