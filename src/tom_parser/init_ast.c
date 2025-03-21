/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:10:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:11:03 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tom_parser.h"
#include <stdlib.h>

/// 
t_ast	*init_ast(void)
{
	t_ast	*ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	ast->arg = NULL;
	ast->left_ast = NULL;
	ast->right_ast = NULL;
	ast->ope = e_ope_none;
	return (ast);
}

