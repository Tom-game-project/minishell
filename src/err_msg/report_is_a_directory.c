#include "err_msg.h"
#include <stdlib.h>

/// TODO
int	report_is_a_directory(char *cmd)
{
	print_error_format_string(cmd, ": Is a directory\n");
	exit(126);
}
