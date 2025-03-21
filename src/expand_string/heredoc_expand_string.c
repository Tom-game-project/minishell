/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:19:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:22:48 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "dict.h"
#include "path.h"
#include "expand_string.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUF_SIZE
# define BUF_SIZE 1024
#endif

static bool	is_newline_wrapper(char *s)
{
	return (*s == '\n');
}

/// 環境変数展開後の文字列を返却する
static char	*replace_expaded_env(char *str, t_str_dict *env_dict)
{
	char	*rstr;

	rstr = heredoc_expand_string(str, env_dict);
	free(str);
	return (rstr);
}

t_char_list	*load_fd_as_char_list(int fd)
{
	t_char_list	*lst;
	char		buf[BUF_SIZE];

	lst = NULL;
	while (1)
	{
		ft_memset(buf, '\0', BUF_SIZE);
		if (read(fd, buf, BUF_SIZE) == 0)
			break ;
		char_list_push_str(&lst, buf);
	}
	return (lst);
}

/// `t_char_list`を文字列としてみて環境変数を展開し
/// その結果を`t_str_list`として返す関数
static t_str_list	*char_list2str_list(t_char_list **lst, t_str_dict *env_dict)
{
	char		*str;
	t_str_list	*expanded;
	int			index;
	t_char_list	*b;

	expanded = NULL;
	while (1)
	{
		index = char_list_search_index(*lst, is_newline_wrapper);
		if (index == -1)
			break ;
		b = char_list_cut(lst, index);
		str = char_list_to_str(b);
		char_list_clear(&b);
		str_list_push(&expanded, replace_expaded_env(str, env_dict));
	}
	if (char_list_len(*lst) != 0)
	{
		str = char_list_to_str(*lst);
		str_list_push(&expanded, str);
	}
	return (expanded);
}

/// リストの内容を隠しファイルに書き込み
/// 読み込み専用のfdを返却する関数 
int	str_list2shadowfile_fd(t_str_list *expanded)
{
	int	rw_fd[2];

	create_shadow_file(rw_fd);
	while (expanded != NULL)
	{
		write(rw_fd[1], expanded->ptr.str, ft_strlen(expanded->ptr.str));
		expanded = expanded->next;
	}
	close(rw_fd[1]);
	return (rw_fd[0]);
}

/// heredocの環境変数を展開する
///
/// この関数に渡されたfdはcloseされる。
///
/// 返り値は環境変数を展開したあとの、隠しファイルを指すfd
int	heredoc_expand_string_via_fd(int fd, t_str_dict *env_dict)
{
	t_char_list	*lst;
	int			rfd;
	t_str_list	*expanded;

	lst = load_fd_as_char_list(fd);

	expanded = char_list2str_list(&lst, env_dict);
	char_list_clear(&lst);
	rfd = str_list2shadowfile_fd(expanded);
	str_list_clear(&expanded, free);
	return (rfd);
}

