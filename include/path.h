#ifndef PATH_H
#define PATH_H

#include "list.h"
#include <sys/stat.h>

t_str_list *get_dir_list(char *name);

char *get_full_path(char *cmd, char *env_path);

char *gen_nondup_name(char *basename, t_str_list *dir_lisr);

int create_shadow_file(int rw_fd[2]);

int set_stat(struct stat *path_stat, char *path);

#endif
