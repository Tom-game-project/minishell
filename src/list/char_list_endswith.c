/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_endswith.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:02 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:27:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

bool	char_list_endswith(t_char_list *lst, char *str)
{
	char	*lst_str;
	size_t	lst_str_len;
	size_t	str_len;
	bool	r;

	lst_str = char_list_to_str(lst);
	lst_str_len = ft_strlen(lst_str);
	str_len = ft_strlen(str);
	if (lst_str_len < str_len)
	{
		free(lst_str);
		return (false);
	}
	r = ft_strncmp(lst_str + lst_str_len - str_len, str, str_len) == 0;
	free(lst_str);
	return (r);
}
