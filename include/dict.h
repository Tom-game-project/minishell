/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:42:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:47:01 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <unistd.h>

typedef struct s_str_dict	t_str_dict;
struct s_str_dict
{
	char		*key;
	char		*value;
	t_str_dict	*next;
};

t_str_dict	*init_str_dict(void);

t_str_dict	*str_dict_set(char *key, char *value);

int			str_dict_push(t_str_dict **node, char *key, char *value);

t_str_dict	*get_str_dict_by_key(\
		t_str_dict *node, char *key);

int			str_dict_print(t_str_dict *node);

int			str_dict_add(\
	t_str_dict **node, \
	char *key, \
	char *value, \
	void (*f)(void *));

int			str_dict_add2(t_str_dict **node, char *key, char *value);

int			str_dict_clear(t_str_dict **node, \
	void (*key_free)(void *), \
	void (*value_free)(void *));

int			str_dict_len(t_str_dict *node);

char		**str_dict_to_envp(t_str_dict *node);

int			envp_to_str_dict(t_str_dict **node, char *envp[]);

char		*str_dict_node_to_str(t_str_dict *node);
size_t		str_dict_key_value_len(t_str_dict *node);

int			str_dict_remove(\
	t_str_dict **node, \
	char *key, \
	void (*key_free)(void *), \
	void (*value_free)(void *));

#endif
