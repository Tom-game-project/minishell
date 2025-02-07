
# include "parser.h"
#include <stdbool.h>

bool    find_env_syntax(t_str_list *head);
bool    expand_env(t_str_list *head);
bool    find_str_syntax(t_str_list *head);
bool    triming_string(t_str_list *head);

bool	check_update_arg(t_ast *ast)
{
	if (ast->arg == NULL)
		return (false);
	else if (find_env_syntax(ast->arg) == false)//環境変数のcheckと展開
	{
		expand_env(ast->arg);//envを展開またはsubshellへ
		return (false);
	}
	else if (find_str_syntax(ast->arg) == false)
	{
		triming_string(ast->arg);//""、''、()を切り出す
		return (false);
	}
	return (true);
}

//exitstatusどうする問題は引き継がれないので問題なし。
// expand_string(str, d);