#include "../src/exec/heredoc/heredoc.h"
// #include "list.h"
#include "exec.h"
#include <unistd.h>

/// リダイレクト
/// ```bash
/// make test TEST_FILE=tests/tom_heredoc_test00.c
/// ```
int main()
{
	// t_str_list *a;
	int rw_fd[2];

	if (create_shadow_file(rw_fd) == -1)
	{
		return (1);
	}
	read_heredocline("EOF\n", rw_fd[1]);
	fd_write(rw_fd[0]);
	close(rw_fd[0]);
	close(rw_fd[1]);
	return (0);
}
