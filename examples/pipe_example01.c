#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024


/// パイプを読む
#define PIPE_READ 0
/// パイプに書き込む
#define PIPE_WRITE 1


static int fd_write(int fd)
{
	char buf[BUF_SIZE];

	while(1)
	{
		memset(buf, '\0', BUF_SIZE); // ここでいちいち初期化を挟む必要アリ。
		if (read(fd, buf, BUF_SIZE) == 0)
			break ;
		write(STDOUT_FILENO, buf, BUF_SIZE);
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	int pid;
	char *echo_hello_ptr[] = {"ls", "-la", NULL};
	int pre_status;
	int pipe_fd[2];

	(void) argc;
	(void) argv;

	if (pipe(pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		execve("/usr/bin/ls", echo_hello_ptr, envp);
		exit(1);
	}
	else
	{
		close(pipe_fd[PIPE_WRITE]); // 親から子に書き込むことはない
						// 子から、pipeで送られて来るものを表示
		fd_write(pipe_fd[PIPE_READ]);
		close(pipe_fd[PIPE_READ]);
		waitpid(pid, &pre_status, WUNTRACED);
	}
	return (0);
}
