#ifndef HEREDOC_H
#define HEREDOC_H


#include "list.h"
#include "parser.h"

int create_shadow_file(int rw_fd[2]);

t_str_list *read_heredocline(char *eof, int fd);

int heredoc_proc(t_ast *ast, t_int_list **heredoc_fd_list);

int close_all_heredoc_fd(t_int_list **node);

#endif
