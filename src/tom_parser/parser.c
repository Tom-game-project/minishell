#include "parser.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "test_tools.h"

#include "tom_parser.h"

static
void nop (void *a)
{
	(void) a;
}

/// リストの中に
/// `<`, `>`, `|`, `||`, `&&`, `<<`, `>>`
/// が含まれていたらtrueを返却する
bool include_ope(t_str_list *lst)
{
	int i;
	char *table[7];

	i = 0;
	table[0] = "<";
	table[1] = ">";
	table[2] = "|";
	table[3] = "||";
	table[4] = "&&";
	table[5] = "<<";
	table[6] = ">>";
	while (i < 7)
       	{
		if (str_list_search_node(lst, ft_streq, table[i]) != NULL)
			return (true);
		i += 1;
	}
	return (false);

}

/// `(`で始まっているかどうかを調べる
bool startswith_open_paren(char *str)
{
	return (ft_strncmp(str, "(", 1) == 0);
}


/// 更にパース可能かどうかを調べる関数
bool is_parsable()
{
	char *table[7];

	table[0] = "<";
	table[1] = ">";
	table[2] = "|";
	table[3] = "||";
	table[4] = "&&";
	table[5] = "<<";
	table[6] = ">>";

	(void) table; // TODO 
	return (false);
}

/// 
t_ast *init_ast()
{
	t_ast *ast;

	ast = malloc(sizeof(t_ast));
	ast->arg = NULL;
	ast->left_ast = NULL;
	ast->right_ast = NULL;
	ast->ope = e_ope_none;
	return (ast);
}

int remove_ifs(t_str_list **lst) // 確保された領域なので、freeしてok
{
	t_str_list *ifs_lst;

	ifs_lst = NULL;
	str_list_push(&ifs_lst, " ");
	str_list_push(&ifs_lst, "\t");
	str_list_push(&ifs_lst, "\n");
	str_list_trim(lst, ifs_lst, free);
	str_list_clear(&ifs_lst, nop);
	return (0);
}

bool is_rdt_string(char *str)
{
	return (
		ft_streq(str, "<<") || \
		ft_streq(str, ">>") || \
		ft_streq(str, ">") || \
		ft_streq(str, "<")
	);
}

bool is_ope_string(char *str)
{
	return (
		ft_streq(str, "||") || \
		ft_streq(str, "|") || \
		ft_streq(str, "&&")
	);
}


t_operator str2ope(char *str)
{
	if (ft_streq(str, "<<"))
		return (e_ope_heredoc_i);
	else if (ft_streq(str, ">>"))
		return (e_ope_heredoc_o);
	else if (ft_streq(str, "|"))
		return (e_ope_pipe);
	else if (ft_streq(str, "||"))
		return (e_ope_or);
	else if (ft_streq(str, "&&"))
		return (e_ope_and);
	else if (ft_streq(str, "<"))
		return (e_ope_redirect_i);
	else if (ft_streq(str, ">"))
		return (e_ope_redirect_o);
	else
		return (e_ope_none);
}

t_parse_result	tom_parser_lexed(t_ast **ast, t_str_list *input)
{
	// TODO とりあえずエラー文が出力されないようにvoidつけとく
	(void) ast;
	(void) input;
	int index;
	t_ast *orig;

	orig = *ast;
	remove_ifs(&input);
	index = str_list_search_index(input, is_ope_string);
	//debug_dprintf(STDERR_FILENO, "hello world %d \n", index);
	if (index != -1) // 何かしら見つけた
	{
		t_str_list *left_input;
		t_str_list *right_input;
		// L ope R
		char *ope_str;
		ope_str = str_list_pop(&input, index);
		//debug_dprintf(STDERR_FILENO,"str \"%s\"\n", ope_str);
		left_input = str_list_cut(&input, index - 1);
		right_input = input;
		debug_dprintf(STDERR_FILENO, "left input\n");
		str_list_print(left_input);
		debug_dprintf(STDERR_FILENO, "right input\n");
		str_list_print(right_input);
		orig->left_ast = init_ast();
		tom_parser_lexed(&orig->left_ast, left_input);
		orig->right_ast = init_ast();
		orig->ope = str2ope(ope_str);
		tom_parser_lexed(&orig->right_ast, right_input);
		return (e_result_ok);
	}
	index = str_list_search_index(input, is_rdt_string);
	if (index != -1) // 何かしら見つけた
	{
		t_str_list *left_input;
		t_str_list *right_input;
		// L ope R
		// ope LR
		char *ope_str;
		ope_str = str_list_pop(&input, index);
		left_input = str_list_cut(&input, index - 1);
		right_input = input;
		//debug_dprintf(STDERR_FILENO, "left input\n");
		//str_list_print(left_input);
		//debug_dprintf(STDERR_FILENO, "right input\n");
		//str_list_print(right_input);
		remove_ifs(&right_input);
		orig->arg = str_list_cut(&right_input ,0);
		orig->left_ast = NULL;
		orig->right_ast = init_ast();
		str_list_concat(&left_input, right_input);
		tom_parser_lexed(&orig->right_ast, left_input);
		orig->ope = str2ope(ope_str);
		return (e_result_ok);
	}
	if (
		str_list_len(input) == 1 && \
		startswith_open_paren(str_list_get_elem(input, 0))
	)
	{
		char *str;
		char *cutstr;

		str = str_list_get_elem(input, 0);
		cutstr = ft_substr(str, 1, ft_strlen(str) - 2);
		orig->left_ast = init_ast();
		orig->ope = e_ope_paren;
		tom_parser(cutstr, &orig->left_ast);
		free(cutstr);
		return (e_result_ok);
	}
	/// すべての条件式に入らなかった場合
	orig->arg = input;
	orig->ope = e_ope_none;
	return (e_result_ok);
}

t_parse_result	tom_parser(char *input, t_ast **ast)
{
	t_str_list *lexed;

	*ast = init_ast();
	lexed = lexer(input);
	tom_parser_lexed(ast, lexed);
	return (e_result_ok);
}

