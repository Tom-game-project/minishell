#ifndef PATH_H
#define PATH_H

#include "list.h"

t_str_list *get_dir_list(char *name);

char *get_full_path(char *cmd, char *env_path);

char *gen_nondup_name(char *basename, t_str_list *dir_lisr);

#endif
