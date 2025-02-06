#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // 入力文字列を動的に確保

    char *input = ft_strdup("hello hello");
    if (!input)
    {
        fprintf(stderr, "Input allocation error\n");
        return 1;
    }

    // ASTのルートノードを確保
    t_ast *ast = allocation_ast();

    // 入力文字列を解析してASTに格納する
    separate_and_store_redirect_operators(ast, &input);


    // ここからASTの内容を表示して確認する
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
        printf("ctlope : ");
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
        printf("rdtope : ");
        switch (current->rdtope)
        {
            case e_rdtope_redirect_i:
                printf("<\n");
                break; 
            case e_rdtope_redirect_o:
                printf(">\n");
                break;
            case e_rdtope_heredoc_i:
                printf("<<\n");
                break;
            case e_rdtope_heredoc_o:
                printf(">>\n");
                break ;
            case e_rdtope_pipe:
                printf("|\n");
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