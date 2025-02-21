#ifndef HEREDOC_H
#define HEREDOC_H


#include "list.h"

int create_shadow_file(int rw_fd[2]);

t_str_list *read_heredocline(char *eof, int fd);
#endif
