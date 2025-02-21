# include "ast_checker.h"
# include <stdio.h>

bool    print_checker_result(t_syntax_result result)
{
    if (result == e_syntax_ok)
    {
        printf("np");
        return (true);
    }
    else if (result == e_ctl_near_unexpected_token_and)
        printf("minishell : near_unexpected_token_and\n");
    else if (result == e_ctl_near_unexpected_token_or)
        printf("minishell : near_unexpected_token_or\n");
    else if (result == e_rdt_near_unexpected_token_newline)
        printf("minishell : near_unexpected_token_newline\n");
    else
        printf("minishell : else error");
    return (false);
}
