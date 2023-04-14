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

void	ft_stack3(t_stack **a)
{
	if ((*a)->top->data > (*a)->top->next->data)
	{
		if ((*a)->top->data < (*a)->bottom->data)
			ft_swap(a, 'a');
		else
		{
			if ((*a)->top->next->data > (*a)->bottom->data)
			{
				ft_swap(a, 'a');
				ft_reverse_rotate(a, 'a');
			}
			else
				ft_rotate(a, 'a');
		}
	}
	else
	{
		if ((*a)->top->data < (*a)->bottom->data)
		{
			ft_swap(a, 'a');
			ft_rotate(a, 'a');
		}
		else
			ft_reverse_rotate(a, 'a');
	}
}

void	ft_stack5(t_stack **a, t_stack **b)
{
	while ((*a)->size > 3)
	{
		if ((*a)->top->data == ft_smallest(*a) || (*a)->top->data == ft_biggest(*a))
		{
			ft_push(a, b, 'b');
			(*a)->size--;
			(*b)->size++;
		}
		else
			ft_rotate(a, 'a');
	}
	if (!ft_check_order(a, false))
		ft_stack3(a);
}
