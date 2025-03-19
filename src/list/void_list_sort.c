#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// merge sort

/// 先頭の要素を取り出し、次の要素を新しい先頭にする
static
t_void_list *pop_head_element(t_void_list **node)
{
	t_void_list *next;
	t_void_list *tmp;

	if (*node == NULL)
	{
		return(NULL);
	}
	tmp = *node;
	next = (*node)->next;
	*node=next;
	tmp->next = NULL;
	return (tmp);
}

/// 与えられたcmp関数によって、２つリストの先頭の要素で、
/// 当てはまったものを、取り除き返す
/// 比較して、popする関数
static
t_void_list *cmppop(
	t_void_list **a,
	t_void_list **b,
	bool (*cmp)(t_anytype, t_anytype)
)
{
	t_void_list *a_head;
	t_void_list *b_head;

	a_head = *a;
	b_head = *b;
	if (a_head == NULL)
		return (pop_head_element(b));
	if (b_head == NULL)
		return (pop_head_element(a));
	// else
	if (cmp(a_head->ptr, b_head->ptr))
		return (pop_head_element(a));
	else
		return (pop_head_element(b));
}

static int
merge_lists(
	t_void_list **node,
       	t_void_list *node1,
       	t_void_list *node2,
       	bool (*cmp)(t_anytype, t_anytype)
)
{
	t_void_list *p;
	t_void_list *tail_node;

	tail_node = NULL;
	while (1)
	{
		 p = cmppop(&node1, &node2, cmp);
		 if (p == NULL)
			 break;
		 if (tail_node == NULL)
		 {
			 tail_node = p;
			 *node = tail_node;
		 }
		 else
		 {
			 tail_node->next = p;
			 tail_node = p;
		 }
	}
	return (0);
}

/// 与えられたリストをcmpに基づいてsortする関数
/// WARN
/// あまりに要素が多いと、スタックオーバーフローを起こすかもしれない
///
int merge_sort(
	t_void_list **node,
       	bool (*cmp)(t_anytype, t_anytype))
{
	t_void_list *node1;
	t_void_list *node2;
	int len;

	len = void_list_len(*node);
	if (len < 2)
		return (0);
	else if (len == 2)
		node1 = void_list_cut(node, 0);
	else
		node1 = void_list_cut(node, len / 2);
	node2 = *node;
	merge_sort(&node1, cmp);
	merge_sort(&node2, cmp); 
	merge_lists(node, node1, node2, cmp);
	return (0);
}
