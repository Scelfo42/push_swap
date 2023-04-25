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

void	ft_stack3(t_stack **stack)
{
	if ((*stack)->top->data == ft_biggest((*stack)->top))
		ft_rotate(stack, 'a', true);
	else if ((*stack)->top->next->data == ft_biggest((*stack)->top))
		ft_reverse_rotate(stack, 'a', true);
	if ((*stack)->top->data > (*stack)->top->next->data)
		ft_swap (stack, 'a', true);
}

void	ft_stack_any(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	while ((*a)->size > 3)
	{
		pos = ft_find_pos_min((*a)->top, &min);
		while ((*a)->top->data != min)
		{
			if (pos <= ((*a)->size / 2) + 1)
				ft_rotate(a, 'a', true);
			else
				ft_reverse_rotate(a, 'a', true);
		}
		ft_push(a, b, 'b');
	}
	if (!ft_check_order(a, false))
		ft_stack3(a);
	while ((*b)->size != 0)
		ft_push(b, a, 'a');
}
