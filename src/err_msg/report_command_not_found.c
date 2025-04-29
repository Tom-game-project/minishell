#include "err_msg.h"
#include <stdlib.h>

/// TODO あとで関数の名前を変更する
int	report_command_not_found(char *cmd)
{
	print_error_format_string(cmd, ": command not found\n");
	exit(127);
}
