#ifndef LIST_H
#define LIST_H


/// charを格納するリスト
typedef struct s_char_list t_char_list;
struct s_char_list
{
	char data;
	t_char_list *next;
};

t_char_list *init_char_list(char c);

int char_list_push(t_char_list **node, char c);

int char_list_push_str(t_char_list **node, char *str);

char char_list_pop(t_char_list **node, int index);

int	char_list_get_elem(t_char_list *node, int index);

int	char_list_len(t_char_list *node);

int char_list_print(t_char_list *node);
#endif
