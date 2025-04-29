#include "err_msg.h"
#include <stdlib.h>

/// TODO
int	report_no_such_file_or_directory(char *cmd)
{
	print_error_format_string(cmd, ": Is not a file or directory\n");
	exit(126);
}

