
#include "built_in.h"

int main(int argc, char *argv[], char *envp[])
{
	int exit_status;

	signal_handler(signal);
	exit_status = main_loop(envp);
	return (exit_status);
}

int signal_handler(void)
{
	ctl_c
	ctl_d
	ctl_sra
	return (0);
}

main_loop(char *envp[])
{
	int		exit_status;
    char	*input;
	t_ast	*ast;

    while ((input = readline("Enter command: ")) != NULL)
	{
        if (*input)
            add_history(input);
		ast = parser();
		temp(ast, envp);//execveを含む実行部
		clear_ast(ast);
        free(input);
    }
    return (exit_status);
}
