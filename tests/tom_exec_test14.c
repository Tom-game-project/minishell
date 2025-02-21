
#include "../src/exec/heredoc/heredoc.h"
#include "exec.h"
#include <fcntl.h>
#include <unistd.h>

/// 隠しファイルを生成する関数のテスト
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test14.c
/// ```
int main()
{
	int rw_fd[2];

	if (create_shadow_file(rw_fd) == -1)
		return (1);
	write(rw_fd[1], "hello world\n", 12);
	fd_write(rw_fd[0]);
	close(rw_fd[1]);
	close(rw_fd[0]);
	return (0);
}

