#ifndef LIST_H
# define LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list t_list;

struct  s_list
{
	char	*str;
	s_list	*next;
};

//allocation
t_list	*list_cerate(char *str);

//free
void    list_free(t_list	*list);

//add
void	*list_add(t_list *list, char *str);

//put
void	*list_put(t_list *list, int	n, char *str);

//pop
char	*list_pop(t_list *list, int	n)

//del
t_list	*list_del(t_list *list, int	n);

//sarch
int		list_sarch(t_list *list, char *str);

#endif