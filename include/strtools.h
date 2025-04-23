/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:22:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:23:25 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRTOOLS_H
# define STRTOOLS_H
# include <stdbool.h>

bool	ft_streq(char *a, char *b);

bool	includes_newline(char *str);

char	*remove_quotations(char *str);

#endif
