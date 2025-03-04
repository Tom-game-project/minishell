#include "dict.h"
#include "expand_string.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "exec.h"

/// ```bash
/// make test TEST_FILE=tests/tom_parser_expand_string_test04.c
/// ```
int main()
{
	//
	int fd;
	int new_fd;

	t_str_dict *d;

	d = NULL;
	// 環境変数を模したもの
	str_dict_add(
		&d,
		ft_strdup("PATH"),
		ft_strdup("HELLO_VALUE"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("$"),
		ft_strdup("PID"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("?"),
		ft_strdup("EXIT STATUS"), 
		free
	);
	fd = open("infile", O_RDONLY, 0644);
	new_fd = heredoc_expand_string_via_fd(fd, d);
	fd_write(new_fd, STDOUT_FILENO);
	close(fd);
	close(new_fd);
	str_dict_clear(&d, free, free);
	return (0);
}
