/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:23:51 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 12:23:53 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_stack3(t_stack *a)
{
	t_node	*first;
	t_node	*third;

	first = a->top;
	third = a->bottom;
	if (first->data > first->next->data)
	{
		if (first->data < third->data)
			ft_case1(&a);
		else
		{
			if (first->next->data > third->data)
				ft_case2(&a);
			else
				ft_case3(&a);
		}
	}
	else
	{
		if (first->data < third->data)
			ft_case4(&a);
		else
			ft_case5(&a);
	}
}
