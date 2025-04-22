#include "list.h"
#include "libft.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>

static bool is_asterisk_char(char *c)
{
	return (*c == '*');
}

/// rule_strの中にアスタリスクが含まれているかどうかを検証する
/// その際、環境変数の展開なども十分に考慮する
///
/// アスタリスクを含めたディレクトリのパスは**作れる**
t_str_list *rule_to_lst(char *rule_str)
{
	t_char_list *c_lst;
	t_char_list *group;
	t_str_list *rlst;
	int index;

	c_lst = NULL;
	rlst = NULL;
	//debug_dprintf(STDERR_FILENO, ">>> %s\n", rule_str);
	char_list_push_str(&c_lst, rule_str);
	index = char_list_search_index(c_lst, is_asterisk_char);
	while (index != -1)
	{
		group = char_list_cut(&c_lst, index - 1);
		if (char_list_len(group) != 0)
			str_list_push(&rlst, char_list_to_str(group));
		char_list_pop(&c_lst, 0);
		str_list_push(&rlst, ft_strdup("*"));
		char_list_clear(&group);
		index = char_list_search_index(c_lst, is_asterisk_char);
	}
	if (char_list_len(c_lst) != 0)
		str_list_push(&rlst, char_list_to_str(c_lst));
	char_list_clear(&c_lst);
	return (rlst);
}

// TODO: tokenリスト用にかきかえる


//static bool is_asterisk_char2(t_anytype a, bool (*f)(void *))
//{
//	(void) f;
//
//	return (a.ex_token->token_type == e_asterisk);
//}
//
//t_anytype
//copy_token_list_node(t_anytype elem)
//{
//	return (alloc_ex_token(elem.ex_token->token_type, ft_strdup(elem.ex_token->str)));
//}
//
//
//// トークンを含んだ、リスト
//// ```
//// [aaaa*aaaa]
//// ```
//t_str_list *rule_to_lst2(t_void_list *rule_list)
//{
//	int index;
//	t_void_list *group;
//	t_void_list *cloned_rule;
//
//	cloned_rule = token_list_clone(rule_list, copy_token_list_node);
//	index = void_list_search_index(rule_list, is_asterisk_char2, NULL);
//	while(index != -1)
//	{
//		group = void_list_cut(&cloned_rule, index - 1);
//		if (void_list_len(group) != 0)
//		{
//			void_list_push()
//		}
//	}
//}
