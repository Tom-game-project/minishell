main_loop(char *envp[])
{
	int		exit_status;
    char	*input;

    while ((input = readline("Enter command: ")) != NULL)
	{
        if (*input)
            add_history(input);
		temp(envp);//execveを含む実行部
		clear_ast(ast);
        free(input);
    }
    return (exit_status);
}
