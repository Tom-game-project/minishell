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


int str_dict_print(t_str_dict *node);
#endif


