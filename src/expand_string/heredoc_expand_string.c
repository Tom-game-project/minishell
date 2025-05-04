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

#include "dict.h"
#include "expand_string.h"
#include "libft.h"
#include "list.h"
#include "path.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "private.h"

#ifndef BUF_SIZE
# define BUF_SIZE 1024
#endif

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
