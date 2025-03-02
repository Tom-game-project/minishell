#include "../src/exec/heredoc/heredoc.h"
#include "list.h"
#include "exec.h"
#include "libft.h"
#include "parser.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "tom_parser_tools/tools.h"

t_ast *
parser_wrap(char *str)
{
    char *input = ft_strdup(str);
    t_ast *ast;
    ast = NULL;
    if (e_result_paren_not_closed_err == parser(&ast, input))
        printf("minishell : not close syntax\n");
    else
    {
        printf("\ninput : %s\n\n", input);
        print_ast(ast, 0);
    }
    free(input);
    return (ast);
}
/// here doc test 

int close_all_fds(t_int_list **node)
{
	t_anytype rvalue;
	// close all fds
	
	while (void_list_pop(node , 0, &rvalue) != -1)
	{
		close(rvalue.i32);
	}
	int_list_clear(node);
	return (0);
}


/// ```bash
/// make test TEST_FILE=tests/tom_heredoc_test01.c
/// ```
int heredoc_test()
{
	t_int_list *heredoc_fd_list;
	t_ast *ast;

	//ast = parser_wrap("<< EOF1 cat && (<< EOF2 cat) && << EOF3 cat");
	ast = parser_wrap("<< EOF1 << EOF2 && (<< EOF3)");


	int heredoc_count;

	heredoc_count = count_heredoc(ast);
	printf("heredoc_count %d\n", heredoc_count);


	heredoc_fd_list = NULL;
	heredoc_proc(ast, &heredoc_fd_list);

	t_int_list *p;
	p = heredoc_fd_list;
	while(p != NULL)
	{
		fd_write(
			p->ptr.i32,
			STDOUT_FILENO
		);
		p = p->next;
	}
	close_all_fds(&heredoc_fd_list); // ここでheredocに使ったすべてのfdを閉じる
	return (0);
}

int main()
{
	heredoc_test();
	return (0);
}

