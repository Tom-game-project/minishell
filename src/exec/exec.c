#include "exec.h"

<<<<<<< Updated upstream
<<<<<<< Updated upstream
exec(ast, envp);
||||||| Stash base
||||||| Stash base
=======
#include "dict.h"
>>>>>>> Stashed changes
#include "parser.h"
#include <unistd.h>
#include <stdio.h>

int exec(t_ast *ast, t_str_dict *envp_dict)
{
<<<<<<< Updated upstream
    
    return (exit_status);
}
=======
#include "dict.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>

int exec(t_ast *ast, t_str_dict *envp_dict)
{
	int exit_status;

	exit_status = 0;
	if (ast->ope == e_rdtope_none)
	{
	}
	else if (ast->ope == e_rdtope_pipe)
	{
		//
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
	}
	return (exit_status);
}
>>>>>>> Stashed changes
||||||| Stash base
    
    return (exit_status);
}
=======
	int exit_status;

	exit_status = 0;
	if (ast->ope == e_rdtope_none)
	{
	}
	else if (ast->ope == e_rdtope_pipe)
	{
		//
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
	}
	return (exit_status);
}
>>>>>>> Stashed changes
