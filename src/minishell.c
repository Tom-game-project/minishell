#include "sig.h"


#include <stdio.h>
//int main(int argc, char *argv[], char *envp[])
int main(void)
{
	int exit_status;

	//signal_handler(signal);
	//exit_status = main_loop(envp);
	exit_status = 0;
	// signal_handler(signal);
	// exit_status = main_loop(envp);
	printf("%d", exit_status);
	return (exit_status);
}
