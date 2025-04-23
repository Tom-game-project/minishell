#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "list.h"
#include "path.h"
#include "libft.h"
#include "test_tools.h"
#include "exec.h"
#include "strtools.h"

static t_str_list *get_all_path_one_case(
	t_str_list *path,
       	t_void_list *splited_path,
       	t_str_list **curr_lst)
{
	t_str_list *filtered_ptr;
	char *parent_path;
	t_char_list *rlist;
	t_str_list *filtered;

	filtered = filter_paths_by_rule_wrap(curr_lst, splited_path->ptr.list);
	filtered_ptr = filtered;
	parent_path = str_list_join(path, "");
	rlist = NULL;
	while (filtered_ptr != NULL)
	{
		str_list_push(
			&rlist,
			ft_strjoin(
				parent_path,
				filtered_ptr->ptr.str));
		filtered_ptr = filtered_ptr->next;
	}
	free(parent_path);
	str_list_clear(&filtered, free);
	return (rlist);
}

static t_str_list *get_all_path_more_than_one_case(
	t_str_list *path_ptr,
       	t_void_list *splited_path,
       	t_str_list **curr_lst)
{		
	t_str_list *filtered_ptr;
	t_char_list *rlist;
	t_str_list *filtered_head;
	t_str_list *path_tmp;


	filtered_ptr = filter_paths_by_rule_wrap(curr_lst, splited_path->ptr.list);;
	rlist = NULL;
	while (str_list_len(filtered_ptr) != 0)
	{
		filtered_head = str_list_cut(&filtered_ptr, 0);
		str_list_concat(&path_ptr, filtered_head);
		str_list_push(&path_ptr, ft_strdup("/"));
		str_list_concat(&rlist, dir_walker(&path_ptr, splited_path->next));
		path_tmp = str_list_cut(&path_ptr, str_list_len(path_ptr) - 1 - 2);
		str_list_clear(&path_ptr, free);
		path_ptr = path_tmp;
	}
	return (rlist);
}

static t_str_list *get_all_path_helper_set_root_dir(
	t_str_list **path,
       	t_str_list **curr_lst,
       	t_void_list *splited_path)
{
	char *str;
	t_void_list *tmp_node;

	tmp_node = void_list_get_elem(splited_path->ptr.list, 0);

	if (str_list_len(*path) == 0)
		if (ft_streq(tmp_node->ptr.ex_token->str, "..") || 
		ft_streq(tmp_node->ptr.ex_token->str, ".") || ft_streq(tmp_node->ptr.ex_token->str, "/"))
		{
			*curr_lst = get_dir_list(tmp_node->ptr.ex_token->str);
			if (ft_streq(tmp_node->ptr.ex_token->str, "/"))
				str_list_push(path, ft_strdup("/"));
			splited_path = splited_path->next;
		}
		else
			*curr_lst = get_dir_list(".");
	else
	{
		str = str_list_join(*path, "");
		*curr_lst = get_dir_list(str);
		free(str);
	}
	return (splited_path);
}

/// 再帰的にディレクトリを探索して、パターンに一致したファイルまたはディレクトリを返却する
t_str_list *dir_walker(t_str_list **path,
	t_str_list *splited_path // ルールを格納する二次元リスト
)
{
	t_char_list *rlist;
	t_str_list *curr_lst;

	if (str_list_len(splited_path) == 0)
		return (NULL);
	splited_path = get_all_path_helper_set_root_dir(path, &curr_lst, splited_path);
	if (void_list_len(splited_path) == 1) 
		rlist = get_all_path_one_case(*path, splited_path, &curr_lst);
	else
		rlist = get_all_path_more_than_one_case(*path, splited_path, &curr_lst);
	str_list_clear(&curr_lst, free);
	return (rlist);
}
