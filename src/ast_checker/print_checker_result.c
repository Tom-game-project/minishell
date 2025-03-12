#include "ast_checker.h"
#include "test_tools.h"
#include <unistd.h>
#include "libft.h"

/// TODO 書き換える！！！
bool    print_checker_result(t_syntax_result result)
{
    if (result == e_syntax_ok)
        return (true);
    else if (result == e_ctl_near_unexpected_token_and)
        ft_putstr_fd("minishell : near_unexpected_token_and\n", STDERR_FILENO);
    else if (result == e_ctl_near_unexpected_token_or)
        ft_putstr_fd("minishell : near_unexpected_token_or\n", STDERR_FILENO);
    else if (result == e_rdt_near_unexpected_token_pipe)
        ft_putstr_fd("minishell : near_unexpected_token_pipe\n", STDERR_FILENO);
    else if (result == e_rdt_near_unexpected_token_newline)
        ft_putstr_fd( "minishell : near_unexpected_token_newline\n", STDERR_FILENO);
    else if (result == e_rdt_near_unexpected_token_rdt)
        ft_putstr_fd( "minishell : near_unexpected_token_rdt\n", STDERR_FILENO);
    else if (result == e_syntax_near_unexpected_token_string)
        ft_putstr_fd( "minishell : near_unexpected_token_string\n", STDERR_FILENO);
    return (false);
}
