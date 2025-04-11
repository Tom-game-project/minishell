#ifndef LOOP_H
#define LOOP_H

#include "dict.h"


int exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status);

int main_loop(char *envp[]);

int none_device_main_loop(char *envp[]);

#endif
