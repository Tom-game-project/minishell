#include "exec.h"
#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>

#include <stdbool.h>


static bool exit_status_has_err(int exit_status)
{
	return (exit_status != 0);
}

int or_proc(t_exec_args *args)
{
	return (sequential_proc(args, exit_status_has_err));
}
