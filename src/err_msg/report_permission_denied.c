#include "err_msg.h"
#include <stdlib.h>

/// TODO あとで関数の名前を変更する
///
/// exit_status が、126だったときに
int	report_permission_denied(char *cmd)
{
	print_error_format_string(cmd, ": Permission denied\n");
	exit(126);
}

