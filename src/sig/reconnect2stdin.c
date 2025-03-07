#include <unistd.h>
#include <fcntl.h>


/// シグナル発生で切断された標準入力を復元させる
///
void
reconnect_stdin(int *exit_status)
{
	if (*exit_status == 0)
		write(STDOUT_FILENO, &"\n", 1);
	*exit_status = 130;
	// ttyデバイスにstdinを再接続する
	int tty_fd = open("/dev/tty", O_RDONLY);
	if (tty_fd != -1)
	{
		dup2(tty_fd, STDIN_FILENO);
		close(tty_fd);
	}
}

