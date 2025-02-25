#ifndef ENV_TOOLS_H
#define ENV_TOOLS_H

#include <stdbool.h>

char *get_key_from_envp_ptr(char *str);

char *get_value_from_envp_ptr(char *str);

bool is_valid_env_char(char c);

bool is_valid_identifier(char *str);

#endif
