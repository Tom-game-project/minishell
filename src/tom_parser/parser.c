#include <tom_parser.h>
#include <stdlib.h>
#include <stdbool.h>

#include "private.h"
#include "list.h"
#include "libft.h"
#include "strtools.h"

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

t_parse_result	tom_parser(t_ast **ast, char *input)
{
	(void) ast;
	(void) input;

	return (e_result_ok);
}
