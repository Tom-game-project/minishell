#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// make vtest TEST_FILE=tests/kaara_parser_test/

int main(void)
{
    // 入力文字列を動的に確保

    char *input = ft_strdup("hello >> \"hello > hello\"");
    if (!input)
    {
        fprintf(stderr, "Input allocation error\n");
        return 1;
    }

    // ASTのルートノードを確保
    t_ast *ast = allocation_ast();

    // 入力文字列を解析してASTに格納する
    t_str_list  *next_input;
    next_input = separate_and_store_redirect_operators(ast, &input);

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
        switch (current->ope)
        {
            case e_ope_and:
                printf("&&\n");
                break;
            case e_ope_or:
                printf("||\n");
                break;
            default:
                printf("NONE\n");
                break;
        }
        printf("rdtope : ");
        switch (current->ope)
        {
            case e_ope_redirect_i:
                printf("<\n");
                break; 
            case e_ope_redirect_o:
                printf(">\n");
                break;
            case e_ope_heredoc_i:
                printf("<<\n");
                break;
            case e_ope_heredoc_o:
                printf(">>\n");
                break ;
            case e_ope_pipe:
                printf("|\n");
                break;            
            default:
                printf("NONE\n");
                break;
        }
        current = current->right_ast;
        idx++;
        printf("--------next_input-------\n");
		str_list_print(next_input);
    }
    return 0;
}