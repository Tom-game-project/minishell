#include "ast_checker.h"
#include "dict.h"
#include "tom_parser.h"
#include "libft.h"
#include "parser.h"
#include "loop_private.h"
#include <limits.h>
#include <unistd.h>

// for test
#include "test_tools.h"

/// syntax error 発生時にはsyntax_err_flagにtrueがセットされる
static t_ast	*parser_wrap(char *input, bool *syntax_err_flag)
{
	t_ast	*ast;

	ast = NULL;
	*syntax_err_flag = e_result_paren_not_closed_err == tom_parser(input, &ast);
	if (*syntax_err_flag)
		ft_putstr_fd("minishell : syntax error\n", STDERR_FILENO);
	else
		debug_dprintf(STDERR_FILENO, "\ninput : %s\n\n", input);
	return (ast);
}

/// コマンドの実行を試みexit statusを更新する関数
///
/// 入力文字列が`INT_MAX`を超えたときは、内部のリストが扱い切れないので
/// errorを吐く
///
/// 関数内部でexec関数が実行されたら`1`を返却します
int	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status)
{
	t_ast	*ast;
	bool syntax_error_flag;
	t_syntax_result result;

	if (INT_MAX < ft_strlen(str))
	{
		ft_putstr_fd("minishell : too long input\n", STDERR_FILENO);
		*exit_status = 1;
		return (0);
	}
	ast = parser_wrap(str, &syntax_error_flag);
	if (syntax_error_flag == 1) // syntax error
	{
		*exit_status = 1;
		clear_ast(&ast);
		return (0);
	}
	result = ast_checker(ast);
	if (result == e_no_input)
	{
		clear_ast(&ast);
		return (0);
	}
	*exit_status = exec_ast(ast, env_dict, result);
	//debug_dprintf(STDERR_FILENO, "hello world\n");
	clear_ast(&ast);
	return (1);
}
