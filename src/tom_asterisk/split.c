#include "list.h"
#include "libft.h"
#include <stdlib.h>

static bool is_slash(char *c)
{
	return (*c == '/');
}

/// pathを分解する関数
t_str_list *split_path_by_slash(char *path)
{
	t_char_list *char_lst;
	t_str_list *str_lst;
	int index;

	char_lst = NULL;
	str_lst = NULL;
	char_list_push_str(&char_lst, path);
	index = char_list_search_index(char_lst, is_slash);
	while(index != -1)
	{
		t_char_list *group_char_lst;
		group_char_lst = char_list_cut(&char_lst, index);
		str_list_push(&str_lst, char_list_to_str(group_char_lst));
		index = char_list_search_index(char_lst, is_slash);
		char_list_clear(&group_char_lst);
	}
	if (char_list_len(char_lst) != 0)
	{
		str_list_push(&str_lst, char_list_to_str(char_lst));
	}
	char_list_clear(&char_lst);
	return (str_lst);
}

int
push_list_to_list(t_void_list **vec_vec_extoken, t_void_list *vec_extoken)
{
	t_anytype elem;

	elem.list = vec_extoken;
	void_list_push(vec_vec_extoken, elem);
	return (0);
}

/// 
/// token_listを受け取って、スラッシュ区切りにする
///
/// 返り値は二次元リストList<List<ex_token>>
/// ```
///   [(aaaaaa/)]
/// - [(bbbb)-(*)-(bb/)]
/// - [(ccccc/)]
/// - [(fileA)]
/// ```
t_void_list *split_token_list_by_slash(t_void_list *lst)
{
	t_void_list *vec_vec_extoken;
	t_void_list *vec_extoken;

	vec_vec_extoken = NULL;
	vec_extoken = NULL;
	while (lst != NULL)
	{
		if (lst->ptr.ex_token->token_type == e_word)
		{
			t_char_list *c_list;
			int index;

			c_list = NULL;
			char_list_push_str(&c_list, lst->ptr.ex_token->str);
			index = char_list_search_index(c_list, is_slash);
			while (index != -1)
			{
				t_char_list *group_char_lst;

				group_char_lst = char_list_cut(&c_list, index);
				void_list_push(
					&vec_extoken,
				       	alloc_ex_token(e_word, char_list_to_str(group_char_lst)));
				push_list_to_list(&vec_vec_extoken, vec_extoken);
				vec_extoken = NULL;

				char_list_clear(&group_char_lst);
				index = char_list_search_index(c_list, is_slash);
			}
			if (char_list_len(c_list) != 0)
			{
				void_list_push(
					&vec_extoken,
				       	alloc_ex_token(e_word, char_list_to_str(c_list)));
				char_list_clear(&c_list);
			}
		}
		else
		{
			void_list_push(&vec_extoken, alloc_ex_token(e_asterisk, ft_strdup("*")));
		}
		lst = lst->next;
	}
	if (void_list_len(vec_extoken) != 0)
	{
		push_list_to_list(&vec_vec_extoken, vec_extoken);
	}
	return (vec_vec_extoken);
}

static void free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

// リストの中のリストをクリアにする
void
clear_token_list(t_anytype elem)
{
	void_list_clear(&elem.list, free_ex_token);
}

int clear_split_token_list(t_void_list **token_list)
{
	void_list_clear(token_list, clear_token_list);
	return (0);
}

