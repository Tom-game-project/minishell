# include "ast_checker.h"
# include <stdio.h>

bool    print_checker_result(t_syntax_result result)
{
    if (result == e_syntax_ok)
        return (true);
    else if (result == e_ctl_near_unexpected_token_and)
        perror("minishell : near_unexpected_token_and\n");//fprintfを作成したら変更
    else if (result == e_ctl_near_unexpected_token_or)
        perror("minishell : near_unexpected_token_or\n");
    else if (result == e_rdt_near_unexpected_token_pipe)
        perror("minishell : near_unexpected_token_pipe\n");
    else if (result == e_rdt_near_unexpected_token_newline)
        perror("minishell : near_unexpected_token_newline\n");
    else
        perror("minishell : else error");
    return (false);
}
