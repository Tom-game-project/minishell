#ifndef LOOP_H
#define LOOP_H

#include "dict.h"

int exec_shell_cmd(char *str, t_str_dict **env_dict);

int main_loop(char *envp[]);

#endif
