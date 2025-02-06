#ifndef DICT_H
#define DICT_H


typedef struct s_str_dict t_str_dict;
struct s_str_dict
{
	char *key;
	char *value;
	t_str_dict *next;
};

t_str_dict *init_str_dict();

t_str_dict *str_dict_set(char *key, char *value);

int str_dict_push(t_str_dict **node, char *key, char *value);


t_str_dict *get_str_dict_by_key(\
		t_str_dict *node, char *key);

int str_dict_print(t_str_dict *node);

int str_dict_add(t_str_dict **node, char *key, char *value, void (*f)(void *));

int str_dict_clear(t_str_dict **node, \
		void (*key_free)(void *),\
		void (*value_free)(void *)
		);

int str_dict_len(t_str_dict *node);

char **str_dict_to_envp(t_str_dict *node);


int envp_to_str_dict(t_str_dict **node, char *envp[]);
#endif
