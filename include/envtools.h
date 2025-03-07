#ifndef ENV_TOOLS_H
#define ENV_TOOLS_H

#include "dict.h"

#include <stdbool.h>

char *get_key_from_envp_ptr(char *str);

char *get_value_from_envp_ptr(char *str);

bool is_valid_env_char(char c);

bool is_valid_identifier(char *str);

/// env_dictに保存される環境変数をアップデートする
int update_exit_status(int exit_status, t_str_dict **env_dict);

#endif
