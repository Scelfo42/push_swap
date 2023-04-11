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
			sa(a);
		else
		{
			if ((*a)->top->next->data > (*a)->bottom->data)
			{
				sa(a);
				rra(a);
			}
			else
				ra(a);
		}
	}
	else
	{
		if ((*a)->top->data < (*a)->bottom->data)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
}
