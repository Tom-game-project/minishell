#include <linux/limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#define BUF_SIZE 1024
#define PIPE_READ 0
#define PIPE_WRITE 1


int	read_infile(int *input_fd, char *filename)
{
	if (filename != NULL)
	{
		if (*input_fd != STDIN_FILENO) // 間違って予約済みのfdを閉じないようにする
			close(*input_fd);
		*input_fd = open(filename, O_RDONLY);
		if (*input_fd == -1)
			(perror(filename), exit(1));
		return (0);
	}
	return (1);
}

static int fd_write(int fd)
{
	char buf[BUF_SIZE];

	while(1)
	{
		memset(buf, '\0', BUF_SIZE);
		if (read(fd, buf, BUF_SIZE) == 0)
			break ;
		write(STDOUT_FILENO, buf, BUF_SIZE);
	}
	return (0);

}
/// パイプを使ったファイルの表示
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
       	(void)argv;
	int pipe_fd[2];
	int pid;
	int status;
	int input_fd;
	char *cat_ptr[] = {"cat", NULL};

	if (pipe(pipe_fd) == -1)
	{
		perror("example:");
		return (1);
	}
		read_infile(&input_fd, "infile");
	pid = fork();
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_READ]);
		execve("/usr/bin/cat", cat_ptr, envp);
		exit(0);
	}
	else
	{
		close(pipe_fd[PIPE_WRITE]);
		fd_write(pipe_fd[PIPE_READ]);
		close(pipe_fd[PIPE_READ]);
		waitpid(pid, &status, WUNTRACED);
	}
	return (WEXITSTATUS(status));
}
