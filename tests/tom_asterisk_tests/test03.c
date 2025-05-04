#include "dict.h"
#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#include "expand_string.h"

void
free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

int
print_token_list_node(int index, t_anytype token)
{
	(void) index;

	if (token.ex_token->token_type == e_word)
	{
		return (debug_dprintf(STDERR_FILENO, "[e_word] %s\n", token.ex_token->str));
	}
	else 
	{
		return (debug_dprintf(STDERR_FILENO, "[e_asterisk] %s\n", token.ex_token->str));
	}
}

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test03.c
/// ```
int main()
{
	//char *str;
       	char *rule_str = "$HELLO/*this/is*/t*om";
	t_str_dict *d;

	//char *str = "aaa$HELLO'$WORLD'$HELLOaaa|aaa";
	//char *str = "aaa'$WORLD'$HELLOaaa";
	//char *str = "\"*\"*'*'";
	debug_dprintf(STDERR_FILENO, "test case: %s\n", rule_str);
	char *str = "???$HELLO$$?$?HELLO$?$WO";
	//char *str = "$$$";
	d = NULL;
	// 環境変数を模したもの
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("HELLO_VALUE"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("$"),
		ft_strdup("PID"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("?"),
		ft_strdup("EXIT STATUS"), 
		free
	);

	t_char_list *c_lst;

	c_lst = NULL;
	char_list_push_str(&c_lst, str);
	
	t_void_list *token_list;
	token_list = expand_string2list2(rule_str, d);


	t_void_list *vec_vec_extoken;
	vec_vec_extoken = split_token_list_by_slash(token_list);

	list_list_print(vec_vec_extoken, print_token_list_node);
	// あとで解放処理を入れる

	//is_same_string(c_lst, token_list);
	char_list_clear(&c_lst);
	void_list_clear(&token_list, free_ex_token);
	return (0);
}

