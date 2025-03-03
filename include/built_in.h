#ifndef BUILT_IN_H
#define BUILT_IN_H

#include "dict.h"
#include "list.h"

typedef enum e_built_in t_built_in;

enum e_built_in
{
	e_built_in_cd,
	e_built_in_pwd,
	e_built_in_export,
	e_built_in_unset,
	e_built_in_echo,
	e_built_in_env,
	e_built_in_exit,
	e_not_built_in,
};

/// TODO:
/// この関数は最終的に削除する必要がある
int say_hello();

int return_one_func();

// src/built-in/cd.c
int built_in_cd(t_str_list *args);

int built_in_env(t_str_dict *envp_dict);

int built_in_pwd();

int built_in_export(
	t_str_list *args,
	t_str_dict **envp_dict
);

int built_in_exit(t_str_list *args);

int built_in_unset(
	t_str_list *args,
	t_str_dict **envp_dict
);

t_built_in get_built_in_enum(char *cmd);

int built_in_echo(t_str_list *args);

#endif
