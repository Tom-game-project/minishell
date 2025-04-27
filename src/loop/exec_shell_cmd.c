#include "dict.h"
#include "tom_parser.h"
#include "libft.h"
#include "parser.h"
#include "loop_private.h"
#include <limits.h>

// for test
#include "test_tools.h"

static t_ast	*parser_wrap(char *input)
{
	t_ast	*ast;

	ast = NULL;
	if (e_result_paren_not_closed_err == tom_parser(input, &ast ))
	{
		ft_putstr_fd("minishell : syntax error\n", STDERR_FILENO);
		return (NULL);
	}
	else
	{
		debug_dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
	}
	return (ast);
}

/// コマンドの実行を試みexit statuswを更新する関数
///
/// 入力文字列が`INT_MAX`を超えたときは、内部のリストが扱い切れないので
/// errorを吐く
///
/// 関数内部でexec関数が実行されたら`1`を返却します
int	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status)
{
	t_ast	*ast;
	int err;

	if (INT_MAX < ft_strlen(str))
	{
		ft_putstr_fd("minishell : too long input\n", STDERR_FILENO);
		*exit_status = 1;
		return (0);
	}
	ast = parser_wrap(str);
	err = exec_ast(ast, env_dict, exit_status);
	clear_ast(&ast);
	return (err);
}
