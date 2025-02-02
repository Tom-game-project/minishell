#ifndef node_H
# define node_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node t_node;

struct  s_node
{
	char	*str;
	t_node	*next;
};

//allocation
t_node	*node_cerate(char *str);

//free
void	node_clear(t_node	 **node);

//add
void	node_add(t_node  **node, char *str);

//put
void	node_put(t_node  **node, int	index, char *str);

//pop
char	*node_pop(t_node  **node, int	index)

//del
void	node_del(t_node  **node, int	index);

//sarch
int		node_index_sarch(t_node  **node, char *str);

char	*node_string_sarch(t_node  **node, int	index);

#endif

// pop(t_node **, int index)
// // index番目の要素を取り出す
// push(t_node **, char *str)
// //最後尾に追加
// insert(t_node **, int index, char *str)
// //index番目に追加
// clear(t_node **)
// //すべての要素を消す(t_nodeをfree)
// del(t_node **)
// //　すべての要素を消す(もし追加する要素がchar *がすべてmallocしたものであり、
// //かつすべての要素を消す前にfreeをしたい場合)(t_nodeもfree)