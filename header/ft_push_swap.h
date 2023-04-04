/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/03 17:27:32 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../projects/fl_header/ft_first_layer.h"
# include <stdio.h>

typedef struct s_node
{
    int             data;
    struct s_node   *next;
	struct s_node	*prev;
}	t_node;

typedef struct s_container
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_container;

typedef struct s_stack
{
	t_container	*a;
	t_container	*b;
}	t_stack;

bool	ft_check_errors(t_stack *stack, int argc, char **argv);
bool	ft_stacks_exist(t_stack *stack);

#endif
