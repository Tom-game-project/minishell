/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:12:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:13:35 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "list.h"
# include "parser.h"

# ifndef BUF_SIZE
#  define BUF_SIZE 1
# endif

# define HEREDOC_PROMPT "> "

typedef enum e_private	t_private;
enum					e_private
{
	e_continue,
	e_break,
	e_return_error
};

int						read_heredocline2(char *eof, int fd);

int						heredoc_proc(t_ast *ast, t_int_list **heredoc_fd_list);

int						close_all_heredoc_fd(t_int_list **node);

int						count_heredoc(t_ast *ast);

int						put_switcher(char *str, int fd);

t_private				read_heredocline_helper2_eot(t_char_list **lst);

t_private				read_heredocline_helper2_baskspace(t_char_list **lst);

t_private				read_heredocline_helper2_newline(char *eof, int fd,
							t_char_list **lst);

#endif
