#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef union u_anytype t_anytype;

union  u_anytype
{
	int i32;
	char c;
	char *str;
};

/// void ptrを格納するリスト
typedef struct s_void_list t_void_list;
struct s_void_list
{
	t_anytype ptr;
	t_void_list *next;
};


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

// intを格納するリスト
typedef struct s_int_list t_int_list;
struct s_int_list
{
	int i;
	t_int_list *next;
};

// char_list functions
t_char_list *init_char_list(char c);

int char_list_push(t_char_list **node, char c);

int char_list_push_str(t_char_list **node, char *str);

char char_list_pop(t_char_list **node, int index);

int	char_list_get_elem(t_char_list *node, int index);

t_str_list *str_list_get_back(t_str_list *node);

int	char_list_len(t_char_list *node);

int char_list_print(t_char_list *node);

int	char_list_insert(t_char_list **node, int index, char c);

int char_list_insert_str(t_char_list **node, int index,char *str);

int char_list_clear(t_char_list **node);

char *char_list_to_str(t_char_list *node);

bool char_list_is_empty(t_char_list *node);

// str_list functions

t_str_list *init_str_list(char *str);

int str_list_push(t_str_list **node, char *str);

int str_list_print(t_str_list *node);

int str_list_len(t_str_list *node);

char *str_list_pop(t_str_list **node, int index);

int str_list_clear(t_str_list **node, void (*f)(void *));

char *str_list_to_str(t_str_list *node);

char **str_list_to_array(t_str_list *node);

char *str_list_join(t_str_list *node, char *sep);

t_str_list *str_list_get_ptr(t_str_list *head, int index);

t_str_list *str_list_split(char *str, char c);

int str_list_map(t_str_list **node, char *(*f)(char *));

char *str_list_search(t_str_list *node, bool (*f)(char *));

int str_list_search_index(t_str_list *node, bool (*f)(char *));

t_str_list *str_list_search_node(t_str_list *node, bool (*f)(char *, char *), char *str);

int str_list_map_arg1(t_str_list **node, char *(*f)(char *,char *), char *str);

char *str_list_get_elem(t_str_list *node, int index);

int str_list_concat(t_str_list **a, t_str_list *b);

t_str_list *str_list_clone(t_str_list *a, char *(*f)(char *));

t_str_list *str_list_cut(t_str_list **node, int index);

bool str_list_in(char *str, t_str_list *lst);

// int_list functions

t_int_list *init_int_list(int i);

t_int_list *int_list_get_back(t_int_list *node);

// void_list functions

t_void_list *void_list_init(t_anytype ptr);

t_void_list *void_list_get_back(t_void_list *node);

int void_list_push(t_void_list **node, t_anytype ptr);

int *void_list_clear(t_void_list **node, void (*f)(t_anytype));

int void_list_len(t_void_list *node);

int void_list_print(t_void_list *node, int (*print)(int, t_anytype));

// TODO for test
// 以下の関数は、成果物に含めない
//

int str_list_dprint(int pid, t_str_list *node);

#endif
