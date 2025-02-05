

// make vtest TEST_FILE=tests/kaara_parser_test/separate_and_store_cmd_args_test.c

#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(void)
{
 	char *input = ft_strdup("kaaara $(ls -la) \"k$(echo hello)aara\" 0613 tom boy");
	if (!input)
	{
		fprintf(stderr, "Input allocation error\n");
		return 1;
	}

//-----------------------------------------------------------------

	t_ast *ast = allocation_ast();
	separate_and_store_cmd_args(ast, &input);
	printf("=== ASTの内容 ===\n");
	t_ast *current = ast;
	int idx = 0;
	while (current != NULL)
	{
		printf("AST node %d:\n", idx);
		if (current->cmd != NULL)
			printf("  cmd      : %s\n", current->cmd);
		else
			printf("  cmd      : (null)\n");
		printf(" ---- arg ---- \n");
		str_list_print(current->arg);
		printf("  ctlope   : ");
		switch (current->ctlope)
		{
			case e_ctlope_and:
				printf("&&\n");
				break;
			case e_ctlope_or:
				printf("||\n");
				break;
			default:
				printf("NONE\n");
				break;
		}
				printf("  ctlope   : ");
		switch (current->ctlope)
		{
			case e_ctlope_and:
				printf("&&\n");
				break;
			case e_ctlope_or:
				printf("||\n");
				break;
			default:
				printf("NONE\n");
				break;
		}
		current = current->right_ast;
		idx++;
	}
	return 0;
}