#include "libft.h"
#include "list.h"
#include "dict.h"
#include "path.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUF_SIZE
# define BUF_SIZE 1024
#endif

static bool is_newline_wrapper(char *s)
{
	return (*s == '\n');
}

/// heredocの環境変数を展開する
///
/// この関数に渡されたfdはcloseされる。
///
/// 返り値は環境変数を展開したあとの、隠しファイルを指すfd
int heredoc_expand_string_via_fd(int fd, t_str_dict *env_dict)
{
	t_char_list *lst;
	char buf[BUF_SIZE];
	int rw_fd[2];

	(void) env_dict;
	/// 渡されたfdを読みこみリスト形式にする
	lst = NULL;
	while (1)
	{
		ft_memset(buf, '\0', BUF_SIZE);
		if (read(fd, buf, BUF_SIZE) == 0)
			break ;
		char_list_push_str(&lst, buf);
	}

	/// 以下で環境変数展開を施す
	char *str;
	t_str_list *expanded;

	expanded = NULL;
	while (1)
	{
		t_char_list *b;
		int index;

		index= char_list_search_index(lst, is_newline_wrapper);
		if (index == -1)
			break ;
		b = char_list_cut(&lst, index);
		str = char_list_to_str(b);
		char_list_clear(&b);
		str_list_push(&expanded, str); // TODO:ここで展開
	}
	if (char_list_len(lst) != 0)
	{
		str = char_list_to_str(lst);
		str_list_push(&expanded, str);
	}
	char_list_clear(&lst);
	/// 新しい隠しファイルに書き込む
	create_shadow_file(rw_fd);
	t_str_list *expanded_tmp;

	expanded_tmp = expanded;
	while (expanded != NULL)
	{
		write(rw_fd[1], expanded->ptr.str, ft_strlen(expanded->ptr.str));
		expanded = expanded->next;
	}
	str_list_clear(&expanded_tmp, free);
	close(rw_fd[1]);
	return (rw_fd[0]);
}

