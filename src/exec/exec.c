
#include "dict.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>


//int exec_(t_ast *ast, t_str_dict *envp_dict)
//{
//	int exit_status;
//
//	exit_status = 0;
//	return (exit_status);
//}

int exec(t_ast *ast, t_str_dict *envp_dict)
{
	int exit_status;

	exit_status = 0;
	if (ast->ope == e_ope_none)
	{
		//

	}
	else if (ast->ope == e_ope_pipe)
	{
		//
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
	}
	return (exit_status);
}
