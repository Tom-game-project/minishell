
#include "built_in.h"
#include "exec.h"
#include "libft.h"
#include "list.h"
#include "parser.h"
#include "pipe.h"
#include "sig.h"


#include <stdio.h>
//int main(int argc, char *argv[], char *envp[])
int main(void)
{
	int exit_status = 1;

	// signal_handler(signal);
	// exit_status = main_loop(envp);
    printf("%d", exit_status);
	return (exit_status);
}
//
//int signal_handler(void)
//{
//	ctl_c
//	ctl_d
//	ctl_sra
//	return (0);
//}
