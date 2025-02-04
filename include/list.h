#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/// charを格納するリスト
typedef struct s_char_list t_char_list;
struct s_char_list
{
	char data;
	t_char_list *next;
};

// strを格納するリスト
typedef struct s_str_list t_str_list;
struct s_str_list
{
	char *str;
	t_str_list *next;
};

// char_list functions
t_char_list *init_char_list(char c);

int char_list_push(t_char_list **node, char c);

int char_list_push_str(t_char_list **node, char *str);

char char_list_pop(t_char_list **node, int index);

int	char_list_get_elem(t_char_list *node, int index);

int	char_list_len(t_char_list *node);

int char_list_print(t_char_list *node);

int	char_list_insert(t_char_list **node, int index, char c);

int char_list_insert_str(t_char_list **node, int index,char *str);

int char_list_clear(t_char_list **node);

char *char_list_to_str(t_char_list *node);

bool char_list_is_empty(t_char_list *node);

// str_list functions
//

t_str_list *init_str_list(char *str);

int str_list_push(t_str_list **node, char *str);

int str_list_print(t_str_list *node);

int str_list_len(t_str_list *node);

char *str_list_pop(t_str_list **node, int index);

int str_list_clear(t_str_list **node, void (*f)(void *));

char *str_list_to_str(t_str_list *node);
#endif
